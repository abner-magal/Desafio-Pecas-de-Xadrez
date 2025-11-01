#!/bin/bash
# benchmark.sh - Script de benchmarks de performance
# Compara tempo de execução dos diferentes níveis e versões otimizadas

set -e

# Cores
CYAN='\033[0;36m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

# Diretórios
BIN_DIR="bin"

# Número de iterações para média
ITERATIONS=10

echo "════════════════════════════════════════════════════════════"
echo "📊 BENCHMARKS DE PERFORMANCE - Projeto Peças de Xadrez"
echo "════════════════════════════════════════════════════════════"
echo ""

# Verificar se hyperfine está disponível
if command -v hyperfine &> /dev/null; then
    USE_HYPERFINE=1
    echo -e "${GREEN}✓${NC} hyperfine detectado - usando para benchmarks precisos"
else
    USE_HYPERFINE=0
    echo -e "${YELLOW}⚠${NC} hyperfine não encontrado - usando 'time' padrão"
    echo "  Instale hyperfine para benchmarks mais precisos:"
    echo "  → cargo install hyperfine"
fi
echo ""

# Função de benchmark com 'time'
benchmark_time() {
    local name=$1
    local exec=$2
    local iterations=$3
    
    echo "───────────────────────────────────────────────────────────"
    echo -e "${CYAN}Testando: $name${NC}"
    echo "Iterações: $iterations"
    echo ""
    
    local total_real=0
    local total_user=0
    local total_sys=0
    
    for ((i=1; i<=iterations; i++)); do
        # Executar e capturar tempo
        local output=$(TIMEFORMAT='%3R %3U %3S'; { time "$exec" > /dev/null 2>&1; } 2>&1)
        
        # Parse do output do time
        read -r real user sys <<< "$output"
        
        total_real=$(echo "$total_real + $real" | bc)
        total_user=$(echo "$total_user + $user" | bc)
        total_sys=$(echo "$total_sys + $sys" | bc)
        
        echo -n "."
    done
    echo ""
    
    # Calcular médias
    local avg_real=$(echo "scale=4; $total_real / $iterations" | bc)
    local avg_user=$(echo "scale=4; $total_user / $iterations" | bc)
    local avg_sys=$(echo "scale=4; $total_sys / $iterations" | bc)
    
    echo ""
    echo "Resultados (média de $iterations execuções):"
    echo "  Real: ${avg_real}s"
    echo "  User: ${avg_user}s"
    echo "  Sys:  ${avg_sys}s"
    echo ""
}

# Função de benchmark com hyperfine
benchmark_hyperfine() {
    local name=$1
    local exec=$2
    local iterations=$3
    
    echo "───────────────────────────────────────────────────────────"
    echo -e "${CYAN}Testando: $name${NC}"
    echo ""
    
    hyperfine \
        --warmup 2 \
        --runs "$iterations" \
        --style basic \
        --export-markdown /dev/null \
        "$exec > /dev/null 2>&1"
    
    echo ""
}

# Selecionar função de benchmark
if [ $USE_HYPERFINE -eq 1 ]; then
    BENCH_FUNC=benchmark_hyperfine
else
    BENCH_FUNC=benchmark_time
fi

# ═══════════════════════════════════════════════════════════════
# BENCHMARKS INDIVIDUAIS
# ═══════════════════════════════════════════════════════════════

$BENCH_FUNC "🟢 Novato" "$BIN_DIR/novato" $ITERATIONS
$BENCH_FUNC "🟡 Aventureiro" "$BIN_DIR/aventureiro" $ITERATIONS
$BENCH_FUNC "🔴 Mestre" "$BIN_DIR/mestre" $ITERATIONS
$BENCH_FUNC "🚀 Otimizado (memória)" "$BIN_DIR/otim_memoria" $ITERATIONS
$BENCH_FUNC "⚡ Otimizado (velocidade)" "$BIN_DIR/otim_velocidade" $ITERATIONS
$BENCH_FUNC "✔️  Com Validações" "$BIN_DIR/otim_validacoes" $ITERATIONS

# ═══════════════════════════════════════════════════════════════
# BENCHMARK COMPARATIVO
# ═══════════════════════════════════════════════════════════════

if [ $USE_HYPERFINE -eq 1 ]; then
    echo "════════════════════════════════════════════════════════════"
    echo "📊 COMPARAÇÃO LADO A LADO"
    echo "════════════════════════════════════════════════════════════"
    echo ""
    
    hyperfine \
        --warmup 2 \
        --runs $ITERATIONS \
        --style full \
        --export-markdown benchmarks_results.md \
        --export-json benchmarks_results.json \
        --command-name "Novato" "$BIN_DIR/novato > /dev/null 2>&1" \
        --command-name "Aventureiro" "$BIN_DIR/aventureiro > /dev/null 2>&1" \
        --command-name "Mestre" "$BIN_DIR/mestre > /dev/null 2>&1" \
        --command-name "Otim-Memória" "$BIN_DIR/otim_memoria > /dev/null 2>&1" \
        --command-name "Otim-Velocidade" "$BIN_DIR/otim_velocidade > /dev/null 2>&1" \
        --command-name "Com-Validações" "$BIN_DIR/otim_validacoes > /dev/null 2>&1"
    
    echo ""
    echo -e "${GREEN}✓${NC} Resultados exportados:"
    echo "  → benchmarks_results.md (Markdown)"
    echo "  → benchmarks_results.json (JSON)"
    echo ""
fi

# ═══════════════════════════════════════════════════════════════
# ANÁLISE DE TAMANHO DOS BINÁRIOS
# ═══════════════════════════════════════════════════════════════

echo "════════════════════════════════════════════════════════════"
echo "📦 TAMANHO DOS BINÁRIOS"
echo "════════════════════════════════════════════════════════════"
echo ""

ls -lh "$BIN_DIR" | tail -n +2 | awk '{printf "%-25s %10s\n", $9, $5}'

echo ""

# ═══════════════════════════════════════════════════════════════
# DICAS DE OTIMIZAÇÃO
# ═══════════════════════════════════════════════════════════════

echo "════════════════════════════════════════════════════════════"
echo "💡 DICAS DE OTIMIZAÇÃO"
echo "════════════════════════════════════════════════════════════"
echo ""
echo "Para otimizações adicionais, considere:"
echo ""
echo "1. Flags de compilação agressivas:"
echo "   → gcc -O3 -march=native -flto"
echo ""
echo "2. Perfil guiado (PGO):"
echo "   → gcc -fprofile-generate → executar → gcc -fprofile-use"
echo ""
echo "3. Análise com gprof:"
echo "   → gcc -pg → executar → gprof binário gmon.out"
echo ""
echo "4. Desativar saída para medir overhead puro:"
echo "   → Redirecionar para /dev/null"
echo ""
echo "5. Usar ferramentas avançadas:"
echo "   → perf stat ./binario"
echo "   → valgrind --tool=callgrind ./binario"
echo ""

# ═══════════════════════════════════════════════════════════════
# OBSERVAÇÕES
# ═══════════════════════════════════════════════════════════════

echo "════════════════════════════════════════════════════════════"
echo "📝 OBSERVAÇÕES"
echo "════════════════════════════════════════════════════════════"
echo ""
echo "• Os programas são dominados por I/O (printf/puts)"
echo "• Diferenças de performance podem ser sutis devido ao tamanho"
echo "• Para N grande, diferenças entre iteração e recursão ficam evidentes"
echo "• Versões otimizadas minimizam chamadas de sistema e bufferizam saída"
echo ""
echo "════════════════════════════════════════════════════════════"
echo -e "${GREEN}✅ BENCHMARKS CONCLUÍDOS!${NC}"
echo "════════════════════════════════════════════════════════════"

#!/bin/bash
# test_all.sh - Script de testes automatizados
# Valida que todos os programas executam com sucesso e produzem saída esperada

# Não usar set -e pois queremos continuar após falhas nos testes
# set -e

# Cores
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Diretórios
BIN_DIR="bin"
TEST_DIR="tests"
EXPECTED_DIR="$TEST_DIR/expected"

# Criar diretórios de teste
mkdir -p "$TEST_DIR"
mkdir -p "$EXPECTED_DIR"

# Contadores
PASS=0
FAIL=0
TOTAL=0

echo "════════════════════════════════════════════════════════════"
echo "🧪 TESTES AUTOMATIZADOS - Projeto Peças de Xadrez"
echo "════════════════════════════════════════════════════════════"
echo ""

# Função de teste básico (código de saída)
test_exit_code() {
    local name=$1
    local exec=$2
    
    ((TOTAL++))
    echo -n "[$TOTAL] Testando $name (código de saída)... "
    
    if "$exec" > /dev/null 2>&1; then
        echo -e "${GREEN}✓ PASSOU${NC}"
        ((PASS++))
        return 0
    else
        echo -e "${RED}✗ FALHOU${NC} (código não-zero: $?)"
        ((FAIL++))
        return 1
    fi
}

# Função de teste de saída (número de linhas esperado)
test_line_count() {
    local name=$1
    local exec=$2
    local expected=$3
    
    ((TOTAL++))
    echo -n "[$TOTAL] Testando $name (linhas de saída)... "
    
    local output_lines=$("$exec" 2>/dev/null | wc -l)
    
    if [ "$output_lines" -ge "$expected" ]; then
        echo -e "${GREEN}✓ PASSOU${NC} ($output_lines linhas)"
        ((PASS++))
        return 0
    else
        echo -e "${RED}✗ FALHOU${NC} (esperado: >=$expected, obtido: $output_lines)"
        ((FAIL++))
        return 1
    fi
}

# Função de teste de conteúdo (procura por palavras-chave)
test_content() {
    local name=$1
    local exec=$2
    local keyword=$3
    
    ((TOTAL++))
    echo -n "[$TOTAL] Testando $name (conteúdo: '$keyword')... "
    
    if "$exec" 2>/dev/null | grep -q "$keyword"; then
        echo -e "${GREEN}✓ PASSOU${NC}"
        ((PASS++))
        return 0
    else
        echo -e "${RED}✗ FALHOU${NC} (palavra-chave não encontrada)"
        ((FAIL++))
        return 1
    fi
}

# Função para gerar output esperado
generate_expected() {
    local name=$1
    local exec=$2
    local outfile="$EXPECTED_DIR/${name}.txt"
    
    echo "  Gerando output esperado: $outfile"
    "$exec" > "$outfile" 2>&1
}

# Função de teste com diff
test_diff() {
    local name=$1
    local exec=$2
    local expected="$EXPECTED_DIR/${name}.txt"
    
    ((TOTAL++))
    echo -n "[$TOTAL] Testando $name (diff com esperado)... "
    
    if [ ! -f "$expected" ]; then
        echo -e "${YELLOW}⚠ PULADO${NC} (arquivo esperado não existe)"
        return 0
    fi
    
    local temp_output=$(mktemp)
    "$exec" > "$temp_output" 2>&1
    
    if diff -q "$expected" "$temp_output" > /dev/null 2>&1; then
        echo -e "${GREEN}✓ PASSOU${NC}"
        ((PASS++))
        rm "$temp_output"
        return 0
    else
        echo -e "${RED}✗ FALHOU${NC} (output diferente)"
        echo "  Diferenças:"
        diff "$expected" "$temp_output" | head -n 10
        ((FAIL++))
        rm "$temp_output"
        return 1
    fi
}

# ═══════════════════════════════════════════════════════════════
# TESTES - Níveis Básicos
# ═══════════════════════════════════════════════════════════════

echo "───────────────────────────────────────────────────────────"
echo "🟢 Testando NOVATO"
echo "───────────────────────────────────────────────────────────"
test_exit_code "Novato" "$BIN_DIR/novato"
test_line_count "Novato" "$BIN_DIR/novato" 20
test_content "Novato" "$BIN_DIR/novato" "TORRE"
test_content "Novato" "$BIN_DIR/novato" "Direita"
echo ""

echo "───────────────────────────────────────────────────────────"
echo "🟡 Testando AVENTUREIRO"
echo "───────────────────────────────────────────────────────────"
test_exit_code "Aventureiro" "$BIN_DIR/aventureiro"
test_line_count "Aventureiro" "$BIN_DIR/aventureiro" 25
test_content "Aventureiro" "$BIN_DIR/aventureiro" "CAVALO"
test_content "Aventureiro" "$BIN_DIR/aventureiro" "Baixo"
echo ""

echo "───────────────────────────────────────────────────────────"
echo "🔴 Testando MESTRE"
echo "───────────────────────────────────────────────────────────"
test_exit_code "Mestre" "$BIN_DIR/mestre"
test_line_count "Mestre" "$BIN_DIR/mestre" 35
test_content "Mestre" "$BIN_DIR/mestre" "Recursividade"
test_content "Mestre" "$BIN_DIR/mestre" "Loops Aninhados"
echo ""

# ═══════════════════════════════════════════════════════════════
# TESTES - Versões Otimizadas
# ═══════════════════════════════════════════════════════════════

echo "───────────────────────────────────────────────────────────"
echo "🚀 Testando OTIMIZADO (memória)"
echo "───────────────────────────────────────────────────────────"
test_exit_code "Otimizado Memória" "$BIN_DIR/otim_memoria"
test_line_count "Otimizado Memória" "$BIN_DIR/otim_memoria" 20
test_content "Otimizado Memória" "$BIN_DIR/otim_memoria" "TORRE"
echo ""

echo "───────────────────────────────────────────────────────────"
echo "⚡ Testando OTIMIZADO (velocidade)"
echo "───────────────────────────────────────────────────────────"
test_exit_code "Otimizado Velocidade" "$BIN_DIR/otim_velocidade"
test_line_count "Otimizado Velocidade" "$BIN_DIR/otim_velocidade" 20
test_content "Otimizado Velocidade" "$BIN_DIR/otim_velocidade" "BISPO"
echo ""

echo "───────────────────────────────────────────────────────────"
echo "✔️  Testando COM VALIDAÇÕES"
echo "───────────────────────────────────────────────────────────"
test_exit_code "Com Validações (padrão)" "$BIN_DIR/otim_validacoes"
test_line_count "Com Validações" "$BIN_DIR/otim_validacoes" 20

# Teste com parâmetros
((TOTAL++))
echo -n "[$TOTAL] Testando Com Validações (parâmetros customizados)... "
if "$BIN_DIR/otim_validacoes" 3 3 3 1 1 > /dev/null 2>&1; then
    echo -e "${GREEN}✓ PASSOU${NC}"
    ((PASS++))
else
    echo -e "${RED}✗ FALHOU${NC}"
    ((FAIL++))
fi

# Teste com ajuda
((TOTAL++))
echo -n "[$TOTAL] Testando Com Validações (--help)... "
if "$BIN_DIR/otim_validacoes" --help > /dev/null 2>&1; then
    echo -e "${GREEN}✓ PASSOU${NC}"
    ((PASS++))
else
    echo -e "${RED}✗ FALHOU${NC}"
    ((FAIL++))
fi

# Teste com parâmetros inválidos (deve falhar)
((TOTAL++))
echo -n "[$TOTAL] Testando Com Validações (parâmetros inválidos - deve falhar)... "
if "$BIN_DIR/otim_validacoes" 999999999 0 0 0 0 > /dev/null 2>&1; then
    echo -e "${RED}✗ FALHOU${NC} (deveria ter retornado erro)"
    ((FAIL++))
else
    echo -e "${GREEN}✓ PASSOU${NC} (rejeitou parâmetros inválidos corretamente)"
    ((PASS++))
fi
echo ""

# ═══════════════════════════════════════════════════════════════
# RELATÓRIO FINAL
# ═══════════════════════════════════════════════════════════════

echo "════════════════════════════════════════════════════════════"
echo "📊 RELATÓRIO FINAL"
echo "════════════════════════════════════════════════════════════"
echo -e "Total de testes: $TOTAL"
echo -e "${GREEN}Passou: $PASS${NC}"
echo -e "${RED}Falhou: $FAIL${NC}"
echo ""

if [ $FAIL -eq 0 ]; then
    echo -e "${GREEN}✅ TODOS OS TESTES PASSARAM!${NC}"
    echo "════════════════════════════════════════════════════════════"
    exit 0
else
    echo -e "${RED}❌ ALGUNS TESTES FALHARAM${NC}"
    echo "════════════════════════════════════════════════════════════"
    exit 1
fi

# 🎮 Exemplos de Execução

## Visão Geral

Este documento fornece exemplos detalhados de execução de todos os programas do projeto "Desafio de Movimentação de Peças de Xadrez", incluindo outputs esperados, casos de teste e validações.

---

## 📋 Índice

1. [Nível Novato - Estruturas Básicas](#nivel-novato)
2. [Nível Aventureiro - Loops Aninhados](#nivel-aventureiro)
3. [Nível Mestre - Recursividade Avançada](#nivel-mestre)
4. [Testes Automatizados](#testes-automatizados)
5. [Validação de Outputs](#validacao-de-outputs)
6. [Análise de Performance](#analise-de-performance)

---

## 🟢 Nível Novato - Estruturas Básicas {#nivel-novato}

### Comando de Execução

```bash
./novato_estruturas_basicas
```

### Output Completo Esperado

```
=== SIMULADOR DE MOVIMENTO DE PEÇAS DE XADREZ ===
Aplicação prática de estruturas de repetição em C

TORRE:
Direita
Direita
Direita
Direita
Direita

BISPO:
Cima Direita
Cima Direita
Cima Direita
Cima Direita
Cima Direita

RAINHA:
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda

=== SIMULAÇÃO CONCLUÍDA COM SUCESSO! ===
```

### Análise do Output

| Peça | Estrutura Usada | Movimentos | Total de Linhas |
|------|----------------|------------|-----------------|
| Torre | `for` | 5x "Direita" | 5 |
| Bispo | `while` | 5x "Cima Direita" | 5 |
| Rainha | `do-while` | 8x "Esquerda" | 8 |
| **Total** | 3 estruturas | **18 movimentos** | **18 linhas** |

### Tempo de Execução

```bash
time ./novato_estruturas_basicas
```

**Saída esperada:**
```
[output do programa]

real    0m0.003s
user    0m0.001s
sys     0m0.002s
```

### Redirecionamento para Arquivo

```bash
# Salvar output em arquivo
./novato_estruturas_basicas > output_novato.txt

# Ver conteúdo
cat output_novato.txt
```

### Execução Silenciosa (apenas código de retorno)

```bash
./novato_estruturas_basicas > /dev/null
echo $?
# Output esperado: 0 (sucesso)
```

---

## 🟡 Nível Aventureiro - Loops Aninhados {#nivel-aventureiro}

### Comando de Execução

```bash
./aventureiro_loops_aninhados
```

### Output Completo Esperado

```
=== SIMULADOR DE MOVIMENTO DE PEÇAS DE XADREZ - NÍVEL AVENTUREIRO ===
Estruturas básicas + Loops aninhados para movimento do Cavalo

TORRE:
Direita
Direita
Direita
Direita
Direita

BISPO:
Cima Direita
Cima Direita
Cima Direita
Cima Direita
Cima Direita

RAINHA:
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda

CAVALO:
Baixo
Baixo
Esquerda

=== SIMULAÇÃO NÍVEL AVENTUREIRO CONCLUÍDA! ===
✅ Estruturas básicas: Torre, Bispo, Rainha
✅ Loops aninhados: Movimento em 'L' do Cavalo
🚀 Próximo nível: Recursividade e estruturas avançadas
```

### Análise do Output

| Peça | Estrutura Usada | Movimentos | Total de Linhas |
|------|----------------|------------|-----------------|
| Torre | `for` | 5x "Direita" | 5 |
| Bispo | `while` | 5x "Cima Direita" | 5 |
| Rainha | `do-while` | 8x "Esquerda" | 8 |
| **Cavalo** | **Loops aninhados** | **2x "Baixo" + 1x "Esquerda"** | **3** |
| **Total** | 4 estruturas | **21 movimentos** | **21 linhas** |

### Movimento em "L" do Cavalo

```
Representação Visual:

Posição Inicial
     ↓
     C
     ↓ (Baixo)
     ●
     ↓ (Baixo)
     ● ← (Esquerda)
     ●
Posição Final
```

### Comparação com Nível Novato

```bash
# Executar ambos e comparar
./novato_estruturas_basicas > novato_out.txt
./aventureiro_loops_aninhados > aventureiro_out.txt

# Ver diferenças
diff novato_out.txt aventureiro_out.txt
```

**Diferenças esperadas:**
- Adição da seção "CAVALO"
- 3 linhas extras de movimento
- Mensagem de conclusão diferente

---

## 🔴 Nível Mestre - Recursividade Avançada {#nivel-mestre}

### Comando de Execução

```bash
./mestre_recursividade_avancada
```

### Output Completo Esperado

```
================================================================================
      🏆 SIMULADOR DE MOVIMENTO DE PEÇAS DE XADREZ - NÍVEL MESTRE 🏆
================================================================================
Técnicas avançadas implementadas:
• RECURSIVIDADE: Torre, Bispo e Rainha (substituindo loops)
• LOOPS COMPLEXOS: Cavalo com múltiplas variáveis e controle de fluxo
• LOOPS ANINHADOS: Bispo com decomposição vertical + horizontal
• CONTROLE DE FLUXO: Continue, break e múltiplas condições
================================================================================

TORRE (Recursividade):
Direita
Direita
Direita
Direita
Direita
BISPO (Recursividade):
Cima Direita
Cima Direita
Cima Direita
Cima Direita
Cima Direita
BISPO (Loops Aninhados - Vertical + Horizontal):
Cima
Direita
Cima
Direita
Cima
Direita
Cima
Direita
Cima
Direita
RAINHA (Recursividade):
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
CAVALO (Loops Complexos - Movimento em L: Cima + Direita):
Cima
Cima
Direita

================================================================================
           🏆 SIMULAÇÃO NÍVEL MESTRE CONCLUÍDA COM SUCESSO! 🏆
================================================================================
✅ Torre:  Recursividade implementada (substituindo loop FOR)
✅ Bispo:  Dupla implementação (Recursividade + Loops Aninhados)
✅ Rainha: Recursividade implementada (substituindo loop DO-WHILE)
✅ Cavalo: Loops complexos com múltiplas variáveis e controle de fluxo

🎓 Domínio completo de técnicas avançadas de programação em C!
📚 Conceitos aplicados: Recursividade, Loops Complexos, Controle de Fluxo
================================================================================
```

### Análise do Output

| Seção | Tipo | Movimentos | Linhas de Output |
|-------|------|------------|------------------|
| Torre | Recursiva | 5x "Direita" | 5 |
| Bispo (v1) | Recursiva | 5x "Cima Direita" | 5 |
| Bispo (v2) | Loops Aninhados | 5x ("Cima" + "Direita") | 10 |
| Rainha | Recursiva | 8x "Esquerda" | 8 |
| Cavalo | Loops Complexos | 2x "Cima" + 1x "Direita" | 3 |
| **Total** | 5 implementações | **36 movimentos** | **31 linhas** |

### Observações Importantes

#### 1. Bispo tem Dupla Implementação

**Versão 1 (Recursiva):**
```
Cima Direita
Cima Direita
Cima Direita
Cima Direita
Cima Direita
```

**Versão 2 (Loops Aninhados - Decomposição):**
```
Cima
Direita
Cima
Direita
Cima
Direita
Cima
Direita
Cima
Direita
```

**Diferença:** A versão 2 decompõe o movimento diagonal em componentes ortogonais (vertical + horizontal).

#### 2. Cavalo Mudou de Direção

- **Nível Aventureiro:** 2 Baixo + 1 Esquerda
- **Nível Mestre:** 2 Cima + 1 Direita

### Análise de Profundidade da Recursão

```bash
# Executar com limite de stack reduzido para testar
ulimit -s 1024  # 1 MB de stack
./mestre_recursividade_avancada
```

**Resultado esperado:** Execução normal (profundidade máxima = 8 chamadas)

---

## 🧪 Testes Automatizados {#testes-automatizados}

### Script de Teste Completo

**Criar arquivo `test_all.sh`:**

```bash
#!/bin/bash
# test_all.sh - Testes automatizados

echo "🧪 Iniciando Testes..."

# Cores
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# Contadores
PASS=0
FAIL=0

# Função de teste
test_program() {
    local name=$1
    local exec=$2
    
    echo -n "Testando $name... "
    
    if ./$exec > /dev/null 2>&1; then
        if [ $? -eq 0 ]; then
            echo -e "${GREEN}✓ PASSOU${NC}"
            ((PASS++))
        else
            echo -e "${RED}✗ FALHOU${NC} (código de saída não-zero)"
            ((FAIL++))
        fi
    else
        echo -e "${RED}✗ FALHOU${NC} (erro de execução)"
        ((FAIL++))
    fi
}

# Executar testes
test_program "Novato" "novato_estruturas_basicas"
test_program "Aventureiro" "aventureiro_loops_aninhados"
test_program "Mestre" "mestre_recursividade_avancada"

# Relatório
echo ""
echo "======================================"
echo "Resultados: ${GREEN}$PASS passou${NC}, ${RED}$FAIL falhou${NC}"
echo "======================================"

exit $FAIL
```

**Executar:**
```bash
chmod +x test_all.sh
./test_all.sh
```

**Saída esperada:**
```
🧪 Iniciando Testes...
Testando Novato... ✓ PASSOU
Testando Aventureiro... ✓ PASSOU
Testando Mestre... ✓ PASSOU

======================================
Resultados: 3 passou, 0 falhou
======================================
```

---

## ✅ Validação de Outputs {#validacao-de-outputs}

### Criar Arquivos de Referência

```bash
# Gerar outputs esperados
./novato_estruturas_basicas > tests/expected_novato.txt
./aventureiro_loops_aninhados > tests/expected_aventureiro.txt
./mestre_recursividade_avancada > tests/expected_mestre.txt
```

### Validar com `diff`

```bash
# Testar Novato
./novato_estruturas_basicas | diff - tests/expected_novato.txt
echo "Status: $?"
# Output esperado: 0 (idêntico)

# Testar Aventureiro
./aventureiro_loops_aninhados | diff - tests/expected_aventureiro.txt
echo "Status: $?"

# Testar Mestre
./mestre_recursividade_avancada | diff - tests/expected_mestre.txt
echo "Status: $?"
```

### Validar com Checksums

```bash
# Gerar checksums
./novato_estruturas_basicas | sha256sum > novato.sha256
./aventureiro_loops_aninhados | sha256sum > aventureiro.sha256
./mestre_recursividade_avancada | sha256sum > mestre.sha256

# Verificar posteriormente
./novato_estruturas_basicas | sha256sum -c novato.sha256
```

### Script de Validação Completo

```bash
#!/bin/bash
# validate_outputs.sh

validate() {
    local name=$1
    local exec=$2
    local expected=$3
    
    echo -n "Validando $name... "
    
    if ./$exec | diff -q - $expected > /dev/null 2>&1; then
        echo "✅ Output correto"
        return 0
    else
        echo "❌ Output diferente!"
        echo "Diferenças encontradas:"
        ./$exec | diff - $expected
        return 1
    fi
}

validate "Novato" "novato_estruturas_basicas" "tests/expected_novato.txt"
validate "Aventureiro" "aventureiro_loops_aninhados" "tests/expected_aventureiro.txt"
validate "Mestre" "mestre_recursividade_avancada" "tests/expected_mestre.txt"
```

---

## 📊 Análise de Performance {#analise-de-performance}

### Medir Tempo de Execução

```bash
# Usando 'time'
time ./novato_estruturas_basicas

# Usando 'hyperfine' (mais preciso)
hyperfine './novato_estruturas_basicas'

# Múltiplas execuções
for i in {1..100}; do
    time ./novato_estruturas_basicas > /dev/null 2>&1
done
```

### Comparação de Performance entre Níveis

```bash
echo "Comparando performance..."
echo "Novato:"
time ./novato_estruturas_basicas > /dev/null

echo "Aventureiro:"
time ./aventureiro_loops_aninhados > /dev/null

echo "Mestre:"
time ./mestre_recursividade_avancada > /dev/null
```

**Resultado típico:**
```
Novato:
real    0m0.002s
user    0m0.001s
sys     0m0.001s

Aventureiro:
real    0m0.003s
user    0m0.001s
sys     0m0.002s

Mestre:
real    0m0.004s
user    0m0.002s
sys     0m0.002s
```

### Análise de Memória com Valgrind

```bash
# Novato
valgrind --leak-check=full --show-leak-kinds=all \
    ./novato_estruturas_basicas

# Aventureiro
valgrind --leak-check=full --show-leak-kinds=all \
    ./aventureiro_loops_aninhados

# Mestre
valgrind --leak-check=full --show-leak-kinds=all \
    ./mestre_recursividade_avancada
```

**Output esperado (todos):**
```
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12345==
==12345== All heap blocks were freed -- no leaks are possible
```

### Profiling com gprof

```bash
# Compilar com profiling
gcc -pg -O2 mestre_recursividade_avancada.c -o mestre_prof

# Executar
./mestre_prof

# Gerar relatório
gprof mestre_prof gmon.out > profile_report.txt

# Ver funções mais custosas
cat profile_report.txt | head -30
```

---

## 🔄 Execução em Pipeline

### Executar Todos em Sequência

```bash
# Pipeline simples
./novato_estruturas_basicas && \
./aventureiro_loops_aninhados && \
./mestre_recursividade_avancada && \
echo "✅ Todos executados com sucesso!"
```

### Executar com Separação Visual

```bash
#!/bin/bash
# run_all.sh

echo "═══════════════════════════════════════"
echo "🟢 NÍVEL NOVATO"
echo "═══════════════════════════════════════"
./novato_estruturas_basicas
echo ""

echo "═══════════════════════════════════════"
echo "🟡 NÍVEL AVENTUREIRO"
echo "═══════════════════════════════════════"
./aventureiro_loops_aninhados
echo ""

echo "═══════════════════════════════════════"
echo "🔴 NÍVEL MESTRE"
echo "═══════════════════════════════════════"
./mestre_recursividade_avancada
echo ""

echo "✅ Execução completa finalizada!"
```

---

## 📸 Captura de Outputs para Documentação

### Capturar com Timestamps

```bash
# Criar arquivo de log com timestamp
{
    echo "Execução em: $(date)"
    echo "═══════════════════════════════════════"
    ./novato_estruturas_basicas
} > logs/novato_$(date +%Y%m%d_%H%M%S).log
```

### Capturar em Formato Markdown

```bash
# Gerar documentação automática
{
    echo "# Execução do Nível Novato"
    echo ""
    echo "\`\`\`"
    ./novato_estruturas_basicas
    echo "\`\`\`"
} > docs/output_novato.md
```

---

## 🎯 Casos de Teste Específicos

### Teste 1: Verificar Número de Linhas

```bash
# Novato deve ter 18 linhas de movimento
lines=$(./novato_estruturas_basicas | grep -E "^(Direita|Cima|Baixo|Esquerda)" | wc -l)
if [ $lines -eq 18 ]; then
    echo "✅ Número correto de movimentos"
else
    echo "❌ Esperado: 18, Obtido: $lines"
fi
```

### Teste 2: Verificar Mensagens de Cabeçalho

```bash
# Verificar se cabeçalho está presente
if ./novato_estruturas_basicas | grep -q "SIMULADOR"; then
    echo "✅ Cabeçalho presente"
else
    echo "❌ Cabeçalho ausente"
fi
```

### Teste 3: Verificar Ordem dos Movimentos

```bash
# Cavalo deve imprimir: Baixo, Baixo, Esquerda (nessa ordem)
if ./aventureiro_loops_aninhados | grep -A3 "CAVALO:" | \
   grep -q "Baixo.*Baixo.*Esquerda"; then
    echo "✅ Ordem correta do Cavalo"
else
    echo "❌ Ordem incorreta"
fi
```

---

## 📝 Checklist de Execução

Antes de considerar os testes completos:

- [ ] Todos os programas compilam sem warnings
- [ ] Todos os programas executam sem erros
- [ ] Outputs correspondem aos esperados
- [ ] Códigos de saída são 0 (sucesso)
- [ ] Nenhum vazamento de memória (valgrind)
- [ ] Performance está dentro do esperado
- [ ] Testes automatizados passam
- [ ] Documentação reflete outputs reais

---

## 🔗 Arquivos Relacionados

- [`guia_compilacao.md`](guia_compilacao.md) - Como compilar os programas
- [`referencias_teoricas.md`](referencias_teoricas.md) - Fundamentação teórica
- Código fonte em: `Movimentacao de Pecas: Estruturas de Repeticao/Implementacao dos Niveis/`

---

**Última atualização:** 31 de outubro de 2025  
**Versão do documento:** 1.0  
**Autor:** Projeto Desafio Peças de Xadrez

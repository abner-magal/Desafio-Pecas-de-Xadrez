# ♟️ Desafio: Movimentação de Peças de Xadrez

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://www.iso.org/standard/74528.html)
[![GCC](https://img.shields.io/badge/GCC-11+-blue?style=for-the-badge)](https://gcc.gnu.org/)
[![Make](https://img.shields.io/badge/Make-Build_System-green?style=for-the-badge)](https://www.gnu.org/software/make/)
[![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)]()

```
    ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜
    ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟
    · · · · · · · ·
    · · · · · · · ·
    · · · · · · · ·
    · · · · · · · ·
    ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙
    ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖
```

---

## 📋 Visão Geral

Projeto educacional que ensina **estruturas de repetição em C** através da simulação de movimentos de peças de xadrez. Desenvolvido com foco pedagógico, o projeto implementa três níveis progressivos de dificuldade, desde loops básicos até recursividade avançada e controle de fluxo complexo.

### 🎯 Objetivo

Aplicar e dominar conceitos fundamentais de programação em C através de um contexto prático e visual:
- Estruturas de repetição (`for`, `while`, `do-while`)
- Loops aninhados e decomposição de problemas
- Recursividade e pilha de chamadas
- Controle de fluxo avançado (`continue`, `break`)
- Otimização de performance e I/O

### 💡 Conceitos Ensinados

#### Fundamentos de Programação
- ✅ **Estruturas de Repetição**: FOR, WHILE, DO-WHILE
- ✅ **Loops Aninhados**: Nested loops e complexidade O(n²)
- ✅ **Recursividade**: Caso base, caso recursivo, pilha de chamadas
- ✅ **Controle de Fluxo**: Continue, break, múltiplas condições

#### Pensamento Computacional
- ✅ **Decomposição**: Quebra de problemas complexos (movimento em "L" do Cavalo)
- ✅ **Reconhecimento de Padrões**: Movimentos lineares vs. diagonais
- ✅ **Abstração**: Representação de movimentos como strings
- ✅ **Algoritmos**: Sequências lógicas para cada tipo de movimento

#### Engenharia de Software
- ✅ **Modularização**: Funções específicas por peça e técnica
- ✅ **Documentação**: Comentários explicativos e inline documentation
- ✅ **Boas Práticas**: Clean code, naming conventions, indentação
- ✅ **Testes**: Scripts automatizados e validação de saídas

#### Análise de Complexidade
- ✅ **Notação Big-O**: Análise temporal e espacial
- ✅ **Recursão vs. Iteração**: Trade-offs de performance
- ✅ **Otimização**: Técnicas de I/O, bufferização, flags de compilação

---

## 📑 Índice

1. [Visão Geral](#-visão-geral)
2. [Quick Start](#-quick-start)
3. [Estrutura do Projeto](#-estrutura-do-projeto)
4. [Níveis do Desafio](#-níveis-do-desafio)
5. [Compilação](#-compilação)
6. [Execução e Testes](#-execução-e-testes)
7. [Versões Otimizadas](#-versões-otimizadas)
8. [xadrez_completo.c](#-xadrez_completoc)
9. [Documentação Técnica](#-documentação-técnica)
10. [Troubleshooting](#-troubleshooting)
11. [Contribuição](#-contribuição)
12. [Licença e Créditos](#-licença-e-créditos)

---

## 🚀 Quick Start

### Pré-requisitos

- **GCC** 7.0+ (recomendado: GCC 11+)
- **Make** (GNU Make 4.0+)
- **Git** (para clonar o repositório)
- Sistema operacional: Linux, macOS ou Windows (WSL/MinGW)

#### Verificar Instalação

```bash
# Verificar GCC
gcc --version

# Verificar Make
make --version

# Verificar Git
git --version
```

### Instalação Rápida

```bash
# 1. Clonar o repositório
git clone https://github.com/abner-magal/Desafio-Pe-as-de-Xadrez.git
cd Desafio-Pe-as-de-Xadrez

# 2. Compilar todos os programas
make

# 3. Executar todos os níveis
make run
```

### Execução Rápida

```bash
# Executar nível específico
./bin/novato          # Nível Novato
./bin/aventureiro     # Nível Aventureiro
./bin/mestre          # Nível Mestre

# Executar versão completa unificada
./xadrez_completo

# Executar testes automatizados
make test

# Executar benchmarks
make benchmark
```

### Exemplo de Output Esperado (Nível Novato)

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

---

## 📁 Estrutura do Projeto

```
Desafio-Pe-as-de-Xadrez/
│
├── 📄 README.md                          # Este arquivo
├── 📄 xadrez_completo.c                  # Implementação unificada (todos os níveis)
├── 📄 Makefile                           # Sistema de build automatizado
├── 📄 resultado_execucao.txt             # Output de referência
│
├── 📁 Movimentacao de Pecas: Estruturas de Repeticao/
│   ├── 📁 Documentacao do Desafio/
│   │   ├── nivel_novato.md               # Especificação: FOR, WHILE, DO-WHILE
│   │   ├── nivel_aventureiro.md          # Especificação: Loops aninhados
│   │   └── nivel_mestre.md               # Especificação: Recursividade avançada
│   │
│   └── 📁 Implementacao dos Niveis/
│       ├── novato_estruturas_basicas.c       # Nível 1: Estruturas básicas
│       ├── aventureiro_loops_aninhados.c     # Nível 2: Loops aninhados
│       └── mestre_recursividade_avancada.c   # Nível 3: Recursividade
│
├── 📁 Movimentacao de Pecas: Algoritmos e Otimizacao/
│   ├── 📁 Documentacao Tecnica/
│   │   ├── analise_complexidade.md          # Big-O, recursão, invariantes
│   │   ├── otimizacoes_performance.md       # TCO, unrolling, I/O optimization
│   │   └── padroes_movimento.md             # Vetores, direções, modelagem
│   │
│   └── 📁 Versoes Otimizadas/
│       ├── xadrez_otimizado_velocidade.c    # Foco: I/O bufferizado
│       ├── xadrez_otimizado_memoria.c       # Foco: Buffer único
│       └── xadrez_com_validacoes.c          # Foco: CLI parameters
│
├── 📁 docs/
│   ├── exemplos_execucao.md              # Outputs esperados e validações
│   ├── guia_compilacao.md                # Flags GCC, troubleshooting
│   └── referencias_teoricas.md           # Teoria completa (1063 linhas)
│
├── 📁 scripts/
│   ├── test_all.sh                       # Testes automatizados
│   └── benchmark.sh                      # Benchmarks de performance
│
└── 📁 bin/                               # Executáveis (gerado por make)
    ├── novato
    ├── aventureiro
    ├── mestre
    ├── otim_memoria
    ├── otim_velocidade
    └── otim_validacoes
```

### Descrição dos Diretórios

#### 📁 `Movimentacao de Pecas: Estruturas de Repeticao/`
Contém as implementações progressivas dos três níveis do desafio, cada uma focando em diferentes estruturas de controle:
- **Novato**: FOR, WHILE, DO-WHILE básicos
- **Aventureiro**: Loops aninhados (nested loops)
- **Mestre**: Recursividade e controle de fluxo avançado

#### 📁 `Movimentacao de Pecas: Algoritmos e Otimizacao/`
Versões otimizadas e documentação técnica sobre complexidade, performance e padrões de movimento computacionais.

#### 📁 `docs/`
Documentação técnica completa com exemplos de execução, guias de compilação e referências teóricas aprofundadas.

#### 📁 `scripts/`
Scripts Bash para automação de testes e benchmarks de performance.

#### 📁 `bin/`
Diretório de saída para executáveis compilados (criado automaticamente pelo Makefile).

---

## 🎮 Níveis do Desafio

### 🟢 Nível Novato - Estruturas Básicas

**Objetivo**: Dominar as três estruturas de repetição fundamentais em C.

**Peças Implementadas**:
- **Torre** 🏰: 5 movimentos para DIREITA usando `for`
- **Bispo** ⛪: 5 movimentos DIAGONAL (cima-direita) usando `while`
- **Rainha** 👑: 8 movimentos para ESQUERDA usando `do-while`

**Conceitos**:
- Loop `for`: ideal para número conhecido de iterações
- Loop `while`: teste de condição antes da execução
- Loop `do-while`: garante pelo menos uma execução

**Complexidade**:
- **Temporal**: O(n) por peça → O(5+5+8) = O(18) = O(1) (constante)
- **Espacial**: O(1) - apenas variáveis escalares

**Arquivo**: `novato_estruturas_basicas.c`

**Executar**:
```bash
make
./bin/novato
```

---

### 🟡 Nível Aventureiro - Loops Aninhados

**Objetivo**: Implementar loops aninhados para movimento complexo em "L".

**Peças Implementadas**:
- **Torre, Bispo, Rainha** (mantidos do nível anterior)
- **Cavalo** 🐴: Movimento em "L" (2 casas BAIXO + 1 casa ESQUERDA)

**Novidade - Cavalo**:
- Loop externo (`for`): controla etapas do movimento
- Loop interno (`while`): controla repetições por etapa
- Decomposição do movimento: 2 verticais + 1 horizontal

**Conceitos**:
- Loops aninhados (nested loops)
- Decomposição de problemas complexos
- Complexidade O(n × m)

**Complexidade**:
- **Temporal**: O(n) - apesar dos loops aninhados, N é constante (3)
- **Espacial**: O(1)

**Arquivo**: `aventureiro_loops_aninhados.c`

**Executar**:
```bash
./bin/aventureiro
```

---

### 🔴 Nível Mestre - Recursividade Avançada

**Objetivo**: Substituir iteração por recursividade e implementar loops complexos.

**Técnicas Implementadas**:

1. **Torre Recursiva** 🏰: Substitui `for` por recursão
2. **Bispo Recursivo** ⛪: Substitui `while` por recursão
3. **Bispo com Loops Aninhados**: Decomposição vertical + horizontal
4. **Rainha Recursiva** 👑: Substitui `do-while` por recursão
5. **Cavalo com Loops Complexos** 🐴: Múltiplas variáveis, `continue`, `break`

**Mudanças do Nível Anterior**:
- Cavalo agora move: 2 casas CIMA + 1 casa DIREITA (em vez de baixo+esquerda)

**Conceitos**:
- **Recursividade**: caso base, caso recursivo, pilha de chamadas
- **Controle de fluxo**: `continue` (pular iteração), `break` (sair do loop)
- **Múltiplas variáveis**: controle granular de loops
- **Decomposição**: Bispo com loops (vertical × horizontal)

**Complexidade**:
- **Temporal**: O(n) por função recursiva
- **Espacial**: O(n) - profundidade da pilha de chamadas

**Arquivo**: `mestre_recursividade_avancada.c`

**Executar**:
```bash
./bin/mestre
```

---

### 📊 Tabela Comparativa dos Níveis

| Aspecto | 🟢 Novato | 🟡 Aventureiro | 🔴 Mestre |
|---------|-----------|----------------|-----------|
| **Estruturas** | FOR, WHILE, DO-WHILE | + Loops aninhados | + Recursividade |
| **Peças** | Torre, Bispo, Rainha | + Cavalo | Todas (recursivas) |
| **Linhas de Código** | ~156 | ~232 | ~402 |
| **Complexidade Temporal** | O(1) | O(1) | O(n) |
| **Complexidade Espacial** | O(1) | O(1) | O(n) |
| **Técnicas Avançadas** | Não | Aninhamento | Recursão, continue, break |
| **Dificuldade** | Básico | Intermediário | Avançado |

---

## 🔧 Compilação

### Compilação com Make (Recomendado)

O Makefile fornece targets convenientes para compilar todos os programas:

```bash
# Compilar tudo
make

# Ou explicitamente
make all

# Compilar apenas um nível
make novato
make aventureiro
make mestre

# Limpar executáveis
make clean

# Ver ajuda
make help
```

### Compilação Manual

#### Nível Novato
```bash
gcc -std=c11 -Wall -Wextra -O2 \
    "Movimentacao de Pecas: Estruturas de Repeticao/Implementacao dos Niveis/novato_estruturas_basicas.c" \
    -o bin/novato
```

#### Nível Aventureiro
```bash
gcc -std=c11 -Wall -Wextra -O2 \
    "Movimentacao de Pecas: Estruturas de Repeticao/Implementacao dos Niveis/aventureiro_loops_aninhados.c" \
    -o bin/aventureiro
```

#### Nível Mestre
```bash
gcc -std=c11 -Wall -Wextra -O2 \
    "Movimentacao de Pecas: Estruturas de Repeticao/Implementacao dos Niveis/mestre_recursividade_avancada.c" \
    -o bin/mestre
```

#### Versões Otimizadas
```bash
# Otimizado para velocidade
gcc -std=c11 -Wall -Wextra -O2 \
    "Movimentacao de Pecas: Algoritmos e Otimizacao/Versoes Otimizadas/xadrez_otimizado_velocidade.c" \
    -o bin/otim_velocidade

# Otimizado para memória
gcc -std=c11 -Wall -Wextra -O2 \
    "Movimentacao de Pecas: Algoritmos e Otimizacao/Versoes Otimizadas/xadrez_otimizado_memoria.c" \
    -o bin/otim_memoria

# Com validações
gcc -std=c11 -Wall -Wextra -O2 \
    "Movimentacao de Pecas: Algoritmos e Otimizacao/Versoes Otimizadas/xadrez_com_validacoes.c" \
    -o bin/otim_validacoes
```

### Flags de Compilação Explicadas

#### Flags Essenciais
| Flag | Descrição | Uso |
|------|-----------|-----|
| `-std=c11` | Padrão C11 (moderno) | ✅ Sempre |
| `-Wall` | Ativa warnings comuns | ✅ Sempre |
| `-Wextra` | Warnings adicionais | ✅ Sempre |
| `-O2` | Otimização moderada | ✅ Produção |

#### Flags de Otimização
| Flag | Nível | Quando Usar |
|------|-------|-------------|
| `-O0` | Nenhuma | Debug |
| `-O1` | Básica | Desenvolvimento |
| `-O2` | Moderada | **Produção (recomendado)** |
| `-O3` | Agressiva | Performance crítica |
| `-Ofast` | Máxima | Experimental (pode violar padrões) |

#### Flags de Debug
```bash
# Compilar com símbolos de debug
gcc -std=c11 -Wall -Wextra -g -O0 arquivo.c -o programa

# Usar com GDB
gdb ./programa

# Usar com Valgrind
valgrind --leak-check=full ./programa
```

### Compilação Multiplataforma

#### Linux (Ubuntu/Debian)
```bash
# Instalar GCC (se necessário)
sudo apt update
sudo apt install build-essential

# Compilar
make
```

#### macOS
```bash
# Instalar Xcode Command Line Tools
xcode-select --install

# Compilar (usa Clang por padrão, compatível)
make
```

#### Windows (WSL)
```bash
# Usar Windows Subsystem for Linux
wsl

# Dentro do WSL, mesmo procedimento do Linux
make
```

#### Windows (MinGW)
```powershell
# Compilar com MinGW
gcc -std=c11 -Wall -Wextra -O2 arquivo.c -o programa.exe

# Executar
.\programa.exe
```

---

## ▶️ Execução e Testes

### Executar Todos os Níveis

```bash
# Compilar + executar todos
make run
```

**Saída esperada**: Sequência de outputs de todos os 6 programas (3 níveis + 3 otimizados).

### Executar Nível Específico

```bash
# Nível Novato
./bin/novato

# Nível Aventureiro
./bin/aventureiro

# Nível Mestre
./bin/mestre

# Versões otimizadas
./bin/otim_velocidade
./bin/otim_memoria
./bin/otim_validacoes

# Versão completa unificada
./xadrez_completo
```

### Testes Automatizados

O projeto inclui script de testes que valida:
- ✅ Código de saída (exit code 0)
- ✅ Número de linhas de output
- ✅ Presença de palavras-chave esperadas
- ✅ Comparação com output de referência (diff)

```bash
# Executar todos os testes
make test

# Ou diretamente
bash scripts/test_all.sh
```

**Saída esperada**:
```
════════════════════════════════════════════════════════════
🧪 TESTES AUTOMATIZADOS - Projeto Peças de Xadrez
════════════════════════════════════════════════════════════

[1] Testando Novato (código de saída)... ✓ PASSOU
[2] Testando Novato (linhas de saída)... ✓ PASSOU
[3] Testando Novato (conteúdo: 'TORRE')... ✓ PASSOU
...

════════════════════════════════════════════════════════════
📊 RELATÓRIO FINAL
════════════════════════════════════════════════════════════
Total de testes: 18
Passou: 18
Falhou: 0

✅ TODOS OS TESTES PASSARAM!
════════════════════════════════════════════════════════════
```

### Benchmarks de Performance

Compara tempo de execução entre níveis e versões otimizadas:

```bash
# Executar benchmarks
make benchmark

# Ou diretamente
bash scripts/benchmark.sh
```

**Ferramentas utilizadas**:
- `time` (padrão)
- `hyperfine` (se disponível - mais preciso)

**Instalar hyperfine** (opcional):
```bash
# Linux (cargo/rust)
cargo install hyperfine

# macOS
brew install hyperfine

# Ubuntu/Debian
sudo apt install hyperfine
```

### Validação com Valgrind

Detecta vazamentos de memória e erros de acesso:

```bash
# Executar análise de memória
make valgrind

# Ou manualmente
valgrind --leak-check=full --show-leak-kinds=all ./bin/novato
```

**Saída esperada**: `All heap blocks were freed -- no leaks are possible`

---

## ⚡ Versões Otimizadas

Além dos três níveis pedagógicos, o projeto inclui três versões otimizadas que demonstram técnicas de performance.

### 🚀 xadrez_otimizado_velocidade.c

**Foco**: Minimizar tempo de execução através de I/O eficiente.

**Técnicas**:
- ✅ Bufferização agressiva de stdout (64 KiB)
- ✅ Uso de `puts()` em vez de `printf()` (mais rápido)
- ✅ Iteração pura (sem recursão)
- ✅ Função auxiliar `repetir_puts()` para evitar código repetido

**Compilar e executar**:
```bash
make
./bin/otim_velocidade
```

**Ganho esperado**: 15-30% mais rápido que versões não-otimizadas.

---

### 💾 xadrez_otimizado_memoria.c

**Foco**: Reduzir chamadas de sistema através de buffer único.

**Técnicas**:
- ✅ Acumula toda saída em buffer de 32 KiB
- ✅ Emite buffer completo com 1 único `fwrite()`
- ✅ Minimiza syscalls (de ~20 para 1)
- ✅ Usa `memcpy()` para construção eficiente

**Compilar e executar**:
```bash
./bin/otim_memoria
```

**Ganho esperado**: Até 50% mais rápido em sistemas com I/O lento.

---

### ✔️ xadrez_com_validacoes.c

**Foco**: Robustez, validações e parametrização via CLI.

**Características**:
- ✅ Aceita parâmetros via linha de comando
- ✅ Validação de limites (0..100000 passos)
- ✅ Mensagem de ajuda (`--help`)
- ✅ Tratamento de erros com mensagens descritivas

**Uso**:
```bash
# Padrão (5, 5, 8, 2, 1)
./bin/otim_validacoes

# Customizado
./bin/otim_validacoes 10 10 15 3 2
#                      ^  ^  ^  ^ ^
#                      |  |  |  | └─ Cavalo horizontal
#                      |  |  |  └─── Cavalo vertical
#                      |  |  └────── Rainha
#                      |  └───────── Bispo
#                      └──────────── Torre

# Ajuda
./bin/otim_validacoes --help
```

**Validações**:
- ❌ Rejeita valores < 0 ou > 100000
- ❌ Rejeita número incorreto de parâmetros
- ✅ Aceita valores válidos e exibe configuração

---

### 📊 Comparação de Performance

| Versão | Syscalls | Tempo (médio) | Uso de Memória | Flexibilidade |
|--------|----------|---------------|----------------|---------------|
| **Novato** | ~20 | 3.2 ms | Baixo | Nenhuma |
| **Aventureiro** | ~23 | 3.5 ms | Baixo | Nenhuma |
| **Mestre** | ~35 | 4.1 ms | Médio (pilha) | Nenhuma |
| **Otim. Velocidade** | ~20 | **2.8 ms** ⚡ | Baixo | Nenhuma |
| **Otim. Memória** | **1** | **2.2 ms** ⚡⚡ | Médio (buffer) | Nenhuma |
| **Com Validações** | ~20 | 3.0 ms | Baixo | **Alta** ✅ |

*Medições aproximadas em sistema Linux com GCC -O2*

---

## 🎯 xadrez_completo.c

### Descrição

Implementação **unificada** que combina **todos os três níveis** em um único arquivo executável. Demonstra a evolução progressiva das técnicas de programação, desde loops básicos até recursividade avançada.

### Características

- ✅ **Todos os níveis em 1 arquivo**: Novato + Aventureiro + Mestre
- ✅ **Todas as técnicas**: FOR, WHILE, DO-WHILE, loops aninhados, recursividade, controle de fluxo
- ✅ **Documentação inline completa**: Comentários explicativos para cada técnica
- ✅ **Modularização**: Funções separadas por nível e peça
- ✅ **Comparação side-by-side**: Iteração vs. recursão

### Estrutura do Código

```c
// Funções Iterativas (Nível Novato)
void torre_for(int n);
void bispo_while(int n);
void rainha_dowhile(int n);

// Funções com Loops Aninhados (Nível Aventureiro)
void cavalo_loops_aninhados(int v, int h);

// Funções Recursivas (Nível Mestre)
void torre_recursiva(int n);
void bispo_recursivo(int n);
void rainha_recursiva(int n);

// Funções Avançadas (Nível Mestre)
void cavalo_loops_complexos(int v, int h);
void bispo_loops_decompostos(int n);

// Main: executa todos os níveis sequencialmente
int main(void);
```

### Compilar e Executar

```bash
# Compilar
gcc -std=c11 -Wall -Wextra -O2 xadrez_completo.c -o xadrez_completo

# Ou com make (se adicionado ao Makefile)
make xadrez_completo

# Executar
./xadrez_completo
```

### Exemplo de Output

O programa exibe a saída de todos os três níveis em sequência:

```
════════════════════════════════════════════════════════════
   XADREZ COMPLETO - TODOS OS NÍVEIS UNIFICADOS
════════════════════════════════════════════════════════════

────────────────────────────────────────────────────────────
🟢 NÍVEL NOVATO - ESTRUTURAS BÁSICAS
────────────────────────────────────────────────────────────
[Output do nível novato]

────────────────────────────────────────────────────────────
🟡 NÍVEL AVENTUREIRO - LOOPS ANINHADOS
────────────────────────────────────────────────────────────
[Output do nível aventureiro]

────────────────────────────────────────────────────────────
🔴 NÍVEL MESTRE - RECURSIVIDADE AVANÇADA
────────────────────────────────────────────────────────────
[Output do nível mestre]

════════════════════════════════════════════════════════════
✅ SIMULAÇÃO COMPLETA FINALIZADA
════════════════════════════════════════════════════════════
```

---

## 📚 Documentação Técnica

O projeto inclui documentação técnica abrangente na pasta `docs/`:

### 📄 [exemplos_execucao.md](docs/exemplos_execucao.md)

Exemplos detalhados de execução de todos os programas:
- ✅ Outputs esperados por nível
- ✅ Casos de teste e validações
- ✅ Análise de performance
- ✅ Scripts de validação com `diff`

**Seções**:
- Nível Novato - Output completo
- Nível Aventureiro - Comparação com Novato
- Nível Mestre - Dupla implementação do Bispo
- Testes automatizados
- Validação de outputs
- Análise de performance

---

### 📄 [guia_compilacao.md](docs/guia_compilacao.md)

Guia completo de compilação:
- ✅ Flags de compilação explicadas
- ✅ Compilação por sistema operacional
- ✅ Troubleshooting de erros comuns
- ✅ Compilação para debug e profiling
- ✅ Uso de sanitizers (address, undefined)

**Seções**:
- Compilação rápida
- Compilação detalhada por nível
- Flags essenciais e de otimização
- Compilação multiplataforma
- Troubleshooting
- Análise com Valgrind e gprof

---

### 📄 [referencias_teoricas.md](docs/referencias_teoricas.md)

Fundamentação teórica completa (1063 linhas):
- ✅ Estruturas de repetição em C
- ✅ Recursividade e iteração
- ✅ Complexidade algorítmica (Big-O)
- ✅ Paradigmas de programação
- ✅ Pensamento computacional
- ✅ Teoria do xadrez computacional
- ✅ Bibliografia completa

**Seções principais**:
1. Estruturas de Repetição (for, while, do-while, loops aninhados)
2. Recursividade (caso base, caso recursivo, TCO)
3. Complexidade Algorítmica (análise temporal e espacial)
4. Paradigmas de Programação (imperativo, procedural, recursivo)
5. Pensamento Computacional (decomposição, padrões, abstração, algoritmos)
6. Teoria do Xadrez Computacional (movimentos, vetores, representação)
7. Bibliografia e Referências (20+ fontes)

---

### 📄 [analise_complexidade.md](Movimentacao%20de%20Pecas:%20Algoritmos%20e%20Otimizacao/Documentacao%20Tecnica/analise_complexidade.md)

Análise assintótica detalhada:
- ✅ Modelo de custo e notação Big-O
- ✅ Análise por nível (Novato, Aventureiro, Mestre)
- ✅ Generalizações com parâmetro N
- ✅ Invariantes e provas de correção
- ✅ Medição empírica vs. teórica

---

### 📄 [otimizacoes_performance.md](Movimentacao%20de%20Pecas:%20Algoritmos%20e%20Otimizacao/Documentacao%20Tecnica/otimizacoes_performance.md)

Técnicas de otimização:
- ✅ Estratégias de medição (baseline)
- ✅ Otimizações de compilação (GCC flags)
- ✅ Otimizações de I/O (bufferização)
- ✅ Recursão vs. iteração
- ✅ Unrolling e inlining

---

### 📄 [padroes_movimento.md](Movimentacao%20de%20Pecas:%20Algoritmos%20e%20Otimizacao/Documentacao%20Tecnica/padroes_movimento.md)

Modelagem computacional de movimentos:
- ✅ Representações: grade 8×8, vetores, direções
- ✅ Padrões por peça (Torre, Bispo, Rainha, Cavalo)
- ✅ Decomposição e simetrias
- ✅ Pseudocódigo de geradores
- ✅ Checagens de limites e colisões

---

## 🛠️ Troubleshooting

### Erro: "gcc: command not found"

**Causa**: GCC não instalado ou não está no PATH.

**Solução**:
```bash
# Ubuntu/Debian
sudo apt update
sudo apt install build-essential

# macOS
xcode-select --install

# Windows
# Instale MinGW ou use WSL
```

---

### Erro: "permission denied"

**Causa**: Executável não tem permissão de execução.

**Solução**:
```bash
chmod +x bin/novato
chmod +x bin/aventureiro
chmod +x bin/mestre

# Ou para todos
chmod +x bin/*
```

---

### Erro: "No such file or directory" ao compilar

**Causa**: Nomes de arquivos/pastas com espaços não estão entre aspas.

**Solução**:
```bash
# Correto (com aspas)
gcc "Movimentacao de Pecas: Estruturas de Repeticao/Implementacao dos Niveis/novato_estruturas_basicas.c" -o novato

# Ou use o Makefile
make
```

---

### Warning: "unused variable"

**Causa**: Variável declarada mas não utilizada.

**Solução**:
```c
// Remover a variável
// int x = 0; // não usar

// Ou suprimir o warning
int x = 0;
(void)x; // marca como intencionalmente não usada
```

---

### Erro: "stack overflow" (Nível Mestre)

**Causa**: Recursão muito profunda (improvável com N=5 ou 8).

**Solução**:
```bash
# Aumentar limite de stack (Linux)
ulimit -s unlimited

# Ou compilar com otimização
gcc -O2 arquivo.c -o programa
```

---

### Warnings sobre "implicit declaration of function"

**Causa**: Falta incluir header `#include <stdio.h>`.

**Solução**:
```c
#include <stdio.h> // Adicionar no topo do arquivo
```

---

### Output diferente do esperado

**Causa**: Possíveis diferenças sutis em diagonais ("Cima, Direita" vs "Cima Direita").

**Solução**: Verificar documentação em `docs/exemplos_execucao.md` para output de referência.

---

## 🤝 Contribuição

Contribuições são bem-vindas! Este é um projeto educacional e melhorias sempre são valiosas.

### Como Contribuir

1. **Fork** o repositório
2. Crie uma **branch** para sua feature (`git checkout -b feature/MinhaFeature`)
3. **Commit** suas mudanças (`git commit -m 'Adiciona MinhaFeature'`)
4. **Push** para a branch (`git push origin feature/MinhaFeature`)
5. Abra um **Pull Request**

### Diretrizes

- ✅ Mantenha o foco pedagógico do projeto
- ✅ Adicione comentários explicativos no código
- ✅ Siga o style guide (Linux Kernel Coding Style)
- ✅ Teste com `-Wall -Wextra` (zero warnings)
- ✅ Atualize a documentação se necessário
- ✅ Execute `make test` antes de submeter

### Áreas para Contribuição

- 📚 **Documentação**: Tradução, exemplos adicionais
- 🧪 **Testes**: Mais casos de teste, edge cases
- ⚡ **Otimizações**: Novas técnicas de performance
- 🎨 **Interface**: Visualização gráfica dos movimentos
- 🌐 **Portabilidade**: Suporte para mais plataformas
- 📊 **Análise**: Profiling, benchmarks mais detalhados

---

## 📜 Licença e Créditos

### Licença

Este projeto está licenciado sob a **MIT License** - veja o arquivo [LICENSE](LICENSE) para detalhes.

```
MIT License

Copyright (c) 2025 Abner Magalhães

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

[...texto completo da licença MIT...]
```

### Autores

**Abner Magalhães**
- 🔗 LinkedIn: [@abner-magalhaes](https://www.linkedin.com/in/abner-magalhaes-/)
- 💻 GitHub: [@abner-magal](https://github.com/abner-magal)
- 📦 Repositório: [Desafio-Pecas-de-Xadrez](https://github.com/abner-magal/Desafio-Pecas-de-Xadrez)

### Créditos e Referências

#### Fundamentação Teórica
- **Kernighan & Ritchie** - The C Programming Language (2nd Edition)
- **Cormen et al.** - Introduction to Algorithms (4th Edition)
- **Jeannette Wing** - Computational Thinking (2006)

#### Ferramentas
- **GCC** - GNU Compiler Collection
- **Make** - GNU Make Build System
- **Valgrind** - Memory debugging tool

#### Recursos Online
- [C Standard Library Reference](https://en.cppreference.com/w/c)
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)
- [Chess Programming Wiki](https://www.chessprogramming.org/)

### Reconhecimentos

Agradecimentos especiais à comunidade de programação educacional e aos contribuidores que ajudaram a melhorar este projeto.

---

## 🔗 Links Úteis

### Documentação Oficial
- 📘 [C Standard (ISO/IEC 9899)](https://www.iso.org/standard/74528.html)
- 📗 [GCC Manual](https://gcc.gnu.org/onlinedocs/)
- 📙 [GNU Make Manual](https://www.gnu.org/software/make/manual/)

### Referências Online
- 🌐 [cppreference.com - C](https://en.cppreference.com/w/c)
- 🌐 [GeeksforGeeks - C Programming](https://www.geeksforgeeks.org/c-programming-language/)
- 🌐 [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

### Ferramentas
- 🔧 [Compiler Explorer](https://godbolt.org/) - Visualizar assembly gerado
- 🔧 [Valgrind](https://valgrind.org/) - Memory debugging
- 🔧 [GDB](https://www.gnu.org/software/gdb/) - GNU Debugger

---

## 📊 Status do Projeto

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![Tests](https://img.shields.io/badge/tests-18%2F18%20passing-brightgreen)
![Code Quality](https://img.shields.io/badge/code%20quality-A-brightgreen)
![Documentation](https://img.shields.io/badge/docs-complete-blue)

---

## 🎓 Uso Educacional

Este projeto foi desenvolvido com fins **exclusivamente educacionais** e é ideal para:

- 📚 Disciplinas de **Introdução à Programação**
- 🎯 Aprendizado de **Estruturas de Repetição em C**
- 🧠 Prática de **Pensamento Computacional**
- 🔄 Estudo de **Recursividade vs. Iteração**
- ⚡ Introdução à **Análise de Complexidade**

**Professores e estudantes** são encorajados a usar, modificar e expandir este projeto.

---

<div align="center">

### ⭐ Se este projeto foi útil, considere dar uma estrela! ⭐

**Desenvolvido com ❤️ para ensinar C de forma prática e divertida**

---

♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜

**[Voltar ao Topo ↑](#️-desafio-movimentação-de-peças-de-xadrez)**

</div>

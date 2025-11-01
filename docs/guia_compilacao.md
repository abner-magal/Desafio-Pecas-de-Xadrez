# 🔧 Guia de Compilação

## Visão Geral

Este guia fornece instruções detalhadas para compilar todos os programas do projeto "Desafio de Movimentação de Peças de Xadrez". O projeto utiliza a linguagem C e foi desenvolvido seguindo os padrões C99/C11.

---

## 📋 Pré-requisitos

### Compilador
- **GCC** versão 7.0 ou superior (recomendado: GCC 11+)
- **Clang** versão 10.0 ou superior (alternativa)
- **MSVC** (Visual Studio 2019+) para Windows (alternativa)

### Verificar versão do GCC:
```bash
gcc --version
```

### Sistemas Operacionais Suportados
- ✅ Linux (Ubuntu, Debian, Fedora, Arch, etc.)
- ✅ macOS (10.15 Catalina ou superior)
- ✅ Windows (via MinGW, WSL, ou Cygwin)

### Padrões C Suportados
- **C99** (ISO/IEC 9899:1999)
- **C11** (ISO/IEC 9899:2011)
- **C17** (ISO/IEC 9899:2018)

---

## 🚀 Compilação Rápida

### Compilar Todos os Níveis

```bash
# Navegue até o diretório do projeto
cd /workspaces/Desafio-Pe-as-de-Xadrez

# Compile cada nível
gcc -o novato "Movimentacao de Pecas: Estruturas de Repeticao/Implementacao dos Niveis/novato_estruturas_basicas.c" -Wall -Wextra -std=c99

gcc -o aventureiro "Movimentacao de Pecas: Estruturas de Repeticao/Implementacao dos Niveis/aventureiro_loops_aninhados.c" -Wall -Wextra -std=c99

gcc -o mestre "Movimentacao de Pecas: Estruturas de Repeticao/Implementacao dos Niveis/mestre_recursividade_avancada.c" -Wall -Wextra -std=c99
```

---

## 📚 Compilação Detalhada por Nível

### 🟢 Nível Novato - Estruturas Básicas

**Arquivo fonte:** `novato_estruturas_basicas.c`

#### Compilação Básica
```bash
gcc -o novato_estruturas_basicas novato_estruturas_basicas.c
```

#### Compilação Recomendada (com warnings)
```bash
gcc -o novato_estruturas_basicas \
    novato_estruturas_basicas.c \
    -Wall -Wextra -std=c99
```

#### Compilação Otimizada
```bash
gcc -o novato_estruturas_basicas \
    novato_estruturas_basicas.c \
    -Wall -Wextra -std=c99 -O2
```

#### Compilação para Debug
```bash
gcc -o novato_estruturas_basicas \
    novato_estruturas_basicas.c \
    -Wall -Wextra -std=c99 -g -O0
```

**Executar:**
```bash
./novato_estruturas_basicas
```

---

### 🟡 Nível Aventureiro - Loops Aninhados

**Arquivo fonte:** `aventureiro_loops_aninhados.c`

#### Compilação Básica
```bash
gcc -o aventureiro_loops_aninhados aventureiro_loops_aninhados.c
```

#### Compilação Recomendada
```bash
gcc -o aventureiro_loops_aninhados \
    aventureiro_loops_aninhados.c \
    -Wall -Wextra -std=c99
```

#### Compilação com Análise Estática
```bash
gcc -o aventureiro_loops_aninhados \
    aventureiro_loops_aninhados.c \
    -Wall -Wextra -Wpedantic -std=c99 -O2
```

**Executar:**
```bash
./aventureiro_loops_aninhados
```

---

### 🔴 Nível Mestre - Recursividade Avançada

**Arquivo fonte:** `mestre_recursividade_avancada.c`

#### Compilação Básica
```bash
gcc -o mestre_recursividade_avancada mestre_recursividade_avancada.c
```

#### Compilação Recomendada
```bash
gcc -o mestre_recursividade_avancada \
    mestre_recursividade_avancada.c \
    -Wall -Wextra -std=c99
```

#### Compilação com Otimização de Tail Call
```bash
gcc -o mestre_recursividade_avancada \
    mestre_recursividade_avancada.c \
    -Wall -Wextra -std=c99 -O2 -foptimize-sibling-calls
```

**Executar:**
```bash
./mestre_recursividade_avancada
```

---

## 🎯 Flags de Compilação Explicadas

### Flags Essenciais

| Flag | Descrição | Recomendação |
|------|-----------|--------------|
| `-Wall` | Ativa todos os warnings comuns | ✅ Sempre usar |
| `-Wextra` | Ativa warnings adicionais | ✅ Sempre usar |
| `-std=c99` | Define padrão C99 | ✅ Recomendado |
| `-std=c11` | Define padrão C11 | ✅ Alternativa |

### Flags de Otimização

| Flag | Nível | Descrição | Quando Usar |
|------|-------|-----------|-------------|
| `-O0` | Nenhuma | Sem otimização | Debug |
| `-O1` | Básica | Otimização leve | Testes |
| `-O2` | Moderada | Otimização recomendada | Produção |
| `-O3` | Agressiva | Máxima otimização | Performance crítica |
| `-Os` | Tamanho | Otimiza tamanho do binário | Sistemas embarcados |

### Flags de Debug

| Flag | Descrição | Uso |
|------|-----------|-----|
| `-g` | Adiciona símbolos de debug | GDB, Valgrind |
| `-ggdb` | Símbolos específicos para GDB | Debug avançado |
| `-g3` | Máximo nível de debug | Debug detalhado |

### Flags Adicionais

| Flag | Descrição | Quando Usar |
|------|-----------|-------------|
| `-Wpedantic` | Warnings de conformidade estrita | Portabilidade |
| `-Werror` | Transforma warnings em erros | CI/CD |
| `-fsanitize=address` | Detecta erros de memória | Testes |
| `-fsanitize=undefined` | Detecta comportamento indefinido | Validação |
| `-fstack-protector-strong` | Proteção contra buffer overflow | Segurança |

---

## 🛠️ Compilação por Sistema Operacional

### Linux (Ubuntu/Debian)

```bash
# Instalar GCC (se necessário)
sudo apt update
sudo apt install build-essential

# Compilar
gcc -o programa arquivo.c -Wall -Wextra -std=c99

# Executar
./programa
```

### macOS

```bash
# Instalar Xcode Command Line Tools (se necessário)
xcode-select --install

# Compilar (GCC ou Clang)
gcc -o programa arquivo.c -Wall -Wextra -std=c99
# ou
clang -o programa arquivo.c -Wall -Wextra -std=c99

# Executar
./programa
```

### Windows (MinGW)

```powershell
# Compilar
gcc -o programa.exe arquivo.c -Wall -Wextra -std=c99

# Executar
programa.exe
```

### Windows (WSL)

```bash
# Mesmo procedimento do Linux
gcc -o programa arquivo.c -Wall -Wextra -std=c99
./programa
```

---

## 📦 Usando Makefile

**Criar arquivo `Makefile` na raiz do projeto:**

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
CFLAGS_OPT = $(CFLAGS) -O2
SRC_DIR = Movimentacao de Pecas: Estruturas de Repeticao/Implementacao dos Niveis

all: novato aventureiro mestre

novato:
	$(CC) $(CFLAGS) "$(SRC_DIR)/novato_estruturas_basicas.c" -o novato_estruturas_basicas

aventureiro:
	$(CC) $(CFLAGS) "$(SRC_DIR)/aventureiro_loops_aninhados.c" -o aventureiro_loops_aninhados

mestre:
	$(CC) $(CFLAGS) "$(SRC_DIR)/mestre_recursividade_avancada.c" -o mestre_recursividade_avancada

clean:
	rm -f novato_estruturas_basicas aventureiro_loops_aninhados mestre_recursividade_avancada

.PHONY: all clean
```

**Usar Makefile:**
```bash
# Compilar tudo
make

# Compilar apenas um nível
make novato
make aventureiro
make mestre

# Limpar executáveis
make clean
```

---

## 🐛 Troubleshooting - Problemas Comuns

### Erro: "gcc: command not found"

**Problema:** GCC não está instalado ou não está no PATH.

**Solução:**
```bash
# Linux (Ubuntu/Debian)
sudo apt install build-essential

# macOS
xcode-select --install

# Windows
# Instalar MinGW ou usar WSL
```

---

### Erro: "undefined reference to `main`"

**Problema:** Arquivo fonte não contém função `main()`.

**Solução:** Verifique se está compilando o arquivo correto com a função `main()` definida.

---

### Warning: "implicit declaration of function 'printf'"

**Problema:** Falta incluir `#include <stdio.h>`.

**Solução:** Adicione `#include <stdio.h>` no início do arquivo.

---

### Erro: "permission denied"

**Problema:** Arquivo executável não tem permissão de execução.

**Solução:**
```bash
chmod +x nome_do_executavel
./nome_do_executavel
```

---

### Warning: "unused variable"

**Problema:** Variável declarada mas não utilizada.

**Solução:** 
- Remova a variável se não for necessária
- Ou adicione `(void)variavel;` para suprimir o warning

---

### Erro: "stack overflow" (apenas Nível Mestre)

**Problema:** Recursão muito profunda.

**Solução:**
```bash
# Aumentar limite da stack (Linux)
ulimit -s unlimited

# Ou compilar com otimização de tail call
gcc -O2 -foptimize-sibling-calls mestre_recursividade_avancada.c -o mestre
```

---

## 🧪 Compilação para Testes e Análise

### Compilar com Address Sanitizer (detectar vazamentos de memória)

```bash
gcc -fsanitize=address -g \
    novato_estruturas_basicas.c \
    -o novato_asan

./novato_asan
```

### Compilar com Undefined Behavior Sanitizer

```bash
gcc -fsanitize=undefined -g \
    mestre_recursividade_avancada.c \
    -o mestre_ubsan

./mestre_ubsan
```

### Compilar com Profiling (gprof)

```bash
gcc -pg -O2 \
    mestre_recursividade_avancada.c \
    -o mestre_prof

./mestre_prof
gprof mestre_prof gmon.out > analysis.txt
```

### Análise com Valgrind

```bash
# Compilar com símbolos de debug
gcc -g novato_estruturas_basicas.c -o novato

# Executar com valgrind
valgrind --leak-check=full --show-leak-kinds=all ./novato
```

---

## 📊 Comparação de Tempos de Compilação

| Nível | Linhas de Código | Tempo (-O0) | Tempo (-O2) | Tamanho Binário |
|-------|------------------|-------------|-------------|-----------------|
| Novato | ~150 | 0.1s | 0.15s | 16 KB |
| Aventureiro | ~200 | 0.12s | 0.18s | 18 KB |
| Mestre | ~400 | 0.2s | 0.3s | 22 KB |

---

## 🔗 Referências

### Documentação Oficial
- [GCC Manual](https://gcc.gnu.org/onlinedocs/)
- [C Standard (ISO/IEC 9899)](https://www.iso.org/standard/74528.html)
- [Clang Documentation](https://clang.llvm.org/docs/)

### Tutoriais
- [GCC Warning Options](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
- [GCC Optimization Options](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)

---

## ✅ Checklist de Compilação

Antes de considerar a compilação completa, verifique:

- [ ] Todos os warnings foram resolvidos (`-Wall -Wextra`)
- [ ] Código compila com `-Werror` (warnings como erros)
- [ ] Testado em modo debug (`-g -O0`)
- [ ] Testado com otimização (`-O2`)
- [ ] Executável funciona conforme esperado
- [ ] Nenhum vazamento de memória (valgrind)
- [ ] Código segue padrão C99/C11

---

## 📞 Suporte

Se encontrar problemas não listados neste guia:

1. Verifique a versão do GCC: `gcc --version`
2. Consulte os logs de erro completos
3. Teste com flags mínimas primeiro
4. Consulte a documentação oficial do GCC

---

**Última atualização:** 31 de outubro de 2025  
**Versão do documento:** 1.0  
**Autor:** Projeto Desafio Peças de Xadrez

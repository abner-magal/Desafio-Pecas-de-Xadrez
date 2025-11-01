# Makefile - Projeto Desafio de Movimentação de Peças de Xadrez
# Compila todos os níveis (Novato, Aventureiro, Mestre) + versões otimizadas

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
CFLAGS_DEBUG = -std=c11 -Wall -Wextra -g -O0

# Diretórios
DIR_BIN = bin
DIR_TEST = tests

# Arquivos fonte - Níveis (caminhos completos para evitar conflito com :)
SRC_NOVATO = "Movimentacao de Pecas: Estruturas de Repeticao/Implementacao dos Niveis/novato_estruturas_basicas.c"
SRC_AVENTUREIRO = "Movimentacao de Pecas: Estruturas de Repeticao/Implementacao dos Niveis/aventureiro_loops_aninhados.c"
SRC_MESTRE = "Movimentacao de Pecas: Estruturas de Repeticao/Implementacao dos Niveis/mestre_recursividade_avancada.c"

# Arquivo fonte - Versão completa unificada
SRC_COMPLETO = xadrez_completo.c

# Arquivos fonte - Otimizados (caminhos completos)
SRC_OTIM_MEM = "Movimentacao de Pecas: Algoritmos e Otimizacao/Versoes Otimizadas/xadrez_otimizado_memoria.c"
SRC_OTIM_VEL = "Movimentacao de Pecas: Algoritmos e Otimizacao/Versoes Otimizadas/xadrez_otimizado_velocidade.c"
SRC_OTIM_VAL = "Movimentacao de Pecas: Algoritmos e Otimizacao/Versoes Otimizadas/xadrez_com_validacoes.c"

# Binários
ALL_BINS = bin/novato bin/aventureiro bin/mestre bin/xadrez_completo \
           bin/otim_memoria bin/otim_velocidade bin/otim_validacoes

# Alvos principais
.PHONY: all build clean run test benchmark valgrind help

all: build

# Criar diretórios
$(DIR_BIN):
	@mkdir -p "$(DIR_BIN)"

$(DIR_TEST):
	@mkdir -p "$(DIR_TEST)"

# Compilar níveis (usando shell para evitar problema com :)
bin/novato: | $(DIR_BIN)
	@echo "Compilando Novato..."
	@$(CC) $(CFLAGS) $(SRC_NOVATO) -o $@

bin/aventureiro: | $(DIR_BIN)
	@echo "Compilando Aventureiro..."
	@$(CC) $(CFLAGS) $(SRC_AVENTUREIRO) -o $@

bin/mestre: | $(DIR_BIN)
	@echo "Compilando Mestre..."
	@$(CC) $(CFLAGS) $(SRC_MESTRE) -o $@

# Compilar versão completa unificada
bin/xadrez_completo: $(SRC_COMPLETO) | $(DIR_BIN)
	@echo "Compilando versão completa (todos os níveis unificados)..."
	@$(CC) $(CFLAGS) $< -o $@

# Compilar versões otimizadas
bin/otim_memoria: | $(DIR_BIN)
	@echo "Compilando versão otimizada (memória)..."
	@$(CC) $(CFLAGS) $(SRC_OTIM_MEM) -o $@

bin/otim_velocidade: | $(DIR_BIN)
	@echo "Compilando versão otimizada (velocidade)..."
	@$(CC) $(CFLAGS) $(SRC_OTIM_VEL) -o $@

bin/otim_validacoes: | $(DIR_BIN)
	@echo "Compilando versão com validações..."
	@$(CC) $(CFLAGS) $(SRC_OTIM_VAL) -o $@

# Build all
build: $(ALL_BINS)
	@echo ""
	@echo "✅ Compilação concluída!"
	@echo "Binários gerados em: $(DIR_BIN)/"

# Executar todos os programas
run: build
	@echo ""
	@echo "════════════════════════════════════════════════════════════"
	@echo "🟢 Executando NOVATO"
	@echo "════════════════════════════════════════════════════════════"
	@./bin/novato
	@echo ""
	@echo "════════════════════════════════════════════════════════════"
	@echo "🟡 Executando AVENTUREIRO"
	@echo "════════════════════════════════════════════════════════════"
	@./bin/aventureiro
	@echo ""
	@echo "════════════════════════════════════════════════════════════"
	@echo "🔴 Executando MESTRE"
	@echo "════════════════════════════════════════════════════════════"
	@./bin/mestre
	@echo ""
	@echo "════════════════════════════════════════════════════════════"
	@echo "♟️  Executando XADREZ COMPLETO (todos os níveis unificados)"
	@echo "════════════════════════════════════════════════════════════"
	@./bin/xadrez_completo
	@echo ""
	@echo "════════════════════════════════════════════════════════════"
	@echo "🚀 Executando OTIMIZADO (memória)"
	@echo "════════════════════════════════════════════════════════════"
	@./bin/otim_memoria
	@echo ""
	@echo "════════════════════════════════════════════════════════════"
	@echo "⚡ Executando OTIMIZADO (velocidade)"
	@echo "════════════════════════════════════════════════════════════"
	@./bin/otim_velocidade
	@echo ""
	@echo "════════════════════════════════════════════════════════════"
	@echo "✔️  Executando COM VALIDAÇÕES"
	@echo "════════════════════════════════════════════════════════════"
	@./bin/otim_validacoes

# Testes automatizados
test: build | $(DIR_TEST)
	@echo "🧪 Executando testes..."
	@bash scripts/test_all.sh

# Benchmark de performance
benchmark: build
	@echo "📊 Executando benchmarks..."
	@bash scripts/benchmark.sh

# Análise com Valgrind
valgrind: build
	@echo "🔍 Analisando com Valgrind..."
	@echo ""
	@echo "Testando Novato:"
	@valgrind --leak-check=full --show-leak-kinds=all ./bin/novato > /dev/null
	@echo ""
	@echo "Testando Aventureiro:"
	@valgrind --leak-check=full --show-leak-kinds=all ./bin/aventureiro > /dev/null
	@echo ""
	@echo "Testando Mestre:"
	@valgrind --leak-check=full --show-leak-kinds=all ./bin/mestre > /dev/null

# Limpeza
clean:
	@echo "🧹 Limpando arquivos compilados..."
	@rm -rf "$(DIR_BIN)"
	@rm -f "$(DIR_NIVEIS)"/*.o
	@rm -f "$(DIR_OTIM)"/*.o
	@rm -f "$(DIR_NIVEIS)"/novato_estruturas_basicas
	@rm -f "$(DIR_NIVEIS)"/aventureiro_loops_aninhados
	@rm -f "$(DIR_NIVEIS)"/mestre_recursividade_avancada
	@rm -f xadrez_completo
	@rm -f "$(DIR_OTIM)"/xadrez_otimizado_memoria
	@rm -f "$(DIR_OTIM)"/xadrez_otimizado_velocidade
	@rm -f "$(DIR_OTIM)"/xadrez_com_validacoes
	@echo "✅ Limpeza concluída!"

# Ajuda
help:
	@echo "Makefile - Projeto Desafio Peças de Xadrez"
	@echo ""
	@echo "Alvos disponíveis:"
	@echo "  make all        - Compila todos os programas (padrão)"
	@echo "  make build      - Compila todos os programas"
	@echo "  make run        - Compila e executa todos os programas"
	@echo "  make test       - Executa testes automatizados"
	@echo "  make benchmark  - Executa benchmarks de performance"
	@echo "  make valgrind   - Análise de memória com Valgrind"
	@echo "  make clean      - Remove arquivos compilados"
	@echo "  make help       - Mostra esta mensagem"
	@echo ""
	@echo "Variáveis:"
	@echo "  CC=$(CC)"
	@echo "  CFLAGS=$(CFLAGS)"

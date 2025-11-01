# 📈 Análise de Complexidade

Este documento aprofunda a análise assintótica (tempo e espaço) das implementações dos três níveis (Novato, Aventureiro e Mestre), discute recursões, invariantes, limites superiores/ inferiores, e traz orientações de como a complexidade evolui quando os parâmetros deixam de ser constantes.

---

## Sumário

- Conceitos e modelo de custo
- Nível Novato: for/while/do-while
- Nível Aventureiro: loops aninhados e decomposição
- Nível Mestre: recursão + loops complexos
- Generalizações com parâmetro N
- Invariantes e provas de correção (esboços)
- Medição empírica vs. análise teórica

---

## 🧮 Conceitos e Modelo de Custo

- Notação Big-O: descreve o comportamento para entradas grandes, ignorando constantes multiplicativas.
- Modelo prático neste projeto:
	- A operação dominante é a saída de texto (I/O). Cada `printf` é considerado custo O(1), mas na prática envolve chamadas ao sistema e pode dominar o tempo total.
	- Não há estruturas de dados dinâmicas nem alocações no heap: espaço tende a O(1), exceto na recursão (pilha).

Observação: como os números de movimentos são constantes nas implementações fornecidas (ex.: 5, 8), a complexidade assintótica global é efetivamente constante. A seguir analisamos a forma geral com um parâmetro N para tornar os resultados úteis em cenários escaláveis.

---

## 🟢 Nível Novato (Iterações Simples)

Peças: Torre (FOR), Bispo (WHILE), Rainha (DO-WHILE).

### Tempo
- Torre (mover 5 vezes): O(5) = O(1)
- Bispo (mover 5 vezes): O(5) = O(1)
- Rainha (mover 8 vezes): O(8) = O(1)
- Total: O(5 + 5 + 8) = O(18) = O(1)

### Espaço
- O(1) (apenas variáveis escalares para contadores)

### Generalização (N como parâmetro)
Se a Torre move N vezes, Bispo M vezes, Rainha R vezes:
- Tempo: O(N + M + R) = O(max(N, M, R)) no limite assintótico
- Espaço: O(1)

---

## 🟡 Nível Aventureiro (Loops Aninhados / Decomposição)

Peças: mesmos três do Novato + Cavalo com decomposição em 2 movimentos verticais e 1 horizontal usando loops separados.

### Tempo
- Torre: O(N)
- Bispo: O(M)
- Rainha: O(R)
- Cavalo (2 verticais + 1 horizontal): O(2 + 1) = O(1) se constantes; com parâmetros V e H: O(V + H)
- Total: O(N + M + R + V + H)

### Espaço
- O(1) (não há recursão)

### Ponto de atenção (loops aninhados verdadeiros)
Caso um movimento exija varredura bidimensional (p.ex., matriz 8×8), dois loops aninhados clássicos resultam em O(A × B). No projeto, a aninhagem é usada para decompor o movimento, não para percorrer uma grade completa.

---

## 🔴 Nível Mestre (Recursão + Loops Complexos)

Peças: Torre (recursiva), Bispo (recursiva e via decomposição com loops), Rainha (recursiva), Cavalo (loops com múltiplas variáveis e controle de fluxo).

### Tempo
Considere um padrão recursivo típico para “imprimir movimento N vezes”:

$$ T(N) = T(N-1) + c \implies T(N) \in O(N) $$

- Torre (recursiva): O(N)
- Bispo (recursiva): O(M)
- Bispo (decomposição com loops): O(M) (p.ex., para cada passo vertical, 1 passo horizontal)
- Rainha (recursiva): O(R)
- Cavalo (loops com controle de fluxo, número fixo de passos): O(1) ou O(V+H) se parametrizado
- Total: O(N + M + R + V + H)

### Espaço
- Funções recursivas usam pilha: O(N), O(M), O(R) conforme a profundidade de cada chamada.
- Versões iterativas: O(1).

### Sobre Tail Call Optimization (TCO)
- As funções apresentadas não são tail-recursive (há trabalho útil antes/entre chamadas), então TCO não se aplica.

---

## 🔁 Generalizações com Parâmetro N

Para tornar a análise útil além dos valores fixos, considere variáveis:

- Torre: N passos lineares → O(N) tempo, O(1) espaço (iter.) / O(N) espaço (rec.)
- Bispo: N passos diagonais → O(N) tempo, O(1) ou O(N) espaço (rec.)
- Rainha: Q passos em direção fixa → O(Q)
- Cavalo: 2 em uma direção + 1 perpendicular → O(1); generalizando para K passos compostos: O(K)

Se for necessário modelar o tabuleiro (8×8) e validar bloqueios/limites em cada passo, o custo de cada passo continua O(1) (checagens de limite), mantendo O(N) por sequência de N passos.

---

## ✅ Invariantes e Provas de Correção (Esboços)

### Iteração (FOR/WHILE/DO-WHILE)
- Invariante exemplo (Torre FOR): após i iterações, exatamente i movimentos "Direita" foram emitidos. A manutenção é trivial ao incrementar i e emitir um único movimento por iteração. Termina quando i = N, garantindo total de N emissões.

### Recursão (Torre/Bispo/Rainha)
- Especificação: `mover_X(N)` emite exatamente N movimentos do tipo X.
- Prova por indução:
	- Base: N = 0 → emite 0 movimentos; válido.
	- Passo: assuma válido para N-1. Para N>0, emite 1 movimento e chama `mover_X(N-1)`, que por hipótese emite N-1 movimentos. Total = N.

### Decomposição (Bispo por componentes)
- Invariante: para cada passo k de 0..N-1, são emitidos 1 movimento vertical e 1 horizontal, mantendo a equivalência ao vetor diagonal (+1,+1) por passo.

---

## 🧪 Medição Empírica vs. Análise Teórica

- A análise Big-O ignora constantes; já a execução real é dominada por I/O (`printf`).
- Para comparar implementações:
	- Desative a saída (redirecione para `/dev/null`) para medir overhead de controle de fluxo.
	- Use ferramentas: `time`, `hyperfine`, `gprof` (compilar com `-pg`), `valgrind` (sanidade de memória).

### Sugestão de Benchmark
- Varie N (p.ex., 10, 1.000, 100.000) em implementações parametrizadas.
- Compare:
	- Iteração vs. Recursão (mesmo N)
	- Com `printf` vs. acumulando em buffer e imprimindo 1 vez
	- `-O0` vs. `-O2`

---

## Conclusões

- Com valores constantes de passos, o projeto atual é O(1) em tempo e O(1) em espaço (exceto O(N) na pilha recursiva para as versões recursivas, com N pequeno).
- Em versões parametrizadas, todas as peças têm comportamento linear nos passos emitidos.
- A escolha entre recursão e iteração não altera a classe de complexidade temporal (ambas O(N)), mas altera o uso de espaço e overhead de chamadas.

---

### Referências Rápidas
- Cormen et al., Introduction to Algorithms
- Sedgewick & Wayne, Algorithms
- ISO/IEC 9899:2018 (C17)
- GCC Online Docs


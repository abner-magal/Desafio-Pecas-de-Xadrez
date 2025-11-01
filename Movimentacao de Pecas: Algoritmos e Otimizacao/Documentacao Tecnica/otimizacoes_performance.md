# 🚀 Otimizações e Performance

Este documento reúne técnicas para reduzir tempo de execução e overhead de I/O, além de orientar medições confiáveis. As sugestões respeitam o objetivo didático do projeto e priorizam clareza, mantendo a possibilidade de ativar níveis de otimização progressivamente.

---

## Sumário

- Estratégia de medição e baseline
- Otimizações de compilação (GCC)
- Otimizações de I/O (suavizar impacto dos `printf`)
- Micro-otimizações de controle de fluxo
- Recursão vs. iteração: custo e diretrizes
- Unrolling e inlining conscientes
- Validação: corretude, portabilidade e trade-offs

---

## 📏 Estratégia de Medição (Baseline)

1. Compile inicialmente com `-O0 -g -Wall -Wextra -std=c11` para obter um baseline e mensagens de diagnóstico confiáveis.
2. Meça com:
   - `time ./binario > /dev/null` (isola overhead de controle de fluxo ao descartar I/O)
   - `hyperfine` para benchmarks robustos (se disponível)
3. Ative gradualmente `-O2` e compare.
4. Para analisar hotpaths de CPU (sem I/O), providencie variantes que acumulam em buffer e imprimem uma única vez.

---

## 🛠️ Otimizações de Compilação (GCC)

- `-O2`: conjunto equilibrado de otimizações (recomendado)
- `-O3`: pode ajudar pouco em cenários CPU-bound, mas muitas vezes não supera o custo de I/O
- `-Ofast`: pode violar estrita conformidade; use apenas em builds experimentais
- `-march=native`: habilita instruções específicas da CPU local (menos portátil)
- `-flto` (Link Time Optimization): possível ganho em funções pequenas/inlining entre unidades de tradução
- `-fno-plt`/`-fno-semantic-interposition` (GCC recentes): reduzem overhead de chamadas dinâmicas (trade-off com dinamismo)

Sugestão de linha:
```
gcc -O2 -pipe -march=native -flto -std=c11 -Wall -Wextra arquivo.c -o exec
```

> Observação: em programas dominados por `printf`, o ganho de `-O3` vs `-O2` tende a ser marginal.

---

## 🖨️ Otimizações de I/O

### 1) Reduzir número de chamadas
- Em vez de emitir N `printf` de linhas curtas, acumule em um buffer e emita 1 chamada.
```c
char buf[2048]; size_t off = 0;
for (int i = 0; i < N; i++) off += (size_t)snprintf(buf+off, sizeof(buf)-off, "Direita\n");
fwrite(buf, 1, off, stdout);
```

### 2) Bufferização de stdout
- Garantir que `stdout` esteja em modo totalmente bufferizado em TTYs pode reduzir flushes.
```c
setvbuf(stdout, NULL, _IOFBF, 1<<16); // 64 KiB de buffer
```

### 3) Uso de `puts`/`fputs` quando adequado
- `puts("texto")` evita o custo de formatar strings (não imprime `%`), mas adiciona `\n` automaticamente.
- `fputs("texto\n", stdout)` é direto e evita parsing de formato do `printf`.

### 4) Saída opcional
- Para benchmarks de controle, permita desativar a impressão (ex.: macro `#ifdef NO_OUTPUT`).

---

## 🔁 Micro-otimizações de Controle de Fluxo

- Evite trabalho redundante no corpo de loops (p. ex., cálculos invariantes devem ficar fora do loop).
- Prefira contadores inteiros simples e comparações diretas (`i < N`).
- Use `continue`/`break` apenas quando simplificarem o fluxo; evite múltiplas condições encadeadas desnecessárias.
- Para loops muito curtos com N constante, o compilador pode desenrolá-los (unrolling). Em casos didáticos, evite unrolling manual que dificulte leitura.

Exemplo (eliminar branches redundantes):
```c
for (int i = 0; i < 5; i++) {
	// emitir movimento direto; nenhuma condição interna necessária
	puts("Direita");
}
```

---

## 🔃 Recursão vs. Iteração

- Tempo assintótico: ambos O(N) para “emitir N movimentos”.
- Overhead: recursão adiciona custo de chamada + frames de pilha; iteração tende a ser mais rápida e usar O(1) espaço.
- Diretriz: prefira recursão para clareza conceitual/ensino; prefira iteração para produção/performance quando N pode ser grande.

> TCO (Tail Call Optimization): não aplicável nas funções atuais por não serem tail-recursive.

---

## 📦 Unrolling e Inlining

- `static inline` em funções de movimento pequenas pode reduzir overhead de chamada quando utilizadas em laços apertados.
- Unrolling manual pode melhorar microperformance para N pequeno e fixo, porém prejudica clareza; avalie com benchmarks reais antes de adotar.

Exemplo de `inline` controlado:
```c
static inline void emit_dir(void) { fputs("Direita\n", stdout); }
for (int i = 0; i < N; i++) emit_dir();
```

---

## ✅ Validação, Corretude e Portabilidade

- Sempre compare a saída com a referência (scripts de validação por `diff`).
- Rode com `-fsanitize=address,undefined` durante o desenvolvimento.
- Verifique em ambientes distintos (Linux/macOS/WSL) e com locale diferente para evitar surpresas em I/O.

Checklist rápido:
- [ ] Saída idêntica à esperada
- [ ] Nenhum warning em `-Wall -Wextra`
- [ ] Sem UB em sanitizers
- [ ] Benchmarks reproduzíveis
- [ ] Comentários e doc atualizados

---

## Exemplos de Ganho Esperado (Guideline)

- “Muitos `printf` pequenos” → “1 `fwrite` grande”: grande redução de syscalls (melhora notável).
- `-O2` vs. `-O0`: ganhos modestos quando a carga é I/O-bound; maiores quando saída é suprimida.
- Iteração vs. Recursão para N elevado: menor uso de pilha e chamadas → melhora consistente.

> Meça sempre no seu hardware: cachê, SO e libc impactam os resultados.

---

### Referências Rápidas
- GCC Online Docs (otimizações e flags)
- man 3 printf/puts/fputs/fwrite
- “Algorithms” (Sedgewick & Wayne) – práticas de medição e experimentação


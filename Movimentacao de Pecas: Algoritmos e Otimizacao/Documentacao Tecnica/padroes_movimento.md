# ♟️ Padrões de Movimento e Modelagem

Este documento descreve padrões de movimento das peças, como modelá-los computacionalmente e como evoluir das emissões de texto do projeto para geradores gerais de movimentos com validação de limites e bloqueios.

---

## Sumário

- Representações: grade 8×8, vetores e direções
- Padrões por peça (Torre, Bispo, Rainha, Cavalo)
- Decomposição de movimentos e simetrias
- Geração genérica de movimentos (pseudocódigo)
- Checagens de limites e colisões
- Extensões: múltiplos passos, raios e obstruções

---

## 🧱 Representações

### Tabuleiro 8×8 (matricial)
```c
// (linha, coluna) com 0 ≤ linha, coluna < 8
// (0,0) ~ a1, (7,7) ~ h8
char board[8][8];
```

### Direções como vetores (dx, dy)
- Norte: (0, +1)
- Sul:   (0, -1)
- Leste: (+1, 0)
- Oeste: (-1, 0)
- NE:    (+1, +1)
- NO:    (-1, +1)
- SE:    (+1, -1)
- SO:    (-1, -1)

### Movimento em “L” (Cavalo)
Conjunto fixo de 8 deslocamentos:
```
(+2,+1), (+2,-1), (-2,+1), (-2,-1), (+1,+2), (+1,-2), (-1,+2), (-1,-2)
```

---

## 🏰 Torre (Rook)

### Padrão
- Raios ortogonais: N, S, L, O
- Anda até o fim do tabuleiro ou até obstrução.

### Pseudocódigo (gerador de raios)
```c
void push_line_moves(int x, int y, int dx, int dy) {
	int nx = x + dx, ny = y + dy;
	while (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
		add_move(nx, ny);
		// interromper se houver peça na casa (captura ou bloqueio)
		if (occupied(nx, ny)) break;
		nx += dx; ny += dy;
	}
}
```

### Direções aplicadas
```
push_line_moves(x, y, 0,+1); // N
push_line_moves(x, y, 0,-1); // S
push_line_moves(x, y,+1, 0); // L
push_line_moves(x, y,-1, 0); // O
```

---

## ⛪ Bispo (Bishop)

### Padrão
- Raios diagonais: NE, NO, SE, SO

### Pseudocódigo
```
push_line_moves(x, y,+1,+1); // NE
push_line_moves(x, y,-1,+1); // NO
push_line_moves(x, y,+1,-1); // SE
push_line_moves(x, y,-1,-1); // SO
```

### Decomposição (Projeto)
- Em alguns trechos, o movimento diagonal foi decomposto em vertical + horizontal por passo, útil para ensino de composição vetorial.

---

## 👑 Rainha (Queen)

### Padrão
- Combina Torre + Bispo (8 direções)

### Pseudocódigo
```
// ortogonais
push_line_moves(x, y, 0,+1);
push_line_moves(x, y, 0,-1);
push_line_moves(x, y,+1, 0);
push_line_moves(x, y,-1, 0);
// diagonais
push_line_moves(x, y,+1,+1);
push_line_moves(x, y,-1,+1);
push_line_moves(x, y,+1,-1);
push_line_moves(x, y,-1,-1);
```

---

## 🐴 Cavalo (Knight)

### Padrão
- Conjunto discreto de 8 deslocamentos; não é raio e ignora obstruções intermediárias (salta).

### Pseudocódigo
```c
const int KDX[8] = {+2,+2,-2,-2,+1,+1,-1,-1};
const int KDY[8] = {+1,-1,+1,-1,+2,-2,+2,-2};

void knight_moves(int x, int y) {
	for (int k = 0; k < 8; k++) {
		int nx = x + KDX[k];
		int ny = y + KDY[k];
		if (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
			add_move(nx, ny);
		}
	}
}
```

### Observações
- Única peça que “salta”; checagem de obstrução intermediária não se aplica.

---

## 🔄 Decomposição, Simetria e Rotação

- Muitos movimentos são versões rotacionadas/espelhadas de um vetor base.
- Estruturas de dados: listas de direções permitem iteração uniforme.

Exemplo (direções ortogonais):
```c
const int DX4[4] = { 0, 0,+1,-1};
const int DY4[4] = {+1,-1, 0, 0};
for (int d = 0; d < 4; d++) push_line_moves(x, y, DX4[d], DY4[d]);
```

---

## ✅ Checagens de Limite e Colisão

### Limites
```c
bool inside(int x, int y) { return 0 <= x && x < 8 && 0 <= y && y < 8; }
```

### Obstruções e Capturas
- Se a casa de destino estiver ocupada por peça aliada → bloquear sem adicionar.
- Se ocupada por adversária → adicionar (captura) e bloquear a continuação.
- Para Cavalo: ignorar caminho intermediário; testar apenas a casa de destino.

---

## 🧪 Pseudocódigo de Gerador Geral (Rainha)

```c
void gen_queen(int x, int y) {
	const int DX8[8] = { 0, 0,+1,-1,+1,-1,+1,-1};
	const int DY8[8] = {+1,-1, 0, 0,+1,+1,-1,-1};
	for (int d = 0; d < 8; d++) push_line_moves(x, y, DX8[d], DY8[d]);
}
```

---

## 🚀 Extensões e Parametrizações

- Número de passos máximo por direção (raio): 1..7 (tabuleiro 8×8).
- Parâmetro N: limitar o número de casas avançadas por direção.
- Tabuleiros de tamanho variável (n×n) → direções idênticas, limites mudam.
- Adição de regras: xeque, cravadas, pin, etc. (fora do escopo deste projeto tutorial).

---

## 🧩 Relação com o Projeto Atual

- O projeto imprime movimentos conceptuais (strings), ideal para ensino de estruturas de controle.
- O conteúdo acima mostra como evoluir para um “gerador de movimentos” real mantendo os padrões de controle (for, while, decomposição e recursão quando útil).

---

### Referências Rápidas
- Chess Programming Wiki (movimentos e gerações)
- Sedgewick & Wayne (estratégias de iteração)
- ISO C / GCC (detalhes de implementação e desempenho)


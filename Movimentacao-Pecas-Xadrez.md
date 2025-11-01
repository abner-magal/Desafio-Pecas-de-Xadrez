# Movimentação de Peças de Xadrez

## Documento de Especificação e Regras

Este documento descreve as regras de movimentação para cada peça no jogo de xadrez.

---

## 1. O TABULEIRO

O tabuleiro de xadrez consiste em 64 casas (8x8) alternando entre cores claras e escuras.

### Coordenadas
- **Colunas**: a, b, c, d, e, f, g, h (da esquerda para a direita)
- **Linhas**: 1, 2, 3, 4, 5, 6, 7, 8 (de baixo para cima para as brancas)

### Notação Algébrica
Cada casa é identificada por sua coluna e linha. Exemplos:
- `e4` - coluna 'e', linha 4
- `a1` - coluna 'a', linha 1 (canto inferior esquerdo das brancas)
- `h8` - coluna 'h', linha 8 (canto superior direito das brancas)

---

## 2. AS PEÇAS

Cada jogador começa com 16 peças:
- 1 Rei
- 1 Rainha (Dama)
- 2 Torres
- 2 Bispos
- 2 Cavalos
- 8 Peões

---

## 3. MOVIMENTAÇÃO DAS PEÇAS

### 3.1 PEÃO (♙ ♟)

**Símbolo**: P (na notação, geralmente omitido)

**Movimento Básico**:
- Move-se uma casa para frente em sua coluna
- **Nunca** pode mover-se para trás
- No primeiro movimento, pode avançar **duas casas**

**Captura**:
- Captura **diagonalmente** uma casa para frente
- Não pode capturar movendo-se para frente

**Movimentos Especiais**:

1. **En Passant** (À passagem):
   - Quando um peão adversário avança duas casas e para ao lado do seu peão
   - Você pode capturá-lo como se ele tivesse avançado apenas uma casa
   - Deve ser executado imediatamente após o avanço duplo do oponente

2. **Promoção**:
   - Quando um peão alcança a última linha (linha 8 para brancas, linha 1 para pretas)
   - Deve ser promovido a Rainha, Torre, Bispo ou Cavalo
   - Normalmente promovido a Rainha (peça mais poderosa)

**Exemplos de Movimentos**:
```
Posição inicial (e2):
- e2 → e3 (1 casa)
- e2 → e4 (2 casas - primeiro movimento)

Captura diagonal:
- Peão em e4, peça adversária em d5
- e4 → d5 (captura)
```

**Valor Relativo**: 1 ponto

---

### 3.2 CAVALO (♘ ♞)

**Símbolo**: N (do inglês kNight)

**Movimento**:
- Move-se em forma de **"L"**
- 2 casas em uma direção + 1 casa perpendicular
- OU 1 casa em uma direção + 2 casas perpendicular

**Características Especiais**:
- **Única peça que pode "pular" sobre outras peças**
- Sempre muda a cor da casa (de clara para escura ou vice-versa)

**Possíveis Movimentos**:
A partir de uma posição central (d4), o cavalo pode mover para 8 posições:
```
. . . . . . . .
. . c . c . . .
. b . . . b . .
. . . N . . . .
. b . . . b . .
. . c . c . . .
. . . . . . . .
. . . . . . . .

N = Cavalo
c = Movimento curto (1+2)
b = Movimento longo (2+1)
```

**Exemplos**:
- d4 → e6 (direita 1, cima 2)
- d4 → f5 (direita 2, cima 1)
- d4 → f3 (direita 2, baixo 1)
- d4 → e2 (direita 1, baixo 2)
- d4 → c2 (esquerda 1, baixo 2)
- d4 → b3 (esquerda 2, baixo 1)
- d4 → b5 (esquerda 2, cima 1)
- d4 → c6 (esquerda 1, cima 2)

**Valor Relativo**: 3 pontos

---

### 3.3 BISPO (♗ ♝)

**Símbolo**: B

**Movimento**:
- Move-se **diagonalmente** qualquer número de casas
- Não pode pular peças
- Sempre permanece na mesma cor de casa

**Direções**:
- 4 diagonais: nordeste, noroeste, sudeste, sudoeste

**Características**:
- Cada jogador tem um bispo de casas claras e um de casas escuras
- Trabalham bem em pares, cobrindo todas as casas

**Exemplos**:
```
Bispo em d4:
. . . . . . . X
. . . . . . X .
. . . . . X . .
X . . . X . . .
. . . B . . . .
. . X . X . . .
. X . . . X . .
X . . . . . X .

B = Bispo
X = Movimentos possíveis
```

**Valor Relativo**: 3 pontos

---

### 3.4 TORRE (♖ ♜)

**Símbolo**: R (do inglês Rook)

**Movimento**:
- Move-se **horizontal** ou **verticalmente** qualquer número de casas
- Não pode pular peças

**Direções**:
- 4 direções: norte, sul, leste, oeste

**Movimento Especial**:
- Participa do **Roque** com o Rei

**Exemplos**:
```
Torre em d4:
. . . X . . . .
. . . X . . . .
. . . X . . . .
. . . X . . . .
X X X R X X X X
. . . X . . . .
. . . X . . . .
. . . X . . . .

R = Torre
X = Movimentos possíveis
```

**Valor Relativo**: 5 pontos

---

### 3.5 RAINHA / DAMA (♕ ♛)

**Símbolo**: Q

**Movimento**:
- Combina os movimentos da **Torre** e do **Bispo**
- Move-se horizontal, vertical ou diagonalmente
- Qualquer número de casas
- Não pode pular peças

**Direções**:
- 8 direções: N, S, L, O, NE, NO, SE, SO

**Características**:
- **Peça mais poderosa** do jogo
- Geralmente vale mais que duas torres
- Deve ser usada com cuidado (não expor ao perigo)

**Exemplos**:
```
Rainha em d4:
. . . X . . . X
. . . X . . X .
. . . X . X . .
X . . X X . . .
X X X Q X X X X
. . X X . . . .
. X . X . . . .
X . . X . . . .

Q = Rainha
X = Movimentos possíveis (todas as 8 direções)
```

**Valor Relativo**: 9 pontos

---

### 3.6 REI (♔ ♚)

**Símbolo**: K

**Movimento**:
- Move-se **uma casa** em qualquer direção
- 8 possíveis posições (se não bloqueadas)

**Restrições Especiais**:
- **NUNCA pode se mover para uma casa atacada** (xeque)
- Não pode ficar adjacente ao rei adversário
- É a única peça que não pode ser capturada (o jogo termina antes)

**Movimento Especial - Roque**:

Condições para executar o roque:
1. Nem o Rei nem a Torre envolvida se moveram
2. Não há peças entre o Rei e a Torre
3. O Rei não está em xeque
4. O Rei não passa por casa atacada
5. O Rei não termina em casa atacada

**Tipos de Roque**:

1. **Roque Curto** (lado do rei):
   - Rei move 2 casas para a direita
   - Torre pula para o lado esquerdo do Rei
   - Notação: O-O
   - Brancas: e1 → g1, Torre h1 → f1
   - Pretas: e8 → g8, Torre h8 → f8

2. **Roque Longo** (lado da rainha):
   - Rei move 2 casas para a esquerda
   - Torre pula para o lado direito do Rei
   - Notação: O-O-O
   - Brancas: e1 → c1, Torre a1 → d1
   - Pretas: e8 → c8, Torre a8 → d8

**Exemplos**:
```
Rei em e1 (posição inicial):

Antes do roque curto:
. . . . K . . R

Depois do roque curto:
. . . . . R K .


Antes do roque longo:
R . . . K . . .

Depois do roque longo:
. . K R . . . .
```

**Valor**: Inestimável (perder o rei = perder o jogo)

---

## 4. CONCEITOS IMPORTANTES

### 4.1 Xeque

**Definição**: O Rei está sob ataque direto de uma peça adversária.

**Regras**:
- Quando em xeque, o jogador **DEVE** sair do xeque
- 3 maneiras de sair do xeque:
  1. Mover o Rei para uma casa segura
  2. Bloquear o ataque com outra peça
  3. Capturar a peça atacante

**Notação**: + (símbolo de xeque)

---

### 4.2 Xeque-Mate

**Definição**: O Rei está em xeque e não há movimento legal para sair.

**Consequência**: 
- **FIM DO JOGO**
- Vitória para o jogador que deu o xeque-mate

**Notação**: # ou ++ (símbolo de xeque-mate)

**Exemplo de Xeque-Mate Simples** (Pastor's Mate):
```
1. e4 e5
2. Bc4 Nc6
3. Qh5 Nf6?
4. Qxf7# (Xeque-mate!)

. . . . k . . .
. . . . . Q . .  ← Rainha dá xeque
. . n . . . . .
. . . . p . . .
. . B . P . . .
. . . . . . . .
. . . . . . . .
. . . . K . . .

Rei preto não pode:
- Capturar a Rainha (protegida pelo Bispo)
- Bloquear o ataque (não há peça)
- Mover para casa segura (todas atacadas)
```

---

### 4.3 Empate (Draw)

Situações que resultam em empate:

1. **Rei Afogado** (Stalemate):
   - Jogador não está em xeque
   - Mas não tem movimentos legais
   - Empate automático

2. **Material Insuficiente**:
   - Impossível dar xeque-mate com as peças restantes
   - Exemplos: Rei vs Rei, Rei+Bispo vs Rei

3. **Acordo Mútuo**:
   - Ambos os jogadores concordam com o empate

4. **Regra dos 50 Movimentos**:
   - 50 movimentos consecutivos sem captura ou movimento de peão

5. **Repetição Tripla**:
   - Mesma posição ocorre 3 vezes (não necessariamente consecutivas)

---

## 5. VALORES DAS PEÇAS

Sistema tradicional de pontos:

| Peça | Valor |
|------|-------|
| Peão | 1 |
| Cavalo | 3 |
| Bispo | 3 (ou 3.25) |
| Torre | 5 |
| Rainha | 9 |
| Rei | ∞ (inestimável) |

**Nota**: O Bispo é frequentemente considerado ligeiramente mais valioso que o Cavalo (3.25 vs 3) devido ao seu alcance em tabuleiro aberto.

---

## 6. PRINCÍPIOS BÁSICOS DE ABERTURA

1. **Controle o Centro**: e4, d4, e5, d5
2. **Desenvolva as Peças**: Cavalos e Bispos primeiro
3. **Proteja o Rei**: Roque cedo
4. **Não mova a mesma peça duas vezes** na abertura
5. **Não saque a Rainha cedo demais**

---

## 7. NOTAÇÃO DE MOVIMENTOS

### Notação Algébrica (padrão)

**Formato**: [Peça][casa de origem][x][casa de destino][+/#]

**Símbolos**:
- Peça: K(rei), Q(rainha), R(torre), B(bispo), N(cavalo), nada(peão)
- x: captura
- +: xeque
- #: xeque-mate
- O-O: roque curto
- O-O-O: roque longo
- =Q: promoção a rainha

**Exemplos**:
- `e4` - Peão para e4
- `Nf3` - Cavalo para f3
- `Bxe5` - Bispo captura em e5
- `Qh5+` - Rainha para h5 dando xeque
- `Nxf7#` - Cavalo captura em f7 dando xeque-mate
- `e8=Q` - Peão promovido a rainha em e8
- `O-O` - Roque curto

---

## 8. CONFIGURAÇÃO INICIAL

```
  a b c d e f g h
8 ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜  8  Linha das peças pretas
7 ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟  7  Linha dos peões pretos
6 . . . . . . . .  6
5 . . . . . . . .  5
4 . . . . . . . .  4
3 . . . . . . . .  3
2 ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙  2  Linha dos peões brancos
1 ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖  1  Linha das peças brancas
  a b c d e f g h
```

**Memorização**:
- Torres nos cantos (a1, h1, a8, h8)
- Cavalos ao lado das torres
- Bispos ao lado dos cavalos
- Rainha na sua cor (Rainha branca em casa clara - d1)
- Rei na casa restante (e1, e8)
- Peões na segunda linha (linha 2 para brancas, linha 7 para pretas)

---

## 9. REGRAS GERAIS

1. **Peça tocada, peça jogada**: Se tocar uma peça, deve movê-la
2. **Turno das brancas primeiro**: Brancas sempre começam
3. **Um movimento por vez**: Apenas uma peça pode ser movida (exceto roque)
4. **Captura**: Peça capturada é removida do tabuleiro
5. **Casa ocupada**: Não pode mover peça para casa ocupada por peça aliada
6. **Movimento legal**: Todo movimento deve ser legal segundo as regras

---

## 10. DICAS PARA INICIANTES

1. **Proteja suas peças**: Não deixe peças sem defesa
2. **Desenvolva com propósito**: Cada movimento deve ter um objetivo
3. **Pense antes de mover**: Considere as consequências
4. **Observe ameaças**: Tanto suas quanto do oponente
5. **Pratique táticas**: Garfo, cravada, raio-X, etc.
6. **Estude finais**: Rei+Peão, Rei+Torre são fundamentais
7. **Analise suas partidas**: Aprenda com os erros

---

## REFERÊNCIAS

- Regras Oficiais da FIDE (Federação Internacional de Xadrez)
- Manual de Xadrez - Princípios Básicos
- Notação Algébrica Padrão

---

**Documento preparado para**: Desafio Peças de Xadrez  
**Data**: 2025  
**Versão**: 1.0

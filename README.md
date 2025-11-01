# Desafio Peças de Xadrez ♔♕♖♗♘♙

Sistema completo de movimentação de peças de xadrez implementado em Python, com validação de movimentos, regras especiais e detecção de xeque.

## 📋 Descrição

Este projeto implementa um sistema de xadrez completo com:
- Todas as 6 tipos de peças (Peão, Cavalo, Bispo, Torre, Rainha, Rei)
- Validação de movimentos específicos para cada peça
- Tabuleiro 8x8 com coordenadas algébricas
- Detecção de xeque
- Verificação de caminho livre
- Sistema de turnos alternados
- Histórico de movimentos

## 🎯 Funcionalidades

### Peças Implementadas

| Peça | Símbolo | Movimentos |
|------|---------|------------|
| Peão (Pawn) | ♙♟ | Move 1 casa para frente (2 no primeiro movimento), captura diagonal |
| Cavalo (Knight) | ♘♞ | Move em "L" (2+1), pode pular peças |
| Bispo (Bishop) | ♗♝ | Move diagonalmente qualquer número de casas |
| Torre (Rook) | ♖♜ | Move horizontal ou verticalmente qualquer número de casas |
| Rainha (Queen) | ♕♛ | Combina movimentos de torre e bispo (8 direções) |
| Rei (King) | ♔♚ | Move 1 casa em qualquer direção |

### Validações
- ✅ Movimentos dentro dos limites do tabuleiro
- ✅ Movimentos válidos para cada tipo de peça
- ✅ Verificação de caminho livre (exceto cavalo)
- ✅ Prevenção de captura de peças da mesma cor
- ✅ Detecção de xeque ao rei
- ✅ Alternância de turnos

## 📁 Estrutura do Projeto

```
Desafio-Pecas-de-Xadrez/
├── README.md                 # Este arquivo
├── perplexity.md            # Análise profunda e detalhada do sistema
├── chess_piece.py           # Classes das peças de xadrez
├── chess_board.py           # Classe do tabuleiro e lógica do jogo
├── example.py               # Exemplos de uso e demonstrações
└── test_chess.py            # Testes unitários completos
```

## 🚀 Como Usar

### Requisitos
- Python 3.7+

### Execução Básica

```python
from chess_board import ChessBoard
from chess_piece import Position

# Criar e configurar tabuleiro
board = ChessBoard()
board.setup_initial_position()

# Exibir tabuleiro
board.display()

# Mover uma peça (notação algébrica)
start = Position.from_algebraic("e2")
end = Position.from_algebraic("e4")
board.move_piece(start, end)
```

### Executar Demonstração

```bash
python example.py
```

### Executar Testes

```bash
python test_chess.py
```

## 📖 Exemplos de Código

### Exemplo 1: Criar uma posição específica

```python
from chess_board import ChessBoard
from chess_piece import Pawn, Knight, Color, Position

board = ChessBoard()

# Adicionar peças manualmente
board.place_piece(Pawn(Color.WHITE, Position(3, 3)))
board.place_piece(Knight(Color.BLACK, Position(5, 4)))

board.display()
```

### Exemplo 2: Verificar movimentos possíveis

```python
from chess_board import ChessBoard
from chess_piece import Position

board = ChessBoard()
board.setup_initial_position()

# Obter peça
knight_pos = Position.from_algebraic("b1")
knight = board.get_piece_at(knight_pos)

# Listar movimentos possíveis
if knight:
    moves = knight.get_possible_moves(board)
    for move in moves:
        print(f"Pode mover para: {move.to_algebraic()}")
```

### Exemplo 3: Verificar xeque

```python
from chess_board import ChessBoard
from chess_piece import Color

board = ChessBoard()
board.setup_initial_position()

# Verificar se algum rei está em xeque
if board.is_in_check(Color.WHITE):
    print("Rei branco está em xeque!")

if board.is_in_check(Color.BLACK):
    print("Rei preto está em xeque!")
```

## 🧪 Testes

O projeto inclui testes abrangentes para:

- ✅ Criação e validação de posições
- ✅ Conversão de/para notação algébrica
- ✅ Movimentos básicos de cada peça
- ✅ Movimentos especiais do peão (avanço duplo, captura diagonal)
- ✅ Capacidade do cavalo de pular peças
- ✅ Bloqueio de caminho para peças de longo alcance
- ✅ Configuração inicial do tabuleiro
- ✅ Execução de movimentos
- ✅ Alternância de turnos
- ✅ Detecção de xeque

Execute os testes com:
```bash
python test_chess.py
```

## 📚 Documentação Detalhada

Para uma análise profunda do sistema, incluindo:
- Regras detalhadas de cada peça
- Complexidade computacional
- Padrões de projeto utilizados
- Considerações de design
- Melhorias futuras

Consulte o arquivo **[perplexity.md](perplexity.md)**.

## 🎓 Conceitos Implementados

### Programação Orientada a Objetos
- Herança (classe base `Piece` e subclasses específicas)
- Polimorfismo (método `can_move_to` implementado diferentemente para cada peça)
- Encapsulamento (atributos privados e métodos públicos)
- Abstração (interface comum para todas as peças)

### Estruturas de Dados
- Matriz 8x8 para representar o tabuleiro
- Enumerações para cores e tipos de peças
- Listas para histórico de movimentos

### Algoritmos
- Verificação de caminho livre (busca linear)
- Detecção de xeque (análise de ameaças)
- Validação de movimentos (regras específicas por peça)

## 🔄 Movimentos Especiais

### Implementados
- ✅ Avanço duplo do peão no primeiro movimento
- ✅ Captura diagonal do peão

### Planejados para implementação futura
- ⏳ En Passant
- ⏳ Promoção do peão
- ⏳ Roque (curto e longo)
- ⏳ Xeque-mate
- ⏳ Empate por rei afogado

## 🛠️ Tecnologias Utilizadas

- **Python 3.7+**: Linguagem de programação
- **unittest**: Framework de testes
- **Enum**: Para tipos e cores das peças
- **Type hints**: Para melhor documentação do código

## 📊 Estatísticas do Projeto

- **Linhas de código**: ~600+
- **Classes**: 10
- **Métodos**: 40+
- **Testes unitários**: 30+
- **Cobertura**: Todos os movimentos básicos das peças

## 🤝 Contribuindo

Contribuições são bem-vindas! Áreas para contribuir:
- Implementação de movimentos especiais (en passant, roque, promoção)
- Detecção de xeque-mate e empate
- Interface gráfica
- Motor de IA
- Notação PGN

## 📝 Licença

Este projeto é de código aberto e está disponível para fins educacionais.

## ✨ Autor

Desenvolvido como parte do Desafio de Peças de Xadrez.

## 🔗 Links Úteis

- [Regras oficiais do xadrez (FIDE)](https://www.fide.com/fide/handbook.html?id=208&view=article)
- [Notação algébrica](https://en.wikipedia.org/wiki/Algebraic_notation_(chess))
- [Chess Programming Wiki](https://www.chessprogramming.org/)

---

**Status do Projeto**: ✅ Funcional - Implementação base completa com todas as peças e validações principais.

Para dúvidas ou sugestões, abra uma issue no repositório!
"""
Exemplo de uso do sistema de xadrez
Demonstra os movimentos básicos das peças
"""

from chess_board import ChessBoard
from chess_piece import Position, Color


def main():
    """Função principal que demonstra o uso do sistema"""
    
    print("=" * 50)
    print("SISTEMA DE PEÇAS DE XADREZ")
    print("Demonstração de Movimentos")
    print("=" * 50)
    
    # Cria e configura o tabuleiro
    board = ChessBoard()
    board.setup_initial_position()
    
    print("\n1. POSIÇÃO INICIAL DO TABULEIRO:")
    board.display()
    
    # Demonstração de movimentos
    moves = [
        ("e2", "e4", "Peão branco avança 2 casas (abertura)"),
        ("e7", "e5", "Peão preto avança 2 casas"),
        ("g1", "f3", "Cavalo branco se desenvolve"),
        ("b8", "c6", "Cavalo preto se desenvolve"),
        ("f1", "c4", "Bispo branco (abertura italiana)"),
        ("f8", "c5", "Bispo preto se desenvolve"),
    ]
    
    print("\n2. SEQUÊNCIA DE MOVIMENTOS:")
    print("-" * 50)
    
    for i, (start_notation, end_notation, description) in enumerate(moves, 1):
        start = Position.from_algebraic(start_notation)
        end = Position.from_algebraic(end_notation)
        
        piece = board.get_piece_at(start)
        if piece:
            piece_name = piece.__class__.__name__
            color = piece.color.value
            print(f"\nMovimento {i}: {description}")
            print(f"  {color.capitalize()} {piece_name}: {start_notation} → {end_notation}")
            
            if board.move_piece(start, end):
                print(f"  ✓ Movimento executado com sucesso")
            else:
                print(f"  ✗ Movimento inválido")
            
            board.display()
    
    # Demonstração de movimentos possíveis
    print("\n3. MOVIMENTOS POSSÍVEIS:")
    print("-" * 50)
    
    # Testa movimentos possíveis de um cavalo
    knight_pos = Position.from_algebraic("f3")
    knight = board.get_piece_at(knight_pos)
    
    if knight:
        print(f"\nMovimentos possíveis para {knight}:")
        possible_moves = knight.get_possible_moves(board)
        moves_notation = [pos.to_algebraic() for pos in possible_moves]
        print(f"  Posições: {', '.join(sorted(moves_notation))}")
    
    # Demonstração de verificação de xeque
    print("\n4. VERIFICAÇÃO DE XEQUE:")
    print("-" * 50)
    
    for color in [Color.WHITE, Color.BLACK]:
        is_check = board.is_in_check(color)
        king_pos = board.find_king(color)
        status = "EM XEQUE!" if is_check else "Seguro"
        print(f"  Rei {color.value}: {king_pos.to_algebraic() if king_pos else 'não encontrado'} - {status}")
    
    # Estatísticas do jogo
    print("\n5. ESTATÍSTICAS:")
    print("-" * 50)
    
    white_pieces = board.get_all_pieces(Color.WHITE)
    black_pieces = board.get_all_pieces(Color.BLACK)
    
    print(f"  Peças brancas: {len(white_pieces)}")
    print(f"  Peças pretas: {len(black_pieces)}")
    print(f"  Total de movimentos: {len(board.move_history)}")
    print(f"  Turno atual: {board.current_turn.value.capitalize()}")
    
    # Demonstração de movimentos especiais do peão
    print("\n6. EXEMPLO: CAPTURA DIAGONAL DO PEÃO")
    print("-" * 50)
    
    # Cria um novo tabuleiro para demonstrar captura
    demo_board = ChessBoard()
    
    # Configura uma situação específica
    from chess_piece import Pawn, Knight
    
    demo_board.place_piece(Pawn(Color.WHITE, Position(4, 4)))  # e5
    demo_board.place_piece(Knight(Color.BLACK, Position(5, 5)))  # f6
    
    print("\nSituação: Peão branco em e5, Cavalo preto em f6")
    demo_board.display()
    
    pawn_pos = Position.from_algebraic("e5")
    capture_pos = Position.from_algebraic("f6")
    
    pawn = demo_board.get_piece_at(pawn_pos)
    if pawn and pawn.can_move_to(capture_pos, demo_board):
        print("✓ Peão pode capturar o cavalo em f6 (movimento diagonal)")
    else:
        print("✗ Movimento inválido")
    
    # Demonstração de movimento da rainha
    print("\n7. EXEMPLO: PODER DA RAINHA")
    print("-" * 50)
    
    queen_board = ChessBoard()
    from chess_piece import Queen
    
    queen_pos = Position(3, 3)  # d4
    queen_board.place_piece(Queen(Color.WHITE, queen_pos))
    
    print("\nRainha branca em d4 (tabuleiro vazio)")
    queen_board.display()
    
    queen = queen_board.get_piece_at(queen_pos)
    possible_moves = queen.get_possible_moves(queen_board)
    
    print(f"Movimentos possíveis: {len(possible_moves)}")
    print("A rainha pode se mover para:")
    
    # Agrupa movimentos por direção
    directions = {
        'Norte': [],
        'Sul': [],
        'Leste': [],
        'Oeste': [],
        'Nordeste': [],
        'Noroeste': [],
        'Sudeste': [],
        'Sudoeste': []
    }
    
    for pos in possible_moves:
        row_diff = pos.row - queen_pos.row
        col_diff = pos.col - queen_pos.col
        
        if row_diff > 0 and col_diff == 0:
            directions['Norte'].append(pos.to_algebraic())
        elif row_diff < 0 and col_diff == 0:
            directions['Sul'].append(pos.to_algebraic())
        elif row_diff == 0 and col_diff > 0:
            directions['Leste'].append(pos.to_algebraic())
        elif row_diff == 0 and col_diff < 0:
            directions['Oeste'].append(pos.to_algebraic())
        elif row_diff > 0 and col_diff > 0:
            directions['Nordeste'].append(pos.to_algebraic())
        elif row_diff > 0 and col_diff < 0:
            directions['Noroeste'].append(pos.to_algebraic())
        elif row_diff < 0 and col_diff > 0:
            directions['Sudeste'].append(pos.to_algebraic())
        elif row_diff < 0 and col_diff < 0:
            directions['Sudoeste'].append(pos.to_algebraic())
    
    for direction, moves in directions.items():
        if moves:
            print(f"  {direction}: {', '.join(moves)}")
    
    print("\n" + "=" * 50)
    print("DEMONSTRAÇÃO CONCLUÍDA")
    print("=" * 50)


if __name__ == "__main__":
    main()

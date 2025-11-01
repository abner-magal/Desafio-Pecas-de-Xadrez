"""
Testes unitários para o sistema de xadrez
"""

import unittest
from chess_piece import (
    Piece, Pawn, Knight, Bishop, Rook, Queen, King,
    Position, Color, PieceType
)
from chess_board import ChessBoard


class TestPosition(unittest.TestCase):
    """Testes para a classe Position"""
    
    def test_position_creation(self):
        """Testa criação de posição"""
        pos = Position(0, 0)
        self.assertEqual(pos.row, 0)
        self.assertEqual(pos.col, 0)
    
    def test_position_validity(self):
        """Testa validação de posições"""
        self.assertTrue(Position(0, 0).is_valid())
        self.assertTrue(Position(7, 7).is_valid())
        self.assertFalse(Position(-1, 0).is_valid())
        self.assertFalse(Position(0, 8).is_valid())
        self.assertFalse(Position(8, 0).is_valid())
    
    def test_algebraic_notation(self):
        """Testa conversão para notação algébrica"""
        self.assertEqual(Position(0, 0).to_algebraic(), "a1")
        self.assertEqual(Position(7, 7).to_algebraic(), "h8")
        self.assertEqual(Position(3, 4).to_algebraic(), "e4")
    
    def test_from_algebraic(self):
        """Testa criação a partir de notação algébrica"""
        pos = Position.from_algebraic("e4")
        self.assertEqual(pos.row, 3)
        self.assertEqual(pos.col, 4)
    
    def test_position_equality(self):
        """Testa comparação de posições"""
        pos1 = Position(3, 4)
        pos2 = Position(3, 4)
        pos3 = Position(4, 3)
        self.assertEqual(pos1, pos2)
        self.assertNotEqual(pos1, pos3)


class TestPawn(unittest.TestCase):
    """Testes para a classe Pawn"""
    
    def setUp(self):
        """Configura um tabuleiro para testes"""
        self.board = ChessBoard()
    
    def test_pawn_forward_one(self):
        """Testa movimento de 1 casa para frente"""
        pawn = Pawn(Color.WHITE, Position(1, 4))
        self.board.place_piece(pawn)
        
        self.assertTrue(pawn.can_move_to(Position(2, 4), self.board))
    
    def test_pawn_forward_two_initial(self):
        """Testa movimento inicial de 2 casas"""
        pawn = Pawn(Color.WHITE, Position(1, 4))
        self.board.place_piece(pawn)
        
        self.assertTrue(pawn.can_move_to(Position(3, 4), self.board))
    
    def test_pawn_forward_two_after_move(self):
        """Testa que peão não pode mover 2 casas após o primeiro movimento"""
        pawn = Pawn(Color.WHITE, Position(2, 4))
        pawn.has_moved = True
        self.board.place_piece(pawn)
        
        self.assertFalse(pawn.can_move_to(Position(4, 4), self.board))
    
    def test_pawn_diagonal_capture(self):
        """Testa captura diagonal"""
        pawn = Pawn(Color.WHITE, Position(4, 4))
        enemy = Pawn(Color.BLACK, Position(5, 5))
        self.board.place_piece(pawn)
        self.board.place_piece(enemy)
        
        self.assertTrue(pawn.can_move_to(Position(5, 5), self.board))
    
    def test_pawn_cannot_capture_forward(self):
        """Testa que peão não pode capturar para frente"""
        pawn = Pawn(Color.WHITE, Position(4, 4))
        enemy = Pawn(Color.BLACK, Position(5, 4))
        self.board.place_piece(pawn)
        self.board.place_piece(enemy)
        
        self.assertFalse(pawn.can_move_to(Position(5, 4), self.board))
    
    def test_pawn_black_direction(self):
        """Testa movimento do peão preto (direção oposta)"""
        pawn = Pawn(Color.BLACK, Position(6, 4))
        self.board.place_piece(pawn)
        
        self.assertTrue(pawn.can_move_to(Position(5, 4), self.board))
        self.assertTrue(pawn.can_move_to(Position(4, 4), self.board))


class TestKnight(unittest.TestCase):
    """Testes para a classe Knight"""
    
    def setUp(self):
        """Configura um tabuleiro para testes"""
        self.board = ChessBoard()
    
    def test_knight_l_moves(self):
        """Testa movimentos em L do cavalo"""
        knight = Knight(Color.WHITE, Position(3, 3))
        self.board.place_piece(knight)
        
        # Testa todos os 8 movimentos possíveis em L
        valid_moves = [
            Position(5, 4), Position(5, 2),  # +2 linha
            Position(1, 4), Position(1, 2),  # -2 linha
            Position(4, 5), Position(2, 5),  # +2 coluna
            Position(4, 1), Position(2, 1),  # -2 coluna
        ]
        
        for move in valid_moves:
            self.assertTrue(knight.can_move_to(move, self.board),
                          f"Cavalo deveria poder mover para {move}")
    
    def test_knight_invalid_moves(self):
        """Testa movimentos inválidos do cavalo"""
        knight = Knight(Color.WHITE, Position(3, 3))
        self.board.place_piece(knight)
        
        # Movimentos que não são em L
        invalid_moves = [
            Position(4, 4),  # Diagonal
            Position(3, 4),  # Horizontal
            Position(4, 3),  # Vertical
        ]
        
        for move in invalid_moves:
            self.assertFalse(knight.can_move_to(move, self.board))
    
    def test_knight_can_jump(self):
        """Testa que cavalo pode pular outras peças"""
        knight = Knight(Color.WHITE, Position(3, 3))
        blocker = Pawn(Color.WHITE, Position(4, 3))
        self.board.place_piece(knight)
        self.board.place_piece(blocker)
        
        # Cavalo ainda pode mover mesmo com bloqueio
        self.assertTrue(knight.can_move_to(Position(5, 4), self.board))


class TestBishop(unittest.TestCase):
    """Testes para a classe Bishop"""
    
    def setUp(self):
        """Configura um tabuleiro para testes"""
        self.board = ChessBoard()
    
    def test_bishop_diagonal_moves(self):
        """Testa movimentos diagonais do bispo"""
        bishop = Bishop(Color.WHITE, Position(3, 3))
        self.board.place_piece(bishop)
        
        # Testa diagonais
        self.assertTrue(bishop.can_move_to(Position(5, 5), self.board))
        self.assertTrue(bishop.can_move_to(Position(1, 1), self.board))
        self.assertTrue(bishop.can_move_to(Position(6, 0), self.board))
        self.assertTrue(bishop.can_move_to(Position(0, 6), self.board))
    
    def test_bishop_blocked_path(self):
        """Testa que bispo não pode pular peças"""
        bishop = Bishop(Color.WHITE, Position(3, 3))
        blocker = Pawn(Color.WHITE, Position(4, 4))
        self.board.place_piece(bishop)
        self.board.place_piece(blocker)
        
        self.assertFalse(bishop.can_move_to(Position(5, 5), self.board))
    
    def test_bishop_invalid_moves(self):
        """Testa movimentos não diagonais"""
        bishop = Bishop(Color.WHITE, Position(3, 3))
        self.board.place_piece(bishop)
        
        self.assertFalse(bishop.can_move_to(Position(3, 5), self.board))  # Horizontal
        self.assertFalse(bishop.can_move_to(Position(5, 3), self.board))  # Vertical


class TestRook(unittest.TestCase):
    """Testes para a classe Rook"""
    
    def setUp(self):
        """Configura um tabuleiro para testes"""
        self.board = ChessBoard()
    
    def test_rook_straight_moves(self):
        """Testa movimentos retos da torre"""
        rook = Rook(Color.WHITE, Position(3, 3))
        self.board.place_piece(rook)
        
        # Horizontal e vertical
        self.assertTrue(rook.can_move_to(Position(3, 7), self.board))
        self.assertTrue(rook.can_move_to(Position(3, 0), self.board))
        self.assertTrue(rook.can_move_to(Position(7, 3), self.board))
        self.assertTrue(rook.can_move_to(Position(0, 3), self.board))
    
    def test_rook_blocked_path(self):
        """Testa que torre não pode pular peças"""
        rook = Rook(Color.WHITE, Position(3, 3))
        blocker = Pawn(Color.WHITE, Position(3, 5))
        self.board.place_piece(rook)
        self.board.place_piece(blocker)
        
        self.assertFalse(rook.can_move_to(Position(3, 7), self.board))
    
    def test_rook_invalid_moves(self):
        """Testa movimentos diagonais (inválidos para torre)"""
        rook = Rook(Color.WHITE, Position(3, 3))
        self.board.place_piece(rook)
        
        self.assertFalse(rook.can_move_to(Position(5, 5), self.board))


class TestQueen(unittest.TestCase):
    """Testes para a classe Queen"""
    
    def setUp(self):
        """Configura um tabuleiro para testes"""
        self.board = ChessBoard()
    
    def test_queen_all_directions(self):
        """Testa movimentos em todas as direções"""
        queen = Queen(Color.WHITE, Position(3, 3))
        self.board.place_piece(queen)
        
        # Horizontal, vertical e diagonais
        moves = [
            Position(3, 7),  # Horizontal direita
            Position(3, 0),  # Horizontal esquerda
            Position(7, 3),  # Vertical cima
            Position(0, 3),  # Vertical baixo
            Position(5, 5),  # Diagonal
            Position(1, 1),  # Diagonal
            Position(6, 0),  # Diagonal
            Position(0, 6),  # Diagonal
        ]
        
        for move in moves:
            self.assertTrue(queen.can_move_to(move, self.board),
                          f"Rainha deveria poder mover para {move}")


class TestKing(unittest.TestCase):
    """Testes para a classe King"""
    
    def setUp(self):
        """Configura um tabuleiro para testes"""
        self.board = ChessBoard()
    
    def test_king_one_square(self):
        """Testa movimento de 1 casa em qualquer direção"""
        king = King(Color.WHITE, Position(3, 3))
        self.board.place_piece(king)
        
        # 8 posições adjacentes
        adjacent = [
            Position(4, 3), Position(2, 3),  # Vertical
            Position(3, 4), Position(3, 2),  # Horizontal
            Position(4, 4), Position(2, 2),  # Diagonais
            Position(4, 2), Position(2, 4),
        ]
        
        for pos in adjacent:
            self.assertTrue(king.can_move_to(pos, self.board))
    
    def test_king_cannot_move_far(self):
        """Testa que rei não pode mover mais de 1 casa"""
        king = King(Color.WHITE, Position(3, 3))
        self.board.place_piece(king)
        
        self.assertFalse(king.can_move_to(Position(5, 3), self.board))
        self.assertFalse(king.can_move_to(Position(3, 5), self.board))


class TestChessBoard(unittest.TestCase):
    """Testes para a classe ChessBoard"""
    
    def test_initial_setup(self):
        """Testa configuração inicial do tabuleiro"""
        board = ChessBoard()
        board.setup_initial_position()
        
        # Verifica peões
        for col in range(8):
            piece = board.get_piece_at(Position(1, col))
            self.assertIsInstance(piece, Pawn)
            self.assertEqual(piece.color, Color.WHITE)
            
            piece = board.get_piece_at(Position(6, col))
            self.assertIsInstance(piece, Pawn)
            self.assertEqual(piece.color, Color.BLACK)
        
        # Verifica que o centro está vazio
        self.assertIsNone(board.get_piece_at(Position(3, 3)))
        self.assertIsNone(board.get_piece_at(Position(4, 4)))
    
    def test_move_piece(self):
        """Testa movimento de peça"""
        board = ChessBoard()
        board.setup_initial_position()
        
        # Move peão branco
        start = Position.from_algebraic("e2")
        end = Position.from_algebraic("e4")
        
        self.assertTrue(board.move_piece(start, end))
        self.assertIsNone(board.get_piece_at(start))
        self.assertIsNotNone(board.get_piece_at(end))
    
    def test_turn_alternation(self):
        """Testa alternância de turnos"""
        board = ChessBoard()
        board.setup_initial_position()
        
        self.assertEqual(board.current_turn, Color.WHITE)
        
        board.move_piece(Position.from_algebraic("e2"), 
                        Position.from_algebraic("e4"))
        self.assertEqual(board.current_turn, Color.BLACK)
        
        board.move_piece(Position.from_algebraic("e7"), 
                        Position.from_algebraic("e5"))
        self.assertEqual(board.current_turn, Color.WHITE)
    
    def test_is_path_clear(self):
        """Testa verificação de caminho livre"""
        board = ChessBoard()
        board.place_piece(Rook(Color.WHITE, Position(0, 0)))
        board.place_piece(Pawn(Color.WHITE, Position(0, 3)))
        
        # Caminho livre até o peão
        self.assertTrue(board.is_path_clear(Position(0, 0), Position(0, 2)))
        
        # Caminho bloqueado pelo peão
        self.assertFalse(board.is_path_clear(Position(0, 0), Position(0, 4)))
    
    def test_find_king(self):
        """Testa localização do rei"""
        board = ChessBoard()
        board.setup_initial_position()
        
        white_king_pos = board.find_king(Color.WHITE)
        self.assertIsNotNone(white_king_pos)
        self.assertEqual(white_king_pos.to_algebraic(), "e1")
        
        black_king_pos = board.find_king(Color.BLACK)
        self.assertIsNotNone(black_king_pos)
        self.assertEqual(black_king_pos.to_algebraic(), "e8")


def run_tests():
    """Executa todos os testes"""
    unittest.main(argv=[''], verbosity=2, exit=False)


if __name__ == '__main__':
    run_tests()

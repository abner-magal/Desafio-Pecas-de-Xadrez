"""
Sistema de Peças de Xadrez
Implementação das classes base para o sistema de xadrez
"""

from enum import Enum
from typing import List, Tuple, Optional


class Color(Enum):
    """Cores das peças"""
    WHITE = "white"
    BLACK = "black"


class PieceType(Enum):
    """Tipos de peças de xadrez"""
    PAWN = "pawn"
    KNIGHT = "knight"
    BISHOP = "bishop"
    ROOK = "rook"
    QUEEN = "queen"
    KING = "king"


class Position:
    """Representa uma posição no tabuleiro"""
    
    def __init__(self, row: int, col: int):
        """
        Inicializa uma posição
        
        Args:
            row: Linha (0-7)
            col: Coluna (0-7)
        """
        self.row = row
        self.col = col
    
    def is_valid(self) -> bool:
        """Verifica se a posição está dentro dos limites do tabuleiro"""
        return 0 <= self.row <= 7 and 0 <= self.col <= 7
    
    def to_algebraic(self) -> str:
        """Converte para notação algébrica (ex: e4)"""
        if not self.is_valid():
            return "invalid"
        files = "abcdefgh"
        return f"{files[self.col]}{self.row + 1}"
    
    @classmethod
    def from_algebraic(cls, notation: str) -> 'Position':
        """
        Cria posição a partir de notação algébrica
        
        Args:
            notation: Notação algébrica (ex: "e4")
        
        Returns:
            Objeto Position
        """
        files = "abcdefgh"
        col = files.index(notation[0].lower())
        row = int(notation[1]) - 1
        return cls(row, col)
    
    def __eq__(self, other) -> bool:
        """Compara duas posições"""
        if not isinstance(other, Position):
            return False
        return self.row == other.row and self.col == other.col
    
    def __str__(self) -> str:
        return self.to_algebraic()
    
    def __repr__(self) -> str:
        return f"Position({self.row}, {self.col})"


class Piece:
    """Classe base abstrata para todas as peças de xadrez"""
    
    def __init__(self, color: Color, position: Position):
        """
        Inicializa uma peça
        
        Args:
            color: Cor da peça (WHITE ou BLACK)
            position: Posição inicial da peça
        """
        self.color = color
        self.position = position
        self.has_moved = False
        self.piece_type = None
    
    def get_symbol(self) -> str:
        """Retorna o símbolo Unicode da peça"""
        symbols = {
            (Color.WHITE, PieceType.PAWN): "♙",
            (Color.WHITE, PieceType.KNIGHT): "♘",
            (Color.WHITE, PieceType.BISHOP): "♗",
            (Color.WHITE, PieceType.ROOK): "♖",
            (Color.WHITE, PieceType.QUEEN): "♕",
            (Color.WHITE, PieceType.KING): "♔",
            (Color.BLACK, PieceType.PAWN): "♟",
            (Color.BLACK, PieceType.KNIGHT): "♞",
            (Color.BLACK, PieceType.BISHOP): "♝",
            (Color.BLACK, PieceType.ROOK): "♜",
            (Color.BLACK, PieceType.QUEEN): "♛",
            (Color.BLACK, PieceType.KING): "♚",
        }
        return symbols.get((self.color, self.piece_type), "?")
    
    def can_move_to(self, target: Position, board: 'ChessBoard') -> bool:
        """
        Verifica se a peça pode se mover para a posição alvo
        
        Args:
            target: Posição de destino
            board: Tabuleiro atual
        
        Returns:
            True se o movimento é válido
        """
        raise NotImplementedError("Subclasses devem implementar can_move_to")
    
    def get_possible_moves(self, board: 'ChessBoard') -> List[Position]:
        """
        Retorna todas as posições possíveis para onde a peça pode se mover
        
        Args:
            board: Tabuleiro atual
        
        Returns:
            Lista de posições válidas
        """
        possible_moves = []
        for row in range(8):
            for col in range(8):
                target = Position(row, col)
                if self.can_move_to(target, board):
                    possible_moves.append(target)
        return possible_moves
    
    def __str__(self) -> str:
        return f"{self.color.value.capitalize()} {self.piece_type.value if self.piece_type else 'Unknown'} at {self.position}"
    
    def __repr__(self) -> str:
        return f"{self.__class__.__name__}({self.color}, {self.position})"


class Pawn(Piece):
    """Peão - move-se para frente, captura na diagonal"""
    
    def __init__(self, color: Color, position: Position):
        super().__init__(color, position)
        self.piece_type = PieceType.PAWN
    
    def can_move_to(self, target: Position, board: 'ChessBoard') -> bool:
        """Valida movimento do peão"""
        if not target.is_valid():
            return False
        
        if target == self.position:
            return False
        
        direction = 1 if self.color == Color.WHITE else -1
        start_row = 1 if self.color == Color.WHITE else 6
        
        row_diff = target.row - self.position.row
        col_diff = abs(target.col - self.position.col)
        
        # Movimento para frente (1 casa)
        if row_diff == direction and col_diff == 0:
            return board.get_piece_at(target) is None
        
        # Movimento inicial (2 casas)
        if row_diff == 2 * direction and col_diff == 0 and self.position.row == start_row:
            intermediate = Position(self.position.row + direction, self.position.col)
            return (board.get_piece_at(target) is None and 
                    board.get_piece_at(intermediate) is None)
        
        # Captura diagonal
        if row_diff == direction and col_diff == 1:
            target_piece = board.get_piece_at(target)
            return target_piece is not None and target_piece.color != self.color
        
        return False


class Knight(Piece):
    """Cavalo - move-se em L"""
    
    def __init__(self, color: Color, position: Position):
        super().__init__(color, position)
        self.piece_type = PieceType.KNIGHT
    
    def can_move_to(self, target: Position, board: 'ChessBoard') -> bool:
        """Valida movimento do cavalo"""
        if not target.is_valid():
            return False
        
        if target == self.position:
            return False
        
        row_diff = abs(target.row - self.position.row)
        col_diff = abs(target.col - self.position.col)
        
        # Movimento em L: (2,1) ou (1,2)
        is_l_move = (row_diff == 2 and col_diff == 1) or (row_diff == 1 and col_diff == 2)
        
        if not is_l_move:
            return False
        
        # Verifica se a casa de destino não tem peça da mesma cor
        target_piece = board.get_piece_at(target)
        return target_piece is None or target_piece.color != self.color


class Bishop(Piece):
    """Bispo - move-se diagonalmente"""
    
    def __init__(self, color: Color, position: Position):
        super().__init__(color, position)
        self.piece_type = PieceType.BISHOP
    
    def can_move_to(self, target: Position, board: 'ChessBoard') -> bool:
        """Valida movimento do bispo"""
        if not target.is_valid():
            return False
        
        if target == self.position:
            return False
        
        row_diff = abs(target.row - self.position.row)
        col_diff = abs(target.col - self.position.col)
        
        # Movimento diagonal
        if row_diff != col_diff:
            return False
        
        # Verifica se o caminho está livre
        if not board.is_path_clear(self.position, target):
            return False
        
        # Verifica se a casa de destino não tem peça da mesma cor
        target_piece = board.get_piece_at(target)
        return target_piece is None or target_piece.color != self.color


class Rook(Piece):
    """Torre - move-se horizontal ou verticalmente"""
    
    def __init__(self, color: Color, position: Position):
        super().__init__(color, position)
        self.piece_type = PieceType.ROOK
    
    def can_move_to(self, target: Position, board: 'ChessBoard') -> bool:
        """Valida movimento da torre"""
        if not target.is_valid():
            return False
        
        if target == self.position:
            return False
        
        # Movimento horizontal ou vertical
        is_horizontal = target.row == self.position.row
        is_vertical = target.col == self.position.col
        
        if not (is_horizontal or is_vertical):
            return False
        
        # Verifica se o caminho está livre
        if not board.is_path_clear(self.position, target):
            return False
        
        # Verifica se a casa de destino não tem peça da mesma cor
        target_piece = board.get_piece_at(target)
        return target_piece is None or target_piece.color != self.color


class Queen(Piece):
    """Rainha - move-se como torre + bispo"""
    
    def __init__(self, color: Color, position: Position):
        super().__init__(color, position)
        self.piece_type = PieceType.QUEEN
    
    def can_move_to(self, target: Position, board: 'ChessBoard') -> bool:
        """Valida movimento da rainha"""
        if not target.is_valid():
            return False
        
        if target == self.position:
            return False
        
        row_diff = abs(target.row - self.position.row)
        col_diff = abs(target.col - self.position.col)
        
        # Movimento diagonal (como bispo)
        is_diagonal = row_diff == col_diff and row_diff > 0
        
        # Movimento horizontal ou vertical (como torre)
        is_straight = (target.row == self.position.row or 
                      target.col == self.position.col)
        
        if not (is_diagonal or is_straight):
            return False
        
        # Verifica se o caminho está livre
        if not board.is_path_clear(self.position, target):
            return False
        
        # Verifica se a casa de destino não tem peça da mesma cor
        target_piece = board.get_piece_at(target)
        return target_piece is None or target_piece.color != self.color


class King(Piece):
    """Rei - move-se 1 casa em qualquer direção"""
    
    def __init__(self, color: Color, position: Position):
        super().__init__(color, position)
        self.piece_type = PieceType.KING
    
    def can_move_to(self, target: Position, board: 'ChessBoard') -> bool:
        """Valida movimento do rei"""
        if not target.is_valid():
            return False
        
        if target == self.position:
            return False
        
        row_diff = abs(target.row - self.position.row)
        col_diff = abs(target.col - self.position.col)
        
        # Movimento de 1 casa em qualquer direção
        if row_diff > 1 or col_diff > 1:
            return False
        
        # Verifica se a casa de destino não tem peça da mesma cor
        target_piece = board.get_piece_at(target)
        return target_piece is None or target_piece.color != self.color

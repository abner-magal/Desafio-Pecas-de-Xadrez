"""
Tabuleiro de Xadrez
Implementação do tabuleiro e gerenciamento do jogo
"""

from typing import Optional, List
from chess_piece import (
    Piece, Pawn, Knight, Bishop, Rook, Queen, King,
    Position, Color, PieceType
)


class ChessBoard:
    """Representa o tabuleiro de xadrez e gerencia o estado do jogo"""
    
    def __init__(self):
        """Inicializa um tabuleiro vazio"""
        self.board = [[None for _ in range(8)] for _ in range(8)]
        self.current_turn = Color.WHITE
        self.move_history = []
    
    def setup_initial_position(self):
        """Configura a posição inicial padrão do xadrez"""
        # Peões brancos
        for col in range(8):
            self.place_piece(Pawn(Color.WHITE, Position(1, col)))
        
        # Peões pretos
        for col in range(8):
            self.place_piece(Pawn(Color.BLACK, Position(6, col)))
        
        # Peças brancas
        self.place_piece(Rook(Color.WHITE, Position(0, 0)))
        self.place_piece(Knight(Color.WHITE, Position(0, 1)))
        self.place_piece(Bishop(Color.WHITE, Position(0, 2)))
        self.place_piece(Queen(Color.WHITE, Position(0, 3)))
        self.place_piece(King(Color.WHITE, Position(0, 4)))
        self.place_piece(Bishop(Color.WHITE, Position(0, 5)))
        self.place_piece(Knight(Color.WHITE, Position(0, 6)))
        self.place_piece(Rook(Color.WHITE, Position(0, 7)))
        
        # Peças pretas
        self.place_piece(Rook(Color.BLACK, Position(7, 0)))
        self.place_piece(Knight(Color.BLACK, Position(7, 1)))
        self.place_piece(Bishop(Color.BLACK, Position(7, 2)))
        self.place_piece(Queen(Color.BLACK, Position(7, 3)))
        self.place_piece(King(Color.BLACK, Position(7, 4)))
        self.place_piece(Bishop(Color.BLACK, Position(7, 5)))
        self.place_piece(Knight(Color.BLACK, Position(7, 6)))
        self.place_piece(Rook(Color.BLACK, Position(7, 7)))
    
    def place_piece(self, piece: Piece):
        """
        Coloca uma peça no tabuleiro
        
        Args:
            piece: Peça a ser colocada
        """
        if piece.position.is_valid():
            self.board[piece.position.row][piece.position.col] = piece
    
    def get_piece_at(self, position: Position) -> Optional[Piece]:
        """
        Retorna a peça em uma posição específica
        
        Args:
            position: Posição a verificar
        
        Returns:
            Peça na posição ou None se vazio
        """
        if not position.is_valid():
            return None
        return self.board[position.row][position.col]
    
    def is_path_clear(self, start: Position, end: Position) -> bool:
        """
        Verifica se o caminho entre duas posições está livre
        (não inclui as posições inicial e final)
        
        Args:
            start: Posição inicial
            end: Posição final
        
        Returns:
            True se o caminho está livre
        """
        row_diff = end.row - start.row
        col_diff = end.col - start.col
        
        # Determina a direção do movimento
        row_step = 0 if row_diff == 0 else (1 if row_diff > 0 else -1)
        col_step = 0 if col_diff == 0 else (1 if col_diff > 0 else -1)
        
        # Número de passos
        steps = max(abs(row_diff), abs(col_diff))
        
        # Verifica cada posição no caminho (exceto início e fim)
        current_row = start.row + row_step
        current_col = start.col + col_step
        
        for _ in range(steps - 1):
            if self.board[current_row][current_col] is not None:
                return False
            current_row += row_step
            current_col += col_step
        
        return True
    
    def move_piece(self, start: Position, end: Position) -> bool:
        """
        Move uma peça de uma posição para outra
        
        Args:
            start: Posição inicial
            end: Posição final
        
        Returns:
            True se o movimento foi executado com sucesso
        
        Note:
            Esta versão básica não valida se o movimento deixa o rei em xeque.
            Para uma implementação completa, adicione validação após executar o movimento.
        """
        piece = self.get_piece_at(start)
        
        if piece is None:
            return False
        
        if piece.color != self.current_turn:
            return False
        
        if not piece.can_move_to(end, self):
            return False
        
        # Executa o movimento
        captured_piece = self.get_piece_at(end)
        self.board[end.row][end.col] = piece
        self.board[start.row][start.col] = None
        piece.position = end
        piece.has_moved = True
        
        # Registra o movimento
        self.move_history.append({
            'piece': piece,
            'from': start,
            'to': end,
            'captured': captured_piece
        })
        
        # Alterna o turno
        self.current_turn = Color.BLACK if self.current_turn == Color.WHITE else Color.WHITE
        
        return True
    
    def is_square_attacked(self, position: Position, by_color: Color) -> bool:
        """
        Verifica se uma posição está sendo atacada por peças de uma cor
        
        Args:
            position: Posição a verificar
            by_color: Cor das peças atacantes
        
        Returns:
            True se a posição está sob ataque
        """
        for row in range(8):
            for col in range(8):
                piece = self.board[row][col]
                if piece is not None and piece.color == by_color:
                    if piece.can_move_to(position, self):
                        return True
        return False
    
    def find_king(self, color: Color) -> Optional[Position]:
        """
        Encontra a posição do rei de uma cor específica
        
        Args:
            color: Cor do rei a procurar
        
        Returns:
            Posição do rei ou None se não encontrado
        """
        for row in range(8):
            for col in range(8):
                piece = self.board[row][col]
                if piece is not None and isinstance(piece, King) and piece.color == color:
                    return piece.position
        return None
    
    def is_in_check(self, color: Color) -> bool:
        """
        Verifica se o rei de uma cor está em xeque
        
        Args:
            color: Cor do rei a verificar
        
        Returns:
            True se o rei está em xeque
        """
        king_position = self.find_king(color)
        if king_position is None:
            return False
        
        opponent_color = Color.BLACK if color == Color.WHITE else Color.WHITE
        return self.is_square_attacked(king_position, opponent_color)
    
    def display(self):
        """Exibe o tabuleiro no console"""
        print("\n  a b c d e f g h")
        print("  ---------------")
        for row in range(7, -1, -1):
            print(f"{row + 1}|", end="")
            for col in range(8):
                piece = self.board[row][col]
                if piece is None:
                    print(".", end=" ")
                else:
                    print(piece.get_symbol(), end=" ")
            print(f"|{row + 1}")
        print("  ---------------")
        print("  a b c d e f g h\n")
    
    def get_all_pieces(self, color: Optional[Color] = None) -> List[Piece]:
        """
        Retorna todas as peças no tabuleiro
        
        Args:
            color: Cor das peças (opcional, None retorna todas)
        
        Returns:
            Lista de peças
        """
        pieces = []
        for row in range(8):
            for col in range(8):
                piece = self.board[row][col]
                if piece is not None:
                    if color is None or piece.color == color:
                        pieces.append(piece)
        return pieces
    
    def get_board_state(self) -> str:
        """
        Retorna uma representação em string do estado do tabuleiro
        
        Returns:
            String representando o tabuleiro
        """
        state = []
        for row in range(7, -1, -1):
            row_state = []
            for col in range(8):
                piece = self.board[row][col]
                if piece is None:
                    row_state.append(".")
                else:
                    row_state.append(piece.get_symbol())
            state.append(" ".join(row_state))
        return "\n".join(state)
    
    def __str__(self) -> str:
        return self.get_board_state()

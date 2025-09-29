#include "ChessBoard.cpp"
#include <iostream>

class ChessBoardPrint {
public:
  ChessBoardPrint(ChessBoard &board) {
    board.on_piece_move = [](const ChessBoard::Piece &piece, const std::string &from, const std::string &to) {
      std::cout << piece.type() << " is moving from " << from << " to " << to << std::endl;
    };

    board.on_piece_removed = [](const ChessBoard::Piece &piece, const std::string &square) {
      std::cout << piece.type() << " is being removed from " << square << std::endl;
    };

    board.on_lost_game = [](ChessBoard::Color color) {
      if (color == ChessBoard::Color::WHITE)
        std::cout << "White lost the game" << std::endl;
      else
        std::cout << "Black lost the game" << std::endl;
    };

    board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const std::string &from, const std::string &to) {
      std::cout << "can not move " << piece.type() << " from " << from << " to " << to << std::endl;
    };

    board.on_piece_move_missing = [](const std::string &square) {
      std::cout << "no piece at " << square << std::endl;
    };

    board.after_piece_move = [&board]() {
      std::cout << "Board after move:" << std::endl;
      for (int y = 7; y >= 0; --y) {
        std::cout << (y + 1) << " ";
        for (int x = 0; x < 8; ++x) {
          if (board.squares[x][y])
            std::cout << board.squares[x][y]->symbol() << " ";
          else
            std::cout << ". ";
        }
        std::cout << std::endl;
      }
      std::cout << "  a b c d e f g h" << std::endl
                << std::endl;
    };
  }
};

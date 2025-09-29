#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}
    Color color;

    std::string color_string() const {
      return (color == Color::WHITE) ? "white" : "black";
    }

    virtual std::string type() const = 0;
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    virtual char symbol() const = 0;
  };

  class King : public Piece {
  public:
    King(Color color) : Piece(color) {}
    std::string type() const override { return color_string() + " king"; }
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int dx = abs(to_x - from_x);
      int dy = abs(to_y - from_y);
      return (dx <= 1 && dy <= 1 && (dx != 0 || dy != 0));
    }
    char symbol() const override { return (color == Color::WHITE) ? 'K' : 'k'; }
  };

  class Knight : public Piece {
  public:
    Knight(Color color) : Piece(color) {}
    std::string type() const override { return color_string() + " knight"; }
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int dx = abs(to_x - from_x);
      int dy = abs(to_y - from_y);
      return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    }
    char symbol() const override { return (color == Color::WHITE) ? 'N' : 'n'; }
  };

  ChessBoard() {
    squares.resize(8);
    for (auto &col : squares)
      col.resize(8);
  }

  std::vector<std::vector<std::unique_ptr<Piece>>> squares;

  std::function<void(const Piece &, const std::string &, const std::string &)> on_piece_move;
  std::function<void(const Piece &, const std::string &)> on_piece_removed;
  std::function<void(Color)> on_lost_game;
  std::function<void(const Piece &, const std::string &, const std::string &)> on_piece_move_invalid;
  std::function<void(const std::string &)> on_piece_move_missing;
  std::function<void()> after_piece_move;

  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(std::string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(std::string() + to[1]) - 1;

    auto &piece_from = squares[from_x][from_y];
    if (piece_from) {
      if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
        if (on_piece_move)
          on_piece_move(*piece_from, from, to);

        auto &piece_to = squares[to_x][to_y];
        if (piece_to) {
          if (piece_from->color != piece_to->color) {
            if (on_piece_removed)
              on_piece_removed(*piece_to, to);
            if (auto king = dynamic_cast<King *>(piece_to.get())) {
              if (on_lost_game)
                on_lost_game(king->color);
            }
          } else {
            if (on_piece_move_invalid)
              on_piece_move_invalid(*piece_from, from, to);
            return false;
          }
        }
        piece_to = std::move(piece_from);

        if (after_piece_move)
          after_piece_move();
        return true;
      } else {
        if (on_piece_move_invalid)
          on_piece_move_invalid(*piece_from, from, to);
        return false;
      }
    } else {
      if (on_piece_move_missing)
        on_piece_move_missing(from);
      return false;
    }
  }
};

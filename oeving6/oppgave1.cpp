#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

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
      if (color == Color::WHITE)
        return "white";
      else
        return "black";
    }

    /// Return color and type of the chess piece
    virtual std::string type() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

    /// Return a short version of the color and type
    virtual std::string print() const = 0;
  };

  class King : public Piece {
  public:
    King(Color color) : Piece(color){};

    std::string type() const override {
      return color_string() + " king";
    };

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      if (abs(to_x - from_x) <= 1 && abs(to_y - from_y) <= 1) {
        return true;
      } else {
        return false;
      }
    }

    std::string print() const override {
      if (color == Color::WHITE)
        return "O";
      else
        return "X";
    };
  };

  class Knight : public Piece {
  public:
    Knight(Color color) : Piece(color){};

    std::string type() const override {
      return color_string() + " knight";
    };
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      if ((abs(to_x - from_x) == 2 && abs(to_y - from_y) == 1) || (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 2)) {
        return true;
      } else {
        return false;
      }
    }

    std::string print() const override {
      if (color == Color::WHITE)
        return "o";
      else
        return "x";
    };
  };

  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
  function<void(const Piece &piece, const string &square)> on_piece_removed;
  function<void(Color color)> on_lost_game;
  function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
  function<void(const string &square)> on_piece_move_missing;
  function<void()> after_piece_move;

  /// Move a chess piece if it is a valid move.
  /// Does not test for check or checkmate.
  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

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
            if (auto king = dynamic_cast<King *>(piece_to.get()))
              if (on_lost_game)
                on_lost_game(king->color);
          } else {
            // piece in the from square has the same color as the piece in the to square
            if (on_piece_move_invalid)
              on_piece_move_invalid(*piece_from, from, to);
            return false;
          }
        }
        piece_to = move(piece_from);
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

class ChessBoardPrint {
public:
  ChessBoardPrint(ChessBoard &board);
};

ChessBoardPrint::ChessBoardPrint(ChessBoard &board) {
  board.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
    cout << piece.type() << " is moving from " << from << " to " << to << endl;
  };
  board.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
    cout << piece.type() << " is being removed from " << square << endl;
  };
  board.on_lost_game = [](ChessBoard::Color color) {
    if (color == ChessBoard::Color::WHITE)
      cout << "Black";
    else
      cout << "White";
    cout << " won the game" << endl;
  };
  board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
    cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
  };
  board.on_piece_move_missing = [](const string &square) {
    cout << "no piece at " << square << endl;
  };
  board.after_piece_move = [&board]() {
    // Drawing the chess board after each move
    for (int i = 7; i >= 0; i--) {
      cout << i + 1;
      for (int j = 0; j < 8; j++) {
        cout << "[";
        if (board.squares[j][i] != 0) {
          cout << board.squares[j][i]->print();
        } else {
          cout << " ";
        }
        cout << "]";
      }
      cout << endl;
    }
    cout << "  ";
    for (int k = 0; k < 8; k++) {
      char a = static_cast<char>('a' + k);
      cout << a << "  ";
    }
    cout << endl
         << endl;
  };
}

int main() {
  ChessBoard board;
  ChessBoardPrint print(board);

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}

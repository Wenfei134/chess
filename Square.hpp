#ifndef SQUARE_H
#define SQUARE_H

#include <memory>

// Fwd declare
class Piece;

class Square
{
  int ROW;
  int COL;
  std::shared_ptr<Piece> mPiece;

public:
  Square(int row, int col);
  // Place pc on square
  void Place(std::shared_ptr<Piece> &pc);
  // Empties square
  void Empty();
  // Return whether square is empty
  bool IsEmpty();
  std::shared_ptr<Piece> GetPiece();
  int GetRow();
  int GetCol();
};

#endif

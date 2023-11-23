#include "square.h"
#include "pieces/piece.h"

Square::Square(int row, int col) : ROW{row}, COL{col}, piece{nullptr} {}

void Square::place(shared_ptr<Piece> &pc)
{
  empty();
  piece = pc;
  piece->setPosition(this);
}
void Square::empty()
{
  if (!isEmpty())
  {
    piece->setPosition(nullptr);
    piece = nullptr;
  }
}
bool Square::isEmpty() { return piece == nullptr; }

shared_ptr<Piece> Square::getPiece()
{
  return piece;
}

int Square::getRow() { return ROW; }
int Square::getCol() { return COL; }

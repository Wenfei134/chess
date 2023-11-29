#include "piece.h"
#include "../square.h"
#include "../board.h"

Piece::Piece(PieceColour colour, PieceType name) : colour{colour}, name{name}, position{nullptr} {}

void Piece::setPosition(Square *sq)
{
  position = sq;
}

Square *Piece::getPosition()
{
  return position;
}

bool Piece::isDead()
{
  return position == nullptr;
}

bool Piece::getHasMoved()
{
  return has_moved;
}

void Piece::setHasMoved(bool has_moved)
{
  this->has_moved = has_moved;
}

PieceColour Piece::getColour()
{
  return colour;
}

PieceType Piece::getType()
{
  return name;
}

bool Piece::isBlockedByPiece(Move &mv)
{
  if (mv.end->isEmpty())
  {
    return false;
  }
  return true;
}

#include "Board.hpp"
#include "Move.hpp"
#include "Pieces/Piece.hpp"
#include "Square.hpp"

// --------------------------------------------------------------------------------------------------------------------
Move::Move(Square *start, Square *end, Board &b) : mStart{start}, mEnd{end}
{
  if (!start->IsEmpty())
  {
    mMovingPiece = start->GetPiece();
    mIsFirstMove = !mMovingPiece->GetHasMoved();
  }

  if (!end->IsEmpty())
  {
    mIsAttack = true;
    mKilledPiece = end->GetPiece();
  }
}

// --------------------------------------------------------------------------------------------------------------------

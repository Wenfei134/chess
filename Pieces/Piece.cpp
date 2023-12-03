#include "Piece.hpp"
#include "../Square.hpp"
#include "../Board.hpp"

#include <vector>

// --------------------------------------------------------------------------------------------------------------------
Piece::Piece(PieceColour colour, PieceType name) : mColour{colour}, mName{name}, mPosition{nullptr} {}

// --------------------------------------------------------------------------------------------------------------------
void Piece::SetPosition(Square *sq)
{
  mPosition = sq;
}

// --------------------------------------------------------------------------------------------------------------------
Square *Piece::GetPosition()
{
  return mPosition;
}

// --------------------------------------------------------------------------------------------------------------------
bool Piece::IsDead()
{
  return mPosition == nullptr;
}

// --------------------------------------------------------------------------------------------------------------------
bool Piece::GetHasMoved()
{
  return mHasMoved;
}

// --------------------------------------------------------------------------------------------------------------------
void Piece::SetHasMoved(bool has_moved)
{
  this->mHasMoved = has_moved;
}

// --------------------------------------------------------------------------------------------------------------------
PieceColour Piece::GetColour()
{
  return mColour;
}

// --------------------------------------------------------------------------------------------------------------------
PieceType Piece::GetType()
{
  return mName;
}

// --------------------------------------------------------------------------------------------------------------------
bool Piece::IsBlockedByPiece(Move &mv)
{
  if (mv.mEnd->IsEmpty())
  {
    return false;
  }
  return true;
}

// --------------------------------------------------------------------------------------------------------------------

void Piece::SetPseudoLegalMoves(int row, int col, int range, std::vector<std::pair<int, int>> &directions, Board *board)
{
  mPseudoLegalMoves.clear();
  std::vector<bool> blockedByPiece;

  for (int i = 0; i < directions.size(); i++)
  {
    blockedByPiece.push_back(false);
  }

  for (int i = 0; i < range; i++)
  {
    for (int j = 0; j < directions.size(); j++)
    {
      int nextRow = row + (i + 1) * directions[j].first;
      int nextCol = col + (i + 1) * directions[j].second;

      if (!board->InRange(nextRow, nextCol))
      {
        continue;
      }

      if (blockedByPiece[j])
      {
        continue;
      }

      Move mv = Move(mPosition, board->GetSquare(nextRow, nextCol), *board);

      if (!IsBlockedByPiece(mv))
      {
        mPseudoLegalMoves.push_back(mv);
      }
      else
      {
        blockedByPiece[j] = true;
        if (mColour != mv.mEnd->GetPiece()->GetColour())
        { // can take
          mPseudoLegalMoves.push_back(mv);
        }
      }
    }
  }
}

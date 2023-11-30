#include "../Board.hpp"
#include "../Move.hpp"
#include "../Square.hpp"
#include "King.hpp"

// --------------------------------------------------------------------------------------------------------------------
King::King(PieceColour colour, PieceType name) : Piece(colour, name) {}

// --------------------------------------------------------------------------------------------------------------------
std::vector<Move> King::ListPseudoLegalMoves(Board *board)
{
  mPseudoLegalMoves.clear();
  return mPseudoLegalMoves;
}

// --------------------------------------------------------------------------------------------------------------------

#include "../Move.hpp"
#include "../Square.hpp"
#include "../Board.hpp"
#include "Queen.hpp"

// --------------------------------------------------------------------------------------------------------------------
Queen::Queen(PieceColour colour, PieceType name) : Piece(colour, name) {}

// --------------------------------------------------------------------------------------------------------------------
std::vector<Move> Queen::ListPseudoLegalMoves(Board *board)
{
  mPseudoLegalMoves.clear();
  return mPseudoLegalMoves;
}

// --------------------------------------------------------------------------------------------------------------------

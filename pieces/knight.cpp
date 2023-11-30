#include "../Board.hpp"
#include "../Move.hpp"
#include "../Square.hpp"
#include "Knight.hpp"

// --------------------------------------------------------------------------------------------------------------------
Knight::Knight(PieceColour colour, PieceType name) : Piece(colour, name) {}

// --------------------------------------------------------------------------------------------------------------------
std::vector<Move> Knight::ListPseudoLegalMoves(Board *board)
{
  mPseudoLegalMoves.clear();
  return mPseudoLegalMoves;
}

// --------------------------------------------------------------------------------------------------------------------

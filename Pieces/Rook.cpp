#include "../Board.hpp"
#include "../Move.hpp"
#include "../Square.hpp"
#include "Rook.hpp"

// --------------------------------------------------------------------------------------------------------------------
Rook::Rook(PieceColour colour, PieceType name) : Piece(colour, name) {}

// --------------------------------------------------------------------------------------------------------------------
std::vector<Move> Rook::ListPseudoLegalMoves(Board *board)
{
  mPseudoLegalMoves.clear();
  return mPseudoLegalMoves;
}

// --------------------------------------------------------------------------------------------------------------------

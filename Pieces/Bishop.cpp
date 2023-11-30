#include "../Board.hpp"
#include "../Move.hpp"
#include "../Square.hpp"
#include "Bishop.hpp"

// --------------------------------------------------------------------------------------------------------------------
Bishop::Bishop(PieceColour colour, PieceType name) : Piece(colour, name) {}

// --------------------------------------------------------------------------------------------------------------------
std::vector<Move> Bishop::ListPseudoLegalMoves(Board *board)
{
  mPseudoLegalMoves.clear();
  return mPseudoLegalMoves;
}

// --------------------------------------------------------------------------------------------------------------------

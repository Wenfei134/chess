#include "../Board.hpp"
#include "../Move.hpp"
#include "../Square.hpp"
#include "Rook.hpp"

// --------------------------------------------------------------------------------------------------------------------
Rook::Rook(PieceColour colour, PieceType name) : Piece(colour, name) {}

// --------------------------------------------------------------------------------------------------------------------
std::vector<Move> Rook::ListPseudoLegalMoves(Board *board)
{
  int row = mPosition->GetRow();
  int col = mPosition->GetCol();
  int range = 8; 
  std::vector<std::pair<int, int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};

  SetPseudoLegalMoves(row, col, range, directions, board);
  return mPseudoLegalMoves;
}

// --------------------------------------------------------------------------------------------------------------------

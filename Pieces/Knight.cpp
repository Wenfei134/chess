#include "../Board.hpp"
#include "../Move.hpp"
#include "../Square.hpp"
#include "Knight.hpp"

// --------------------------------------------------------------------------------------------------------------------
Knight::Knight(PieceColour colour, PieceType name) : Piece(colour, name) {}

// --------------------------------------------------------------------------------------------------------------------
std::vector<Move> Knight::ListPseudoLegalMoves(Board *board)
{
  int row = mPosition->GetRow();
  int col = mPosition->GetCol();
  int range = 1; 
  std::vector<std::pair<int, int>> directions = {{2,1},{2,-1},{-2,-1},{-2,1},{1,2},{1,-2},{-1,2},{-1,-2}};

  SetPseudoLegalMoves(row, col, range, directions, board);
  return mPseudoLegalMoves;
}

// --------------------------------------------------------------------------------------------------------------------

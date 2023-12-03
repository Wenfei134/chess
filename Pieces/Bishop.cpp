#include "../Board.hpp"
#include "../Move.hpp"
#include "../Square.hpp"
#include "Bishop.hpp"

// --------------------------------------------------------------------------------------------------------------------
Bishop::Bishop(PieceColour colour, PieceType name) : Piece(colour, name) {}

// --------------------------------------------------------------------------------------------------------------------
std::vector<Move> Bishop::ListPseudoLegalMoves(Board *board)
{
  int row = mPosition->GetRow();
  int col = mPosition->GetCol();
  int range = 8; 
  std::vector<std::pair<int, int>> directions = {{1,1},{-1,1},{1,-1},{-1,-1}};

  SetPseudoLegalMoves(row, col, range, directions, board);
  return mPseudoLegalMoves;
}

// --------------------------------------------------------------------------------------------------------------------

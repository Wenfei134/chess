#include "../Board.hpp"
#include "../Move.hpp"
#include "../Square.hpp"
#include "King.hpp"

// --------------------------------------------------------------------------------------------------------------------
King::King(PieceColour colour, PieceType name) : Piece(colour, name) {}

// --------------------------------------------------------------------------------------------------------------------
std::vector<Move> King::ListPseudoLegalMoves(Board *board)
{
  int row = mPosition->GetRow();
  int col = mPosition->GetCol();
  int range = 1; 
  std::vector<std::pair<int, int>> directions = {{1,1},{0,1},{-1,1},{1,0},{-1,0},{1,-1},{0,-1},{-1,-1}};

  SetPseudoLegalMoves(row, col, range, directions, board);
  return mPseudoLegalMoves;
}

// --------------------------------------------------------------------------------------------------------------------

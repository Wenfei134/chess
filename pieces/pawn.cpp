#include "pawn.h"
#include "../board.h"
#include "../move.h"
#include "../square.h"
#include <iostream>

Pawn::Pawn(PieceColour colour, PieceType name) : Piece(colour, name) {}

vector<Move> Pawn::listPseudoLegalMoves(Board &board)
{
  pseudo_legal_moves.clear();
  int row = position->getRow();
  int col = position->getCol();
  int i;
  if (colour == PieceColour::kWhite)
  {
    i = -1;
  }
  else
  {
    i = 1;
  }

  for (int j = 0; j < 2; j++) // normal move
  {
    if (j == 0 || !has_moved)
    {
      int nextRow = row + i * (j + 1);
      if (!board.inRange(nextRow, col))
      {
        continue;
      }
      Move mv = Move(board.getSquare(row, col), board.getSquare(nextRow, col), board);
      if (!isBlockedByPiece(board, mv)) // not blocked by a piece
      {
        pseudo_legal_moves.push_back(mv);
      }
      else
      {
        break;
      }
    }
  }

  for (int j = -1; j < 2; j++) // pawn takes diagonally
  {
    if (j == 0)
    {
      continue;
    }
    int nextRow = row + i;
    int nextCol = col + j;
    if (!board.inRange(nextRow, nextCol))
    {
      continue;
    }
    Move mv = Move(board.getSquare(row, col), board.getSquare(nextRow, nextCol), board);
    if (isBlockedByPiece(board, mv)) // there is a piece to take
    {
      pseudo_legal_moves.push_back(mv);
    }
  }

  return pseudo_legal_moves;
}

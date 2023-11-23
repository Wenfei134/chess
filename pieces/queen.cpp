#include "queen.h"
#include "../move.h"
#include "../square.h"
#include "../board.h"

Queen::Queen(PieceColour color, PieceType name) : Piece(color, name) {}

vector<Move> Queen::listPseudoLegalMoves(Board &board)
{
  pseudo_legal_moves.clear();
  return pseudo_legal_moves;
}

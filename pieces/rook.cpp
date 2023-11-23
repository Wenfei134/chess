#include "rook.h"
#include "../board.h"
#include "../move.h"
#include "../square.h"

Rook::Rook(PieceColour color, PieceType name) : Piece(color, name) {}

vector<Move> Rook::listPseudoLegalMoves(Board &board)
{
  pseudo_legal_moves.clear();
  return pseudo_legal_moves;
}

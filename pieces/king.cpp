#include "king.h"
#include "../board.h"
#include "../move.h"
#include "../square.h"

King::King(PieceColour colour, PieceType name) : Piece(colour, name) {}

vector<Move> King::listPseudoLegalMoves(Board &board)
{
  pseudo_legal_moves.clear();
  return pseudo_legal_moves;
}

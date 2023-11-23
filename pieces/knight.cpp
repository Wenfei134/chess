#include "knight.h"
#include "../board.h"
#include "../move.h"
#include "../square.h"

Knight::Knight(PieceColour colour, PieceType name) : Piece(colour, name) {}

vector<Move> Knight::listPseudoLegalMoves(Board &board)
{
  pseudo_legal_moves.clear();
  return pseudo_legal_moves;
}

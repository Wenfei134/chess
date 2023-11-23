#include "bishop.h"
#include "../board.h"
#include "../move.h"
#include "../square.h"

Bishop::Bishop(PieceColour colour, PieceType name) : Piece(colour, name) {}

vector<Move> Bishop::listPseudoLegalMoves(Board &board)
{
  pseudo_legal_moves.clear();
  return pseudo_legal_moves;
}

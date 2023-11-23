#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece
{
public:
  Queen(PieceColour color, PieceType name);
  vector<Move> listPseudoLegalMoves(Board &board) override;
};

#endif

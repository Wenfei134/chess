#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop : public Piece
{
public:
  Bishop(PieceColour colour, PieceType name);
  vector<Move> listPseudoLegalMoves(Board &board) override;
};

#endif

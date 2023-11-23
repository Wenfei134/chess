#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn : public Piece
{
public:
  Pawn(PieceColour colour, PieceType name);
  vector<Move> listPseudoLegalMoves(Board &board) override;
};

#endif

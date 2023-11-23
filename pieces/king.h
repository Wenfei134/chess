#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece
{
public:
  King(PieceColour colour, PieceType name);
  vector<Move> listPseudoLegalMoves(Board &board) override;
};

#endif

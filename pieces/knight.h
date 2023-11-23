#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight : public Piece
{
public:
  Knight(PieceColour colour, PieceType name);
  vector<Move> listPseudoLegalMoves(Board &board) override;
};

#endif

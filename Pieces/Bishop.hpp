#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.hpp"

class Bishop : public Piece
{
public:
  Bishop(PieceColour colour, PieceType name);
  std::vector<Move> ListPseudoLegalMoves(Board *board) override;
};

#endif

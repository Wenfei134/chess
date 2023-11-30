#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.hpp"

class Queen : public Piece
{
public:
  Queen(PieceColour colour, PieceType name);
  std::vector<Move> ListPseudoLegalMoves(Board *board) override;
};

#endif

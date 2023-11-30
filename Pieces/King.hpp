#ifndef KING_H
#define KING_H

#include "Piece.hpp"

class King : public Piece
{
public:
  King(PieceColour colour, PieceType name);
  std::vector<Move> ListPseudoLegalMoves(Board *board) override;
};

#endif

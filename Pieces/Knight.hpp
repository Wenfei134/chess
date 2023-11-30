#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.hpp"

class Knight : public Piece
{
public:
  Knight(PieceColour colour, PieceType name);
  std::vector<Move> ListPseudoLegalMoves(Board *board) override;
};

#endif

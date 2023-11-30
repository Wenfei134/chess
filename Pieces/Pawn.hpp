#ifndef PAWN_H
#define PAWN_H

#include "Piece.hpp"

class Pawn : public Piece
{
public:
  Pawn(PieceColour colour, PieceType name);
  std::vector<Move> ListPseudoLegalMoves(Board *board) override;
};

#endif

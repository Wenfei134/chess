#ifndef ROOK_H
#define ROOK_H

#include "Piece.hpp"

class Rook : public Piece
{
public:
  Rook(PieceColour colour, PieceType name);
  std::vector<Move> ListPseudoLegalMoves(Board *board) override;
};

#endif

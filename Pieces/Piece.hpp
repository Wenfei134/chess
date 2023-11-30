#ifndef PIECE_H
#define PIECE_H

#include "../Move.hpp"

#include <vector>

class Board;
class Square;

enum class PieceType
{
  kPawn = 0,
  kKnight,
  kBishop,
  kRook,
  kQueen,
  kKing
};

enum class PieceColour
{
  kWhite = 0,
  kBlack
};

class Piece
{
protected:
  PieceColour mColour;
  PieceType mName;
  Square *mPosition;
  bool mHasMoved = false;
  std::vector<Move> mPseudoLegalMoves;

public:
  Piece(PieceColour colour, PieceType name);
  PieceColour GetColour();
  PieceType GetType();
  void SetPosition(Square *sq);
  Square *GetPosition();
  bool GetHasMoved();
  void SetHasMoved(bool has_moved);
  bool IsDead();
  virtual bool IsBlockedByPiece(Move &mv);
  virtual std::vector<Move> ListPseudoLegalMoves(Board *board) = 0;
  virtual ~Piece() = default;
};

#endif

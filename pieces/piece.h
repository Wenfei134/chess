#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <vector>
#include "../move.h"

class Board;
class Square;

using std::shared_ptr;
using std::string;
using std::vector;

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
  PieceColour colour;
  PieceType name;
  Square *position;
  bool has_moved = false;
  vector<Move> pseudo_legal_moves;

public:
  Piece(PieceColour colour, PieceType name);
  PieceColour getColour();
  PieceType getType();
  void setPosition(Square *sq);
  Square *getPosition();
  bool getHasMoved();
  void setHasMoved(bool has_moved);
  bool isDead();
  virtual bool isBlockedByPiece(Move &mv);
  virtual vector<Move> listPseudoLegalMoves(Board &board) = 0;
  virtual ~Piece() = default;
};

#endif

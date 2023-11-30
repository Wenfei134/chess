#ifndef MOVE_H
#define MOVE_H

#include <memory>

class Board;
class Square;
class Piece;

class Move
{
public:
  Move(Square *start, Square *end, Board &b);
  Square *mStart;
  Square *mEnd;
  std::shared_ptr<Piece> mMovingPiece;
  std::shared_ptr<Piece> mKilledPiece;
  std::shared_ptr<Piece> mRetiredPiece;
  bool mIsAttack = false;
  bool mIsFirstMove = false;
};

#endif

#ifndef MOVE_H
#define MOVE_H

#include <memory>
#include <utility>
#include <iostream>

class Board;
class Square;
class Piece;

using std::shared_ptr;

class Move
{
public:
  Move(Square *start, Square *end, Board &b);
  Square *start;
  Square *end;
  shared_ptr<Piece> moving_piece;
  shared_ptr<Piece> killed_piece;
  shared_ptr<Piece> retired_piece;
  bool is_attack = false;
  bool is_first_move = false;
  /* If you wish to implement more chess functionality then uncomment the following
  bool is_enpassant = false;
  bool is_promotion = false;
  int promote_to;
  bool is_kingside_castling = false;
  bool is_queenside_castling = false;
  bool is_white_resign = false;
  bool is_black_resign = false;
  */
};

#endif

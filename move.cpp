#include "move.h"
#include "square.h"
#include "board.h"
#include "pieces/piece.h"

Move::Move(Square *start, Square *end, Board &b) : start{start}, end{end}
{
  if (!start->isEmpty())
  {
    moving_piece = start->getPiece();
    is_first_move = !moving_piece->getHasMoved();
  }

  if (!end->isEmpty())
  {
    is_attack = true;
    killed_piece = end->getPiece();
  }
}
#include "piece.h"
#include "../square.h"
#include "../board.h"

Piece::Piece(PieceColour colour, PieceType name) : colour{colour}, name{name}, position{nullptr} {}

void Piece::setPosition(Square *sq)
{
  position = sq;
}

Square *Piece::getPosition()
{
  return position;
}

bool Piece::isDead()
{
  return position == nullptr;
}

bool Piece::getHasMoved()
{
  return has_moved;
}

void Piece::setHasMoved(bool has_moved)
{
  this->has_moved = has_moved;
}

PieceColour Piece::getColour()
{
  return colour;
}

PieceType Piece::getType()
{
  return name;
}

bool Piece::isBlockedByPiece(Move &mv)
{
  if (mv.end->isEmpty())
  {
    return false;
  }
  return true;
}

// void Piece::setPseudoLegalMoves(int row, int col, int range, vector<std::pair<int, int>> &directions, Board &board)
// {
//   pseudo_legal_moves.clear();
//   vector<bool> blockedByPiece;

//   for (int i = 0; i < directions.size(); i++)
//   {
//     blockedByPiece.push_back(false);
//   }

//   for (int i = 0; i < range; i++)
//   {
//     for (int j = 0; j < directions.size(); j++)
//     {
//       int nextRow = row + (i + 1) * directions[j].first;
//       int nextCol = col + (i + 1) * directions[j].second;

//       if (!board.inRange(nextRow, nextCol))
//       {
//         continue;
//       }

//       if (blockedByPiece[j])
//       {
//         continue;
//       }

//       Move mv = Move(position, board.getSquare(nextRow, nextCol), board);

//       if (!isBlockedByPiece(board, mv))
//       {
//         pseudo_legal_moves.push_back(mv);
//       }
//       else
//       {
//         blockedByPiece[j] = true;
//         if (colour != mv.end->getPiece()->getcolour())
//         { // can take
//           pseudo_legal_moves.push_back(mv);
//         }
//       }
//     }
//   }
// }

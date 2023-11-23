#ifndef CHESSGAME_H
#define CHESSGAME_H
#include "board.h"
#include "move.h"
#include "pieces/piece.h"
#include <utility>
#include <stdexcept>

using std::shared_ptr;
using std::unique_ptr;
using std::vector;

class ChessGame
{
  Board board;
  int state;
  PieceColour player_in_turn;
  bool setted = false;

public:
  enum
  {
    INITIAL = 0,
    ACTIVE,
    WHITE_WIN,
    BLACK_WIN,
    STALEMATE
  };
  ChessGame();
  void reset();
  void takeTurn(Move mv);
  void setup();
  vector<vector<vector<Move>>> getLegalMoves();
  int getState();

  Board *GetBoard();
};
#endif

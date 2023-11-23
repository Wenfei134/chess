#ifndef CHESSCONTROLLER_H
#define CHESSCONTROLLER_H

#include "move.h"
#include "chessgame.h"
#include <vector>

using std::vector;

// Fwd declare
class ChessGraphicsSystem;

class ChessController
{
  int prev_row;
  int prev_col;
  bool hasValidMoves;
  vector<vector<vector<Move>>> validMoves;
  ChessGraphicsSystem *gSys;
  ChessGame *game;

public:
  ChessController(ChessGraphicsSystem * gSys, ChessGame * game);
  void start();
  void handleClick(int row, int col);
};

#endif

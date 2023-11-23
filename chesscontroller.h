#ifndef CHESSCONTROLER_H
#define CHESSCONTROLER_H

#include "move.h"
#include "chessgame.h"
#include <vector>

using std::vector;

class ChessControler
{
  int prev_row;
  int prev_col;
  bool hasValidMoves;
  ChessGame game;
  vector<vector<vector<Move>>> validMoves;

public:
  void start();
  void handleClick(int row, int col);
  void print()
  {
    game.print();
  }
};

#endif

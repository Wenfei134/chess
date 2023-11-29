#ifndef CHESSCONTROLLER_H
#define CHESSCONTROLLER_H

#include "move.h"
#include <vector>

using std::vector;

// Fwd declare
class ChessGraphicsSystem;
class ChessGame;

class ChessController
{
  int mSelectedPieceRow;
  int mSelectedPieceCol;
  vector<vector<vector<Move>>> mValidMoves;
  ChessGraphicsSystem *mGraphicsSystem = nullptr;
  ChessGame *mGame = nullptr;

  void DeselectSelectedPiece();
  bool HasSelectedPiece();

public:
  ChessController();
  ~ChessController();
  void Start();
  void HandleClick(int row, int col);
};

#endif

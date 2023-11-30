#ifndef CHESSCONTROLLER_H
#define CHESSCONTROLLER_H

#include "Move.hpp"

#include <vector>

// Fwd declare
class ChessGraphicsSystem;
class ChessGame;

class ChessController
{
  int mSelectedPieceRow = -1; // -1 means none selected
  int mSelectedPieceCol = -1; // -1 means none selected
  std::vector<std::vector<std::vector<Move>>> mValidMoves;
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

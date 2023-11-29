#include "chesscontroller.h"
#include "move.h"
#include "chessgame.h"
#include "Graphics/ChessGraphicsSystem.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>

// --------------------------------------------------------------------------------------------------------------------
ChessController::ChessController() {
  mGraphicsSystem = new ChessGraphicsSystem(this);
  mGame = new ChessGame();
} 

// --------------------------------------------------------------------------------------------------------------------
ChessController::~ChessController() {
  delete mGraphicsSystem;
  delete mGame;
}

// --------------------------------------------------------------------------------------------------------------------
void ChessController::HandleClick(int row, int col)
{
  // after previous game ends, we replay
  // if (game->getState() != game->ACTIVE)
  // {
  //   start();
  // }
  // in game
  if (mGame->getState() == mGame->ACTIVE)
  {
    if (!HasSelectedPiece())
    {
      if (!mValidMoves[row][col].empty())
      {
        auto highlightedMoves = mValidMoves[row][col];
        mSelectedPieceCol = col;
        mSelectedPieceRow = row;

        // Make sure the renderer highlights
        mGraphicsSystem->Render(mGame->GetBoard(), highlightedMoves);
        return;
      }
    }
    else
    {
      for (auto mv : mValidMoves[mSelectedPieceRow][mSelectedPieceCol])
      {
        if (mv.end->getRow() == row && mv.end->getCol() == col)
        {
          mGame->takeTurn(mv);
          mValidMoves = mGame->getLegalMoves();
          mGraphicsSystem->Render(mGame->GetBoard(), {});
          return;
        }
      }
      DeselectSelectedPiece();
      // Dehighlight the rendered moves of the selected piece
      mGraphicsSystem->Render(mGame->GetBoard(), {});
      HandleClick(row, col);
      return;
    }
  }
  // if (game->getState() == game->WHITE_WIN)
  // {
  //   gSys->Render(game->GetBoard());
  // }
  // else if (game->getState() == game->BLACK_WIN)
  // {
  //   gSys->Render(game->GetBoard());
  // }
  // else if (game->getState() == game->STALEMATE)
  // {
  //   gSys->Render(game->GetBoard());
  // }
}

// --------------------------------------------------------------------------------------------------------------------
void ChessController::Start()
{
  // before game begins
  mGame->reset();
  mValidMoves = mGame->getLegalMoves();
  DeselectSelectedPiece();

  mGraphicsSystem->RunChessGame(mGame->GetBoard());
}

// --------------------------------------------------------------------------------------------------------------------
bool ChessController::HasSelectedPiece() {
  return (mSelectedPieceCol != -1 && mSelectedPieceRow != -1);
}

// --------------------------------------------------------------------------------------------------------------------
void ChessController::DeselectSelectedPiece() {
  mSelectedPieceCol = -1;
  mSelectedPieceRow = -1;
}

// --------------------------------------------------------------------------------------------------------------------

#include "ChessController.hpp"
#include "ChessGame.hpp"
#include "Graphics/ChessGraphicsSystem.hpp"
#include "Square.hpp"

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
  if (mGame->GetState() == mGame->ACTIVE)
  {
    if(row == -1 || col == -1){
      DeselectSelectedPiece();
      mGraphicsSystem->Render(mGame->GetBoard(), {});
      return;
    }

    if (!HasSelectedPiece())
    {
      if (!mValidMoves[row][col].empty())
      {
        auto highlightedMoves = mValidMoves[row][col];
        mSelectedPieceCol = col;
        mSelectedPieceRow = row;

        // Renderer highlights moves
        mGraphicsSystem->Render(mGame->GetBoard(), highlightedMoves);
        return;
      }
    }
    else
    {
      for (auto mv : mValidMoves[mSelectedPieceRow][mSelectedPieceCol])
      {
        if (mv.mEnd->GetRow() == row && mv.mEnd->GetCol() == col)
        {
          mGame->TakeTurn(mv);
          mValidMoves = mGame->GetLegalMoves();
          mGraphicsSystem->Render(mGame->GetBoard(), {});
          return;
        }
      }
      DeselectSelectedPiece();
      // Renderer renders over highlighted moves if there are any
      mGraphicsSystem->Render(mGame->GetBoard(), {});
      HandleClick(row, col);
      return;
    }
  }
}

// --------------------------------------------------------------------------------------------------------------------
void ChessController::Start()
{
  mValidMoves = mGame->GetLegalMoves();
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

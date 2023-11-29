#include "chesscontroller.h"
#include "move.h"
#include "chessgame.h"
#include "Graphics/ChessGraphicsSystem.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>

ChessController::ChessController(ChessGraphicsSystem * gSys, ChessGame * game) : gSys(gSys), game(game) {} 

void ChessController::handleClick(int row, int col)
{
  // after previous game ends, we replay
  // if (game->getState() != game->ACTIVE)
  // {
  //   start();
  // }
  // in game
  if (game->getState() == game->ACTIVE)
  {
    if (!hasSelectedPiece())
    {
      if (!validMoves[row][col].empty())
      {
        auto highlightedMoves = validMoves[row][col];
        selectedPieceCol = col;
        selectedPieceRow = row;

        // Make sure the renderer highlights
        gSys->Render(game->GetBoard());
        return;
      }
    }
    else
    {
      for (auto mv : validMoves[selectedPieceRow][selectedPieceCol])
      {
        if (mv.end->getRow() == row && mv.end->getCol() == col)
        {
          game->takeTurn(mv);
          validMoves = game->getLegalMoves();
          gSys->Render(game->GetBoard());
          return;
        }
      }
      deselectSelectedPiece();
      // Dehighlight the rendered moves of the selected piece
      gSys->Render(game->GetBoard());
      handleClick(row, col);
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

void ChessController::start()
{
  // before game begins
  game->reset();
  validMoves = game->getLegalMoves();
  deselectSelectedPiece();

  gSys->RunChessGame(game->GetBoard());
}


bool ChessController::hasSelectedPiece() {
  return (selectedPieceCol != -1 && selectedPieceRow != -1);
}

void ChessController::deselectSelectedPiece() {
  selectedPieceCol = -1;
  selectedPieceRow = -1;
}
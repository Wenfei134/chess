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
  // before game starts
  if (game->getState() != game->ACTIVE && prev_row != -1)
  {
    game->reset();
  }
  // in game
  if (game->getState() == game->ACTIVE)
  {
    if (!hasValidMoves)
    {
      validMoves = game->getLegalMoves();
      hasValidMoves = true;
    }
    if (prev_row == -1)
    {
      if (0 <= row && row < 8 && 0 <= col && col < 8)
      {
        if (validMoves[row][col].size() > 0)
        {
          auto highlightedMoves = validMoves[row][col];
          prev_col = col;
          prev_row = row;

          for (auto moves : highlightedMoves)
          {
            std::cout << moves.end->getRow() << " " << moves.end->getCol() << std::endl;
          }
          // render
          return;
        }
      }
    }
    else
    {
      for (auto mv : validMoves[prev_row][prev_col])
      {
        if (mv.end->getRow() == row && mv.end->getCol() == col)
        {
          std::cout << "made move" << std::endl;
          std::cout << "start pos " << prev_row << " " << prev_col << std::endl;
          std::cout << "end pos " << row << " " << col << std::endl;
          game->takeTurn(mv);
          validMoves = game->getLegalMoves();
          // render
          return;
        }
      }
      prev_row = -1;
      prev_col = -1;
      // render
      return;
    }
  }
  if (game->getState() == game->WHITE_WIN)
  {
    prev_row = row;
    prev_col = col;
    // render
  }
  else if (game->getState() == game->BLACK_WIN)
  {
    prev_row = row;
    prev_col = col;
    // render
  }
  else if (game->getState() == game->STALEMATE)
  {
    prev_row = row;
    prev_col = col;
    // render
  }
}

void ChessController::start()
{
  enum
  {
    WHITE = 0,
    BLACK
  };
  // before game begins
  game->reset();
  validMoves = game->getLegalMoves();
  hasValidMoves = true;
  prev_row = -1;
  prev_col = -1;

  gSys->RunChessGame(game->GetBoard());
}

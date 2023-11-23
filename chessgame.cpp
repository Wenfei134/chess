#include "chessgame.h"
#include "board.h"
#include "move.h"
#include "pieces/piece.h"
#include <iostream>
#include <string>

ChessGame::ChessGame()
{
  state = INITIAL;
}

void ChessGame::reset()
{
  if (!setted)
  {
    board.init();
    player_in_turn = PieceColour::kWhite;
  }
  else
  {
    setted = false;
  }
  state = ACTIVE;
}

void ChessGame::setup()
{
  if (!setted)
  {
    board.init();
  }
  setted = true;
}

void ChessGame::takeTurn(Move mv)
{
  if (state != ACTIVE)
  {
    throw std::logic_error("Game is already done");
  }
  board.doMove(mv);
  player_in_turn = player_in_turn == PieceColour::kWhite ? PieceColour::kBlack : PieceColour::kWhite; // white if black, black if white
  if (board.isCheckmated(player_in_turn))
  {
    if (player_in_turn == PieceColour::kWhite)
    {
      state = BLACK_WIN;
    }
    else
    {
      state = WHITE_WIN;
    }
  }
  else if (board.isStalemated(player_in_turn))
  {
    state = STALEMATE;
  }
}

vector<vector<vector<Move>>> ChessGame::getLegalMoves()
{
  vector<vector<vector<Move>>> ret;
  for (int i = 0; i < 8; i++)
  {
    vector<vector<Move>> row;
    for (int j = 0; j < 8; j++)
    {
      row.push_back(vector<Move>{});
    }
    ret.push_back(row);
  }

  vector<Move> legalMoves = board.listLegalMoves(player_in_turn);
  for (auto move : legalMoves)
  {

    int r = move.start->getRow();
    int c = move.start->getCol();

    ret[r][c].push_back(move);
  }

  return ret;
}

int ChessGame::getState()
{
  return state;
}

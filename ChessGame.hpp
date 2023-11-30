#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "Move.hpp"
#include "Pieces/Piece.hpp"

// Fwd declare
class Board;

class ChessGame
{
  Board *mBoard = nullptr;
  int mState = ACTIVE;
  PieceColour mPlayerInTurn = PieceColour::kWhite;

public:
  enum
  {
    ACTIVE = 0,
    WHITE_WIN,
    BLACK_WIN,
    STALEMATE
  };
  ChessGame();
  ~ChessGame();
  void TakeTurn(Move mv);
  std::vector<std::vector<std::vector<Move>>> GetLegalMoves();
  int GetState();

  Board *GetBoard();
};
#endif

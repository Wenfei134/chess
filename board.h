#ifndef BOARD_H
#define BOARD_H
#include "square.h"
#include "move.h"
#include "pieces/piece.h"
#include <vector>
#include <string>
#include <utility>
#include <iostream>

using std::shared_ptr;
using std::string;
using std::vector;

class Board
{
public:
  static const int ROWS = 8;
  static const int COLS = 8;
  static const int NUM_COLOURS = 2;
  static const int NUM_PIECE_TYPES = 6;

private:
  vector<vector<Square>> board;
  vector<shared_ptr<Piece>> pieces[NUM_COLOURS];
  vector<Move> moves_played;
  shared_ptr<Piece> kings[NUM_COLOURS];
  Move getLastMove();
  int getNumMovesPlayed();
  void addPiece(PieceColour colour, PieceType piece, Square *sq);

public:
  Board();
  ~Board();
  void init();
  void empty();
  void doMove(Move &mv);
  void undoMove();
  vector<Move> listLegalMoves(PieceColour colour);
  bool isChecked(PieceColour colour);
  bool isCheckmated(PieceColour colour);
  bool isStalemated(PieceColour colour);

  // Returns a pointer to Square in board at row and col corresponding to coord; ex: "d4", "e4"
  Square *getSquare(int row, int col);

  bool inRange(int row, int col);
  int getRows();
  int getCols();
};
#endif

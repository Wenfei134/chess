#include "board.h"
#include <iostream>
#include <stdexcept>
#include "pieces/bishop.h"
#include "pieces/king.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/piece.h"
#include "pieces/queen.h"
#include "pieces/rook.h"
#include "move.h"

Board::Board()
{
  for (int i = 0; i < ROWS; ++i)
  {
    vector<Square> row;
    board.emplace_back(row);
    for (int j = 0; j < COLS; ++j)
    {
      board.at(i).push_back(Square(i, j));
    }
  }
}

Board::~Board() { empty(); }

void Board::empty()
{
  for (int i = 0; i < NUM_COLOURS; ++i)
  {
    while (pieces[i].size() > 0)
    {
      if (!pieces[i].back()->isDead())
      {
        pieces[i].back()->getPosition()->empty();
      }
      pieces[i].pop_back();
    }
  }
  while (moves_played.size() > 0)
  {
    moves_played.pop_back();
  }
}

void Board::addPiece(PieceColour colour, PieceType piece, Square *sq)
{
  if (colour != PieceColour::kWhite && colour != PieceColour::kBlack)
  {
    throw std::invalid_argument("addPiece: Invalid colour");
  }
  shared_ptr<Piece> new_piece;

  switch (piece)
  {
  case PieceType::kPawn:
    new_piece = std::make_shared<Pawn>(colour, PieceType::kPawn);
    break;
  case PieceType::kKnight:
    new_piece = std::make_shared<Knight>(colour, PieceType::kKnight);
    break;
  case PieceType::kBishop:
    new_piece = std::make_shared<Bishop>(colour, PieceType::kBishop);
    break;
  case PieceType::kRook:
    new_piece = std::make_shared<Rook>(colour, PieceType::kRook);
    break;
  case PieceType::kQueen:
    new_piece = std::make_shared<Queen>(colour, PieceType::kQueen);
    break;
  case PieceType::kKing:
    new_piece = std::make_shared<King>(colour, PieceType::kKing);
    break;
  default:
    throw std::invalid_argument("invalid type of piece");
  }

  sq->empty();
  sq->place(new_piece);

  if (colour == PieceColour::kWhite)
  {
    pieces[0].push_back(new_piece);
  }
  else
  {
    pieces[1].push_back(new_piece);
  }
}

void Board::init()
{
  empty();
  PieceType backrow[COLS] = {PieceType::kRook, PieceType::kKnight, PieceType::kBishop, PieceType::kQueen, PieceType::kKing, PieceType::kBishop, PieceType::kKnight, PieceType::kRook};
  for (int col = 0; col < COLS; ++col)
  {
    addPiece(PieceColour::kBlack, backrow[col], getSquare(0, col));
    addPiece(PieceColour::kBlack, PieceType::kPawn, getSquare(1, col));
    addPiece(PieceColour::kWhite, PieceType::kPawn, getSquare(6, col));
    addPiece(PieceColour::kWhite, backrow[col], getSquare(7, col));
  }
  kings[0] = getSquare(7, 4)->getPiece(); // white king
  kings[1] = getSquare(0, 4)->getPiece(); // black king
}

int Board::getNumMovesPlayed()
{
  return moves_played.size();
}

Move Board::getLastMove()
{
  if (moves_played.size() == 0)
  {
    std::logic_error("getLastMove: No move to pop found");
  }
  return moves_played.back();
}

Square *Board::getSquare(int row, int col)
{
  if (row < 0 || ROWS <= row || col < 0 || COLS <= col)
  {
    throw std::invalid_argument("getSquare(int, int): Square out of range\n");
  }
  return &board[row][col];
}

bool Board::inRange(int row, int col)
{
  if (row < 0 || ROWS <= row || col < 0 || COLS <= col)
  {
    return false;
  }
  return true;
}

int Board::getRows() { return ROWS; }

int Board::getCols() { return COLS; }

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
The functions below are stub functions to implement
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

vector<Move> Board::listLegalMoves(PieceColour colour)
{
  int index;
  if (colour == PieceColour::kWhite)
  {
    index = 0;
  }
  else
  {
    index = 1;
  }
  vector<Move> legalMoves;
  int len = pieces[index].size();
  for (int i = 0; i < len; ++i)
  {
    auto piece = pieces[index][i];
    if (piece->isDead())
    {
      continue;
    }
    vector<Move> pseudo_legal_moves = piece->listPseudoLegalMoves(*this);
    for (auto mv : pseudo_legal_moves)
    {
      doMove(mv);
      if (!isChecked(mv.moving_piece->getColour()))
      {
        legalMoves.push_back(mv);
      }
      undoMove();
    }
  }
  return legalMoves;
}

void Board::doMove(Move &mv)
{
  // implement

  // update relative variables
  // if the moving piece hasn't moved
  if (!mv.moving_piece->getHasMoved())
  {
    mv.moving_piece->setHasMoved(true);
  }

  // record the move
  moves_played.push_back(mv);
}

void Board::undoMove()
{
  if(moves_played.size() == 0){
    return;
  }

  auto mv = moves_played[moves_played.size()-1];
  moves_played.pop_back(); 

  // implement

  if (mv.is_first_move)
  {
    mv.moving_piece->setHasMoved(false);
  }
}

bool Board::isChecked(PieceColour colour)
{
  Square *king_pos;
  if (colour == PieceColour::kWhite)
  {
    king_pos = kings[0]->getPosition();
  }
  else
  {
    king_pos = kings[1]->getPosition();
  }

  // implement
  return false;
}

bool Board::isCheckmated(PieceColour colour)
{
  return false;
}

bool Board::isStalemated(PieceColour colour)
{
  return false;
}

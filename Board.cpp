#include "Board.hpp"
#include "Pieces/Bishop.hpp"
#include "Pieces/King.hpp"
#include "Pieces/Knight.hpp"
#include "Pieces/Pawn.hpp"
#include "Pieces/Queen.hpp"
#include "Pieces/Rook.hpp"

#include <stdexcept>

// --------------------------------------------------------------------------------------------------------------------
Board::Board()
{
  for (int i = 0; i < ROWS; ++i)
  {
    mBoard.emplace_back(std::vector<Square>());
    for (int j = 0; j < COLS; ++j)
    {
      mBoard[i].emplace_back(Square(i, j));
    }
  }

  PieceType backRow[COLS] = {
    PieceType::kRook,
    PieceType::kKnight,
    PieceType::kBishop,
    PieceType::kQueen,
    PieceType::kKing,
    PieceType::kBishop,
    PieceType::kKnight,
    PieceType::kRook
  };
  for (int col = 0; col < COLS; ++col)
  {
    AddPiece(PieceColour::kBlack, backRow[col], GetSquare(0, col));
    AddPiece(PieceColour::kBlack, PieceType::kPawn, GetSquare(1, col));
    AddPiece(PieceColour::kWhite, PieceType::kPawn, GetSquare(6, col));
    AddPiece(PieceColour::kWhite, backRow[col], GetSquare(7, col));
  }
  mKings[0] = GetSquare(7, 4)->GetPiece(); // white king
  mKings[1] = GetSquare(0, 4)->GetPiece(); // black king
}

// --------------------------------------------------------------------------------------------------------------------
Board::~Board()
{
  Empty();
}

// --------------------------------------------------------------------------------------------------------------------
void Board::Empty()
{
  for (int i = 0; i < NUM_COLOURS; ++i)
  {
    while (mPieces[i].size() > 0)
    {
      if (!mPieces[i].back()->IsDead())
      {
        mPieces[i].back()->GetPosition()->Empty();
      }
      mPieces[i].pop_back();
    }
  }
  while (mMovesPlayed.size() > 0)
  {
    mMovesPlayed.pop_back();
  }
}

// --------------------------------------------------------------------------------------------------------------------
void Board::AddPiece(PieceColour colour, PieceType piece, Square *sq)
{
  if (colour != PieceColour::kWhite && colour != PieceColour::kBlack)
  {
    throw std::invalid_argument("AddPiece: Invalid colour");
  }
  std::shared_ptr<Piece> new_piece;

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

  sq->Empty();
  sq->Place(new_piece);

  if (colour == PieceColour::kWhite)
  {
    mPieces[0].push_back(new_piece);
  }
  else
  {
    mPieces[1].push_back(new_piece);
  }
}

// --------------------------------------------------------------------------------------------------------------------
Move Board::GetLastMove()
{
  if (mMovesPlayed.size() == 0)
  {
    std::logic_error("getLastMove: No move to pop found");
  }
  return mMovesPlayed.back();
}

// --------------------------------------------------------------------------------------------------------------------
Square *Board::GetSquare(int row, int col)
{
  if (row < 0 || ROWS <= row || col < 0 || COLS <= col)
  {
    throw std::invalid_argument("GetSquare(int, int): Square out of range\n");
  }
  return &mBoard[row][col];
}

// --------------------------------------------------------------------------------------------------------------------
bool Board::InRange(int row, int col)
{
  if (row < 0 || ROWS <= row || col < 0 || COLS <= col)
  {
    return false;
  }
  return true;
}

// --------------------------------------------------------------------------------------------------------------------
int Board::GetRows()
{ 
  return ROWS; 
}

// --------------------------------------------------------------------------------------------------------------------
int Board::GetCols()
{ 
  return COLS; 
}

// --------------------------------------------------------------------------------------------------------------------
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
The functions below are stub functions to implement
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


// --------------------------------------------------------------------------------------------------------------------
std::vector<Move> Board::ListPseudoLegalMoves(PieceColour colour)
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
  std::vector<Move> pseudoLegalMoves;
  int len = mPieces[index].size();
  for (int i = 0; i < len; ++i)
  {
    auto piece = mPieces[index][i];
    if (piece->IsDead())
    {
      continue;
    }
    std::vector<Move> pseudoLegalMovesForPiece = piece->ListPseudoLegalMoves(this);
    for(auto mv : pseudoLegalMovesForPiece){
      pseudoLegalMoves.push_back(mv);
    }
  }
  return pseudoLegalMoves;
}

// --------------------------------------------------------------------------------------------------------------------
std::vector<Move> Board::ListLegalMoves(PieceColour colour)
{

  auto pseudoLegalMoves = ListPseudoLegalMoves(colour);
  std::vector<Move> legalMoves; 
  for (auto mv : pseudoLegalMoves)
  {
    DoMove(mv);
    if (!IsChecked(mv.mMovingPiece->GetColour()))
    {
      legalMoves.push_back(mv);
    }
    UndoMove();
  }
  return legalMoves;
}

// --------------------------------------------------------------------------------------------------------------------
void Board::DoMove(Move &mv)
{
  // implement

  mv.mStart->Empty();
  mv.mEnd->Place(mv.mMovingPiece);

  // update relative variables
  // if the moving piece hasn't moved
  if (!mv.mMovingPiece->GetHasMoved())
  {
    mv.mMovingPiece->SetHasMoved(true);
  }

  // record the move
  mMovesPlayed.push_back(mv);
}

// --------------------------------------------------------------------------------------------------------------------
void Board::UndoMove()
{
  if(mMovesPlayed.size() == 0){
    return;
  }

  auto mv = mMovesPlayed[mMovesPlayed.size()-1];
  mMovesPlayed.pop_back(); 

  // implement

  mv.mEnd->Empty();
  mv.mStart->Place(mv.mMovingPiece);
  if(mv.mIsAttack){
    mv.mEnd->Place(mv.mKilledPiece);
  }

  if (mv.mIsFirstMove)
  {
    mv.mMovingPiece->SetHasMoved(false);
  }
}

// --------------------------------------------------------------------------------------------------------------------
bool Board::IsChecked(PieceColour colour)
{
  Square *kingPos;
  if (colour == PieceColour::kWhite)
  {
    kingPos = mKings[0]->GetPosition();
  }
  else
  {
    kingPos = mKings[1]->GetPosition();
  }

  // implement

  PieceColour oppositeColour = PieceColour::kWhite;
  if(colour == PieceColour::kWhite){
    oppositeColour = PieceColour::kBlack;
  }

  auto moves = ListPseudoLegalMoves(oppositeColour);

  for(auto mv: moves){
    if(mv.mEnd == kingPos){
      return true;
    }
  }

  return false;
}

// --------------------------------------------------------------------------------------------------------------------
bool Board::IsCheckmated(PieceColour colour)
{
  if(ListLegalMoves(colour).empty() && IsChecked(colour)){
    return true;
  }
  return false;
}

// --------------------------------------------------------------------------------------------------------------------
bool Board::IsStalemated(PieceColour colour)
{
  if(ListLegalMoves(colour).empty() && !IsChecked(colour)){
    return true;
  }
  return false;
}

// --------------------------------------------------------------------------------------------------------------------

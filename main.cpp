#include "chesscontroller.h"
#include "Graphics/ChessGraphicsSystem.hpp"
#include <iostream>

int main(int argv, char** args)
{
  ChessGraphicsSystem *gSys = nullptr;
  try {
      gSys = new ChessGraphicsSystem();
  } catch (const char *errMsg) {
      printf(errMsg);
      return -1;
  }

  ChessGame *game = new ChessGame(); 

  ChessController c = ChessController(gSys, game);
  c.start();

  delete game;
  delete gSys;
  return 0;
}

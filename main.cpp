#include "chesscontroller.h"
#include "Graphics/ChessGraphicsSystem.hpp"
#include <iostream>

int main(int argv, char** args)
{
  ChessController *c = new ChessController();
  c->Start();

  delete c;
  return 0;
}

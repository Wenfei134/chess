#include "ChessController.hpp"

// --------------------------------------------------------------------------------------------------------------------
int main(int argv, char** args)
{
  ChessController *c = new ChessController();
  c->Start();

  delete c;
  return 0;
}

// --------------------------------------------------------------------------------------------------------------------
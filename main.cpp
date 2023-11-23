#include "chesscontroller.h"
#include <iostream>

int main()
{
  ChessControler c = ChessControler();
  c.start();
  // c.print();
  c.handleClick(6, 3);
  c.handleClick(4, 3);
}

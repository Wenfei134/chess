#ifndef CLICKABLEBUTTON_HPP
#define CLICKABLEBUTTON_HPP

#include <vector>
#include "../move.h"

// Fwd declare
class ChessController;

class ClickEventHandler
{
    public:
        void HandleClickEvent(int clickX, int clickY);
        void Render(std::vector<Move> legalMoves);

    private:
        // Hues all legal move squares as blue given a selected piece
        void RenderBlueLegalMoves(std::vector<Move> legalMoves);

        ChessController *mController;
};

#endif
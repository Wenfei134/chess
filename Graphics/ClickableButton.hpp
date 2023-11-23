#ifndef CLICKABLEBUTTON_HPP
#define CLICKABLEBUTTON_HPP

#include <SDL.h>
#include <vector>

class ClickableButton
{
    public:
        ClickableButton();

        SDL_Point GetPosition();
        void HandleEvent(SDL_Event* e);
        void Render(std::vector<Move> legalMoves);
        void SetPosition(int x, int y);

    private:
        SDL_Point mPosition;

        // Hues all legal move squares as blue given a selected piece
        void RenderBlueLegalMoves(std::vector<Move> legalMoves);
};

#endif
#ifndef CLICKABLEBUTTON_HPP
#define CLICKABLEBUTTON_HPP

#include <SDL.h>
#include <vector>
#include "../move.h"

enum LButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

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
        LButtonSprite mCurrentTexture;

        // Hues all legal move squares as blue given a selected piece
        void RenderBlueLegalMoves(std::vector<Move> legalMoves);
};

#endif
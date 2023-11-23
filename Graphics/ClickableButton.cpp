#include "ClickableButton.hpp"

// --------------------------------------------------------------------------------------------------------------------
ClickableButton::ClickableButton() : mPosition({0,0}), mCurrentTexture(BUTTON_SPRITE_MOUSE_OUT) {}

// --------------------------------------------------------------------------------------------------------------------
SDL_Point ClickableButton::GetPosition() {
    return mPosition;
}

// --------------------------------------------------------------------------------------------------------------------
void ClickableButton::HandleEvent(SDL_Event* e) {
    
}

// --------------------------------------------------------------------------------------------------------------------
void ClickableButton::Render(std::vector<Move> legalMoves)


// --------------------------------------------------------------------------------------------------------------------
void ClickableButton::SetPosition(int x, int y) {
    mPosition = {x, y};
}
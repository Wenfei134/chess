#ifndef CHESSGRAPHICSSYSTEM_H
#define CHESSGRAPHICSSYSTEM_H

#include "ChessTexture.hpp"
#include "../pieces/piece.h"
#include <SDL.h>

// Fwd Declare
class Board;

class ChessGraphicsSystem {

    public:

        ChessGraphicsSystem();
        ~ChessGraphicsSystem();

        void Render(Board *board);
        // Creates the game window, renders the game, and listens for input until exit
        void RunChessGame(Board *board);

    private:
        // Textures for chess board and chess pieces sprite sheet
        ChessTexture mChessPiecesSpriteSheetTexture;
        ChessTexture mChessBoardTexture;

        //The window we'll be rendering to
        SDL_Window* mWindow = NULL;

        //The window renderer
        SDL_Renderer* mRenderer = NULL;

        // The bounding rectangles to use on the chess pieces sprite sheet
        SDL_Rect mChessPiecesTexturesBoundingRects[12];

        SDL_Point ConvertGridCoordinatesToSDLCoordinates(int x, int y);
        // Gets correct index of bounding rectangle to render given the color and type of the piece
        int GetChessFigureTextureBoundingRectIndex(PieceColour pieceColour, PieceType pieceType);
        // Loads all the required textures
        void LoadAllMedia();
        // Helper function for RunChessGame to render the chess board given the current state 
        void RenderBoardState(Board *board);
};

#endif
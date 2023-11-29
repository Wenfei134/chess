#include "../chesscontroller.h"
#include "ClickEventHandler.hpp"
#include "GraphicsConstants.hpp"


// --------------------------------------------------------------------------------------------------------------------
void ClickEventHandler::HandleClickEvent(int clickX, int clickY) {
    if (clickX > OFFSET_FROM_EDGE_OF_BOARD && clickX < SCREEN_WIDTH - OFFSET_FROM_EDGE_OF_BOARD && 
        clickY > OFFSET_FROM_EDGE_OF_BOARD && clickY < SCREEN_HEIGHT - OFFSET_FROM_EDGE_OF_BOARD) {
        clickX -= OFFSET_FROM_EDGE_OF_BOARD;
        clickY -= OFFSET_FROM_EDGE_OF_BOARD;

        // Row and column switched with X and Y because of how SDL 2 grid coordinates work
        int chessTileRow = clickY / CHESS_TILE_SIZE;
        int chessTileColumn = clickX / CHESS_TILE_SIZE;

        // TODO: Call controller handleClick with chessTileRow and column, maybe we should do observer for this?

    }
}

// --------------------------------------------------------------------------------------------------------------------
void ClickEventHandler::Render(std::vector<Move> legalMoves) {

}


// --------------------------------------------------------------------------------------------------------------------

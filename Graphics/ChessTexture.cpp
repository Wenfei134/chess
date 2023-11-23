#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "ChessTexture.hpp"

// --------------------------------------------------------------------------------------------------------------------
// Following RAII, a ChessTexture should be ready to use without any further initialization after this.
ChessTexture::ChessTexture(SDL_Renderer *renderer) : mTexture(nullptr), mWidth(0), mHeight(0), mRenderer(renderer) {}

// --------------------------------------------------------------------------------------------------------------------
ChessTexture::~ChessTexture() {
	if(mTexture)
	{
		SDL_DestroyTexture( mTexture );
		mTexture = nullptr;
	}
}

// --------------------------------------------------------------------------------------------------------------------
int ChessTexture::GetWidth() {
    return mWidth;
}

// --------------------------------------------------------------------------------------------------------------------
int ChessTexture::GetHeight() {
    return mHeight;
}

// --------------------------------------------------------------------------------------------------------------------
bool ChessTexture::LoadTextureFromFile(std::string path) {
    // Reset the texture if it exists
    if (mTexture) {
        SDL_DestroyTexture( mTexture );
		mTexture = nullptr;
        mHeight = 0;
        mWidth = 0;
    }

    // The final texture
	SDL_Texture* newTexture = nullptr;

	// Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if (!loadedSurface)
	{
		printf("Unable to load image at %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
		if(!newTexture)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			// Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		// Get rid of the no longer needed surface
		SDL_FreeSurface(loadedSurface);
	}

	mTexture = newTexture;

    // Returns false if the texture is null
	return mTexture;
}

// --------------------------------------------------------------------------------------------------------------------
void ChessTexture::Render(int x, int y, SDL_Rect* sourceSizeRect) {
    // Create the render rectangle window - (x,y) coords and then (width,height) dimensions
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	// If there's a specific snippet we want, we take from sourceSizeRect
	if (sourceSizeRect)
	{
		renderQuad.w = sourceSizeRect->w;
		renderQuad.h = sourceSizeRect->h;
	}

	//Render to screen
	SDL_RenderCopy(mRenderer, mTexture, sourceSizeRect, &renderQuad);
}

// --------------------------------------------------------------------------------------------------------------------
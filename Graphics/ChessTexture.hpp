/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/
#ifndef CHESSTEXTURE_HPP
#define CHESSTEXTURE_HPP

#include <string>

//Fwd declaration so we can use pointers to these classes in this file without having to import the libraries they come from
class SDL_Rect;
class SDL_Texture;
class SDL_Renderer;

class ChessTexture
{
	public:
		ChessTexture(SDL_Renderer *renderer);
		~ChessTexture();

        //Gets image dimensions
		int GetWidth();
		int GetHeight();

        //Loads png texture image from file
		bool LoadTextureFromFile(std::string path);

		//Renders texture at given point
		void Render(int x, int y, SDL_Rect* sourceSizeRect = nullptr);


	private:
		// png texture image
		SDL_Texture *mTexture;

		// Image dimensions
		int mWidth;
		int mHeight;

        // Renderer to use
        SDL_Renderer *mRenderer;
};

#endif
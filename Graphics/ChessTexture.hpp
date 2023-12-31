#ifndef CHESSTEXTURE_HPP
#define CHESSTEXTURE_HPP

#include <string>

// Fwd declaration so we can use pointers to these classes in this file without having to import the libraries they come from
struct SDL_Rect;
struct SDL_Texture;
struct SDL_Renderer;

class ChessTexture
{
public:
  ChessTexture(SDL_Renderer *renderer);
  ~ChessTexture();

  // Loads png texture image from file
  bool LoadTextureFromFile(std::string path);

  // Renders texture at given point
  void Render(int x, int y, SDL_Rect *sourceSizeRect = nullptr);

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

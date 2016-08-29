//
// Created by SJ Holland on 4/3/16.
//

#ifndef SPACEGAME_GAMETEXTURE_H
#define SPACEGAME_GAMETEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>

//Texture wrapper class
class GameTexture
{
public:
    //Initializes variables
    GameTexture();

    //Deallocates memory
    ~GameTexture();

    //Loads image at specified path
    bool loadFromFile(std::string path, SDL_Renderer *gRenderer);

    // TODO: rule of three

#ifdef _SDL_TTF_H
    //Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
#endif

    //Deallocates texture
    void free();

    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );

    //Set blending
    void setBlendMode( SDL_BlendMode blending );

    //Set alpha modulation
    void setAlpha( Uint8 alpha );

    //Renders texture at given point
    void render( int x, int y, SDL_Renderer* gRenderer = NULL, SDL_Rect* clip = NULL,
                 double angle = 0.0, SDL_Point* center = NULL,
                 SDL_RendererFlip flip = SDL_FLIP_NONE);

    //Renders texture at given point
    void render( SDL_Rect target, SDL_Renderer* gRenderer = NULL, SDL_Rect* clip = NULL,
                 double angle = 0.0, SDL_Point* center = NULL,
                 SDL_RendererFlip flip = SDL_FLIP_NONE);

    //Gets image dimensions
    int getWidth();

    int getHeight();

private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;
};


#endif //SPACEGAME_GAMETEXTURE_H

//
// Created by SJ Holland on 4/3/16.
//

#ifndef SDTTEST_LTEXTURE_H
#define SDTTEST_LTEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>

//Texture wrapper class
class LTexture
{
public:
    //Initializes variables
    LTexture();

    //Deallocates memory
    ~LTexture();

    //Loads image at specified path
    bool loadFromFile( std::string path, SDL_Renderer* gRenderer );

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

    // Render texture at given point, using a clip specified by name.
    // Returns 0 if successful, or 1 if the name was not found.
    // If the clip_name is null or empty, render the whole texture.
    int renderClipByIndex(int x, int y, SDL_Renderer *gRenderer = NULL, size_t clip_index = 0,
                          double angle = 0.0, SDL_Point *center = NULL,
                          SDL_RendererFlip flip = SDL_FLIP_NONE);

    //Gets image dimensions
    int getWidth();
    int getHeight();

    size_t addClip(int x, int y, int w, int h);

private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;

    std::vector<SDL_Rect> clips;
};


#endif //SDTTEST_LTEXTURE_H

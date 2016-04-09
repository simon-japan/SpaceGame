/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, strings, and file streams
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <fstream>
#include "View/LTexture.h"
#include "Model/Tile.h"
#include "Model/Dot.h"
#include "View/SpriteSheet.h"
#include "View/Renderer.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The dimensions of the level
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;

//Tile constants
const int TOTAL_TILES = 192;
const int TOTAL_TILE_SPRITES = 12;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia( std::vector<Tile> & tiles );

//Frees media and shuts down SDL
void close( );

//Sets tiles from tile map
bool setTiles( std::vector<Tile> & tiles );

void addSprite(SpriteSheet & sheet, int x, int y, int w, int h, std::string name, SpriteRepository & spriteRepository);

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

//Scene textures
LTexture gDotTexture;
LTexture gTileTexture;

using namespace std;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia( std::vector<Tile> & tiles)
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	if( !gDotTexture.loadFromFile( "/Users/simon/Desktop/images/dot.bmp", gRenderer ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	//Load tile texture
	if( !gTileTexture.loadFromFile( "/Users/simon/Desktop/images/tiles.png", gRenderer ) )
	{
		printf( "Failed to load tile set texture!\n" );
		success = false;
	}

    // Todo: put this somewhere else
	//Load tile map
	if( !setTiles( tiles ) )
	{
		printf( "Failed to load tile set!\n" );
		success = false;
	}

	return success;
}

void close( /*std::vector<Tile> tiles*/ )
{
	//Deallocate tiles
    /*
	for( int i = 0; i < TOTAL_TILES; ++i )
	{
		if( tiles[ i ] == NULL )
		{
			delete tiles[ i ];
			tiles[ i ] = NULL;
		}
	}
     */

	//Free loaded images
	gDotTexture.free();
	gTileTexture.free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}



bool setTiles( vector<Tile> & tiles )
{

    static vector<string> tile_types = {
            "tile_red",
            "tile_green",
            "tile_blue",
            "tile_topleft",
            "tile_left",
            "tile_bottomleft",
            "tile_top",
            "tile_center",
            "tile_bottom",
            "tile_topright",
            "tile_right",
            "tile_bottomright"
    };

    static vector<string> tangible_tile_types = {
            "tile_topleft",
            "tile_left",
            "tile_bottomleft",
            "tile_top",
            "tile_center",
            "tile_bottom",
            "tile_topright",
            "tile_right",
            "tile_bottomright"
    };

	//Success flag
	bool tilesLoaded = true;

	//The tile offsets
	int x = 0, y = 0;

	//Open the map
	std::ifstream map( "/Users/simon/Desktop/lazy.map" );

	//If the map couldn't be loaded
	if( !map.is_open() )
	{
		printf( "Unable to load map file!\n" );
		tilesLoaded = false;
	}
	else
	{
		//Initialize the tiles
		for( int i = 0; i < TOTAL_TILES; ++i )
		{
			//Determines what kind of tile will be made
			int tileType = -1;

			//Read tile from map file
			map >> tileType;

			//If the was a problem in reading the map
			if( map.fail() )
			{
				//Stop loading map
				printf( "Error loading map: Unexpected end of file!\n" );
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if( ( tileType >= 0 ) && ( tileType < TOTAL_TILE_SPRITES ) )
			{
                string tileTypeName(tile_types[tileType]);
                bool isTangible = (find (tangible_tile_types.begin(), tangible_tile_types.end(), tileTypeName) !=
                        tangible_tile_types.end());
				tiles.push_back( Tile( x, y, tileTypeName, isTangible));
			}
				//If we don't recognize the tile type
			else
			{
				//Stop loading map
				printf( "Error loading map: Invalid tile type at %d!\n", i );
				tilesLoaded = false;
				break;
			}

			//Move to next tile spot
			x += TILE_WIDTH;

			//If we've gone too far
			if( x >= LEVEL_WIDTH )
			{
				//Move back
				x = 0;

				//Move to the next row
				y += TILE_HEIGHT;
			}
		}

	}

	//Close the file
	map.close();

	//If the map was loaded fine
	return tilesLoaded;
}

void addSprite(SpriteSheet & sheet, int x, int y, int w, int h, string name, SpriteRepository & spriteRepository)
{
    SDL_Rect clip;
    clip.x = x;
    clip.y = y;
    clip.w = w;
    clip.h = h;
    sheet.addClip(name, clip);
    spriteRepository.addSprite(sheet, name);
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//The level tiles
        std::vector<Tile> tileSet;

		//Load media
		if( !loadMedia( tileSet ) )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			Dot dot;

            //Level keeps track of the bounds of the world and the set of tiles (pretty simple model)
            Level level (LEVEL_WIDTH, LEVEL_HEIGHT, tileSet);

			//Level camera
			SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

            //One sprite sheet for all the tiles
            SpriteSheet tileSpriteSheet(&gTileTexture);

            //Although there is only one clip for the dot sprite (for now), I will use a sprite sheet for it.
            SpriteSheet dotSpriteSheet(&gDotTexture);

            //This object will provide references to sprite objects indexed by name
            SpriteRepository spriteRepository;

            // Create all the sprites in the sprite repository
            // Todo: this should not be hard coded: load it from a file
            addSprite(tileSpriteSheet, 0, 0, TILE_WIDTH, TILE_HEIGHT, "tile_red", spriteRepository);
            addSprite(tileSpriteSheet, 0, 80, TILE_WIDTH, TILE_HEIGHT, "tile_green", spriteRepository);
            addSprite(tileSpriteSheet, 0, 160, TILE_WIDTH, TILE_HEIGHT, "tile_blue", spriteRepository);
            addSprite(tileSpriteSheet, 80, 0, TILE_WIDTH, TILE_HEIGHT, "tile_topleft", spriteRepository);
            addSprite(tileSpriteSheet, 80, 80, TILE_WIDTH, TILE_HEIGHT, "tile_left", spriteRepository);
            addSprite(tileSpriteSheet, 80, 160, TILE_WIDTH, TILE_HEIGHT, "tile_bottomleft", spriteRepository);
            addSprite(tileSpriteSheet, 160, 0, TILE_WIDTH, TILE_HEIGHT, "tile_top", spriteRepository);
            addSprite(tileSpriteSheet, 160, 80, TILE_WIDTH, TILE_HEIGHT, "tile_center", spriteRepository);
            addSprite(tileSpriteSheet, 160, 160, TILE_WIDTH, TILE_HEIGHT, "tile_bottom", spriteRepository);
            addSprite(tileSpriteSheet, 240, 0, TILE_WIDTH, TILE_HEIGHT, "tile_topright", spriteRepository);
            addSprite(tileSpriteSheet, 240, 80, TILE_WIDTH, TILE_HEIGHT, "tile_right", spriteRepository);
            addSprite(tileSpriteSheet, 240, 160, TILE_WIDTH, TILE_HEIGHT, "tile_bottomright", spriteRepository);

            // Don't forget the dot!
            addSprite(dotSpriteSheet, 0, 0, dot.DOT_WIDTH, dot.DOT_HEIGHT, "dot", spriteRepository);

            // The renderer is the top-level "view" object.
            // It can render a whole scene: you give it the camera and the level (and for now, just a dot)
            // It will use the sprite repository to find the sprite for each object it needs to render,
            // and uses the SDL renderer
            Renderer renderer(gRenderer, spriteRepository);

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

					//Handle input for the dot
					dot.handleEvent( e );
				}

				//Move the dot
				dot.move( tileSet, &level );
				dot.setCamera( camera, &level, SCREEN_WIDTH, SCREEN_HEIGHT);

				renderer.renderAll(camera, level, dot);

			}
		}

		//Free resources and close SDL
		close( /*tileSet*/ );
	}

	return 0;
}
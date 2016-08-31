/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, strings, and file streams
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <fstream>
#include "View/GameTexture.h"
#include "Model/Tile.h"
#include "Model/Character.h"
#include "View/Renderer.h"
#include "Serialization/SpriteLoader.h"
#include "Serialization/LevelLoader.h"
#include "Controller/GameController.h"
#include "Controller/CameraController.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

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
		gWindow = SDL_CreateWindow( "Simon's Space Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
									SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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

void close()
{
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
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
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//Level camera
		SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

        //SpriteRepository owns all the textures loaded in memory. They can be retrieved from it by name.
        TextureRepository textureRepository;

		//SpriteRepository owns all the sprite objects. They can be retrieved from it by name.
		SpriteRepository spriteRepository;

		SpriteLoader spriteLoader(textureRepository, spriteRepository, gRenderer);
		spriteLoader.loadSprites("configuration/sprites.xml");

        // The level is the root element of the Model.
        // It is loaded from configuration by a LevelLoader.
        // For now, it is created & destroyed in the main loop. Currently there's only one level.
		LevelLoader levelLoader;
		unique_ptr<Level> levelPtr(levelLoader.loadLevel("configuration/map.xml"));

		//The player's avatar is a special character that is always loaded, regardless of the level.
		auto player = make_shared<Character>(50, 50, 0, 0, std::string("Player"));
        levelPtr->addCharacter(player);

        // The GameController responds to user input (all it does at the moment is to move the avatar around).
        // Todo: add any more required functionality here
        GameController gameController(*player);

		// The renderer is the top-level "view" object.
		// It can render a whole scene: you give it the camera and the level (which contains all renderable objects)
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

				//Handle input from the player
                gameController.handlePlayerInput(e);
			}

            // Update the player model's position based on its updated velocity + collision detection.
			player->move( *levelPtr ); // Todo: invoke this in a more systematic way

			// Todo: AI
			// Todo: interactions between characters

            // The camera constantly centers on the player, modulo the boundaries of the level.
            CameraController::setCameraOnCharacter(camera, *levelPtr, *player, SCREEN_WIDTH, SCREEN_HEIGHT);

            // Render everything in the level that is visible to the camera
            renderer.renderLevel(camera, *levelPtr);
		}

		//Free resources and close SDL
		close( /*tileSet*/ );
	}

	return 0;
}


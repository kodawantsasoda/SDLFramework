#include <stdio.h>
#include <SDL.h>
#include "ScreenOrganizer.h"

//Screen dimension constants

int main(int argc, char* args[])
{
	ScreenOrganizer* game = ScreenOrganizer::Instance();

	//Destroy window
	game->Release();

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	return 0;
}

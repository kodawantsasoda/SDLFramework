#include "GameWindow.h"

GameWindow* GameWindow::gwInstance = NULL;
//Initializing to false
bool GameWindow::gwInitialized = false;

GameWindow* GameWindow::Instance() {

	//Create a new instance if no instance was created before
	if (gwInstance == NULL)

		gwInstance = new GameWindow();

	return gwInstance;

}

void GameWindow::Release() {

	delete gwInstance;
	gwInstance = NULL;

	gwInitialized = false;

}

bool GameWindow::Initialized() {

	return gwInitialized;

}

GameWindow::GameWindow() {

	quitGame = false;
	gwInitialized = Init();

}

GameWindow::~GameWindow() {

	//the sdl documentation requires me to destroy the renderer before the window... otherwise i get big boi errors after closing the window
	SDL_DestroyRenderer(gwRenderer);
	gwRenderer = NULL;

	SDL_FreeSurface(gwSurface);
	gwSurface = NULL;

	SDL_DestroyWindow(gwWindow);
	gwWindow = NULL;

}

bool GameWindow::Init() {

	//Initialize SDL Video and Audio and handling initialization errors
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {

		printf("SDL Initialization Error: %s\n", SDL_GetError());
		return false;
	}

	//Creating the window
	gwWindow = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	//Handling with window creation errors
	if (gwWindow == NULL) {
		printf("Window Creation Error: %s\n", SDL_GetError());
		return false;
	}

	//Creating the renderer
	gwRenderer = SDL_CreateRenderer(gwWindow, -1, SDL_RENDERER_ACCELERATED);

	//Handling with the renderer creation errors
	if (gwRenderer == NULL) {
		printf("Renderer Creation Error: %s\n", SDL_GetError());
		return false;
	}

	gwSurface = SDL_GetWindowSurface(gwWindow);

	if (gwSurface == NULL) {
		printf("Surface Creation Error: %s\n", SDL_GetError());
		return false;
	}

	//Setting the renderer's clear color to whit
	SDL_SetRenderDrawColor(gwRenderer, 0x00, 0x00, 0x00, 0xFF);

	//Initializing the SDL_image library and handling initialization errors
	int flags = IMG_INIT_PNG;
	if(!(IMG_Init(flags) & flags)) {

		printf("IMG Initialization Error: %s\n", IMG_GetError());
		return false;
	}

	/*
	//Initializing the SDL_ttf library and handling initialization errors
	if(TTF_Init() == -1) {

		printf("TTF Initialization Error: %s\n", TTF_GetError());
		return false;
	}
	*/

	//return true if no errors occurred during initialization
	return true;

}

void GameWindow::blackScreen() {

	if (gwInitialized == true) {

		SDL_FillRect(gwSurface, NULL, SDL_MapRGB(gwSurface->format, 0x00, 0x00, 0x00));
		SDL_UpdateWindowSurface(gwWindow);

	}

	else {

		printf("SDL Window Initialization Error: Window and or Surface needs to be Initialized before updating it...");

	}
	
}

SDL_Surface* GameWindow::getWindowSurface() {

	return gwSurface;

}

SDL_Window* GameWindow::getWindow() {

	return gwWindow;

}

SDL_Renderer* GameWindow::getRenderer() {

	return gwRenderer;

}
#include "ScreenOrganizer.h"

ScreenOrganizer* ScreenOrganizer::soInstance = NULL;

ScreenOrganizer* ScreenOrganizer::Instance(){

	if (soInstance == NULL) {
		soInstance = new ScreenOrganizer();
	}
	return soInstance;
}

void ScreenOrganizer::Release() {
	
	delete soInstance;
	soInstance = NULL;
}

ScreenOrganizer::ScreenOrganizer() {

	masterWindow = GameWindow::Instance();

	masterLoader = Loader::Instance();

	ManageGameRun();
}

ScreenOrganizer::~ScreenOrganizer() {

	GameWindow::Release();
	masterWindow = NULL;

	Loader::Release();
	masterLoader = NULL;

}

void ScreenOrganizer::imageToScreen(std::string path) {

}

void ScreenOrganizer::ManageGameRun() {

	masterWindow->blackScreen(); 

	masterLoader->loadSomeMedia("hello_world.bmp");

	SDL_BlitSurface(masterLoader->pathToSurface, NULL, masterWindow->getWindowSurface(), NULL);

	SDL_UpdateWindowSurface(masterWindow->getWindow());

	masterWindow->KeepWindowOpen(); //mayneed to rethink this... i think this function needs to be last in order to keep the window open
	
}
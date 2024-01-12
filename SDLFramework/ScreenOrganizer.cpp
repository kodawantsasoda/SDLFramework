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

	essentials = GameEssentials::Instance();

	//delete these eventually
	masterWindow = GameWindow::Instance();

	masterLoader = Loader::Instance();
	//

	ManageGameRun();
}

ScreenOrganizer::~ScreenOrganizer() {

	GameEssentials::Release();
	essentials = NULL;

	GameWindow::Release();
	masterWindow = NULL;

	Loader::Release();
	masterLoader = NULL;

}

void ScreenOrganizer::imageToScreen(std::string path) {

}

void ScreenOrganizer::ManageGameRun() {

	masterWindow->blackScreen();
	
	SDL_ShowCursor(SDL_DISABLE);

	while (quitGame == false) {
		while (SDL_PollEvent(&eventCapture)) {

			if (eventCapture.type == SDL_QUIT)
				
				quitGame = true;
			
			if (eventCapture.type == SDL_KEYDOWN) {
				
				if (eventCapture.key.keysym.sym == SDLK_SPACE) {

					essentials->createTexture("chicken.jpg");

					//centering chimken
					essentials->renderTexture("chicken.jpg", (GameWindow::Instance()->SCREEN_WIDTH - 350) / 2, (GameWindow::Instance()->SCREEN_HEIGHT - 350) / 2, 350, 350);

					SDL_ShowCursor(SDL_ENABLE);

				}
			}	
		}
	}
	
}
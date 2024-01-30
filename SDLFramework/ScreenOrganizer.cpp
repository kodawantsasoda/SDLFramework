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

void ScreenOrganizer::addBeforeGameRun() {

	//clips
	SDL_Rect temp;
	temp.x = 100;
	temp.y = 100;
	temp.w = 150;
	temp.h = 350;

	collectionOfClippedRects["Chicken"] = temp;

}

void ScreenOrganizer::ManageGameRun() {

	addBeforeGameRun();

	masterWindow->blackScreen();
	
	SDL_ShowCursor(SDL_DISABLE);

	while (quitGame == false) {
		while (SDL_PollEvent(&eventCapture)) {

			if (eventCapture.type == SDL_QUIT)
				
				quitGame = true;
			
			if (eventCapture.type == SDL_KEYDOWN) {
				
				if (eventCapture.key.keysym.sym == SDLK_SPACE) {

					essentials->createOrReturnPreviousTexture("chicken.jpg");

					//centering chimken
					//essentials->setRenderViewport((GameWindow::Instance()->SCREEN_WIDTH - 350) / 2, (GameWindow::Instance()->SCREEN_HEIGHT - 350) / 2, 350, 350);

					essentials->renderTexture("chicken.jpg", (GameWindow::Instance()->SCREEN_WIDTH - 150) / 2, (GameWindow::Instance()->SCREEN_HEIGHT - 350) / 2, &collectionOfClippedRects["Chicken"]);

					//essentials->renderTexture("chicken.jpg");

					SDL_ShowCursor(SDL_ENABLE);

				}
			}	
		}

		essentials->Render();

	}

	
}
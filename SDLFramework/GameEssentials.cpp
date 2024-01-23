#include "GameEssentials.h"

GameEssentials* GameEssentials::geInstance = NULL;

GameEssentials* GameEssentials::Instance() {

	if (geInstance == NULL)

		geInstance = new GameEssentials();

	return geInstance;

}

void GameEssentials::Release() {

	delete geInstance;
	geInstance = NULL;

}

GameEssentials::GameEssentials() {

	currentTexture = NULL;

	textureRect = NULL;

	currentSurfaceWidth = 0;

	currentSurfaceHeight = 0;

}

GameEssentials::~GameEssentials() {

	for (auto x : collectionOfTextures) {

		if (x.second != NULL) {
			
			SDL_DestroyTexture(x.second);

		}
	}

	collectionOfTextures.clear();

	SDL_DestroyTexture(currentTexture);
	currentTexture = NULL;

	currentSurfaceWidth = 0;

	currentSurfaceHeight = 0;

	textureRect = NULL;

}

SDL_Texture* GameEssentials::createTexture(std::string path) {

	currentTexture = NULL;

	textureRect = NULL;

	currentSurfaceWidth = 0;

	currentSurfaceHeight = 0;

	if (collectionOfTextures[path]) {

		setSurfaceDimensions();

		return collectionOfTextures[path];

	}

	Loader::Instance()->loadTexture(path);

	if (Loader::Instance()->loaded() == true) {

		currentTexture = SDL_CreateTextureFromSurface(GameWindow::Instance()->getRenderer(), Loader::pathToSurface);

		if (currentTexture == NULL) {

			printf("SDL Error: could not create texture from renderer and/or surface!");

			return NULL;

		}

		collectionOfTextures[path] = currentTexture;

	}

	else {

		printf("SDL ERROR: Could not create texture by loading!");

	}

	setSurfaceDimensions();

	//i need to figure this out... hmmmm.... I get an after compilation error
	//SDL_FreeSurface(Loader::Instance()->pathToSurface);

	return currentTexture; 

}

//need to add SDL_Rect to RenderCopy
void GameEssentials::renderTexture(std::string path) {

	if (collectionOfTextures[path] == NULL) {

		printf("Error rendering texture: texture has not been created yet. Please call createTexture and ensure the path is correct.");

	}

	else {
		printf("pap-a");
	}

	SDL_RenderClear(GameWindow::Instance()->getRenderer());

	//**note textureRect = NULL if renderTexture(path, x, y) or renderTexture(path, x, y, w, h were not called
	SDL_RenderCopy(GameWindow::Instance()->getRenderer(), collectionOfTextures[path], NULL, NULL);

}

//need to add sdl rect 1/14
void GameEssentials::setRenderViewport(std::string path, int x, int y, int w, int h) {

	bool viewPortRenderSuccess = GameWindow::Instance()->setRenderViewPort(x, y, w, h);

	if (viewPortRenderSuccess == false) {

		printf("The attempt to render texture with a viewport failed!");

	}

}

int GameEssentials::getCurrentSurfaceWidth() {

	return currentSurfaceWidth;

}

int GameEssentials::getCurrentSurfaceHeight() {

	return currentSurfaceHeight;

}

void GameEssentials::setSurfaceDimensions() {

	currentSurfaceWidth = Loader::pathToSurface->w;

	currentSurfaceHeight = Loader::pathToSurface->h;

}

void GameEssentials::setSurfaceDimensions(int w, int h) {

	textureRect = NULL;

	currentSurfaceWidth = w;

	currentSurfaceHeight = h;

}

void GameEssentials::setTextureRect(int x, int y, int w, int h) {

	textureRect->x = x;
	textureRect->y = y;

	if (w != NULL && h != NULL) {

		textureRect->w = getCurrentSurfaceWidth();
		textureRect->h = getCurrentSurfaceHeight();

	}
	
	//else w and h == NULL

}

void GameEssentials::Render() {

	SDL_RenderPresent(GameWindow::Instance()->getRenderer());

}


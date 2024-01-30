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

	textureRect = new SDL_Rect();

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

	delete textureRect;

}

SDL_Texture* GameEssentials::createOrReturnPreviousTexture(std::string path) {

	currentTexture = NULL;

	currentSurfaceWidth = 0;

	currentSurfaceHeight = 0;

	Loader::Instance()->loadTexture(path);

	if (Loader::Instance()->loaded() == true) {

		if (collectionOfTextures[path]) {

			setSurfaceDimensions();

			return collectionOfTextures[path];

		}

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

//this renders the ENTIRE texture. SDL_Render
void GameEssentials::renderTexture(std::string path) {

	if (collectionOfTextures[path] == NULL) {

		printf("Error rendering texture: texture has not been created yet. Please call createTexture and ensure the path is correct.");

	}

	SDL_RenderClear(GameWindow::Instance()->getRenderer());

	SDL_RenderCopy(GameWindow::Instance()->getRenderer(), collectionOfTextures[path], NULL, NULL);

}

void GameEssentials::renderTexture(std::string path, int x, int y, SDL_Rect* clipRect) {

	if (collectionOfTextures[path] == NULL) {

		printf("Error rendering texture: texture has not been created yet. Please call createTexture and ensure the path is correct.");

	}

	//needed to load the texture up with its dimensions
	createOrReturnPreviousTexture(path);

	//if we are clipping the texture, we should set the width and height as the same dimensions for destination rectangle and source rectangle
	if (clipRect != NULL) {

		setTextureRect(x, y, clipRect->w, clipRect->h);
		printf("papa");

	}

	else {

		setTextureRect(x, y);

	}

	SDL_RenderClear(GameWindow::Instance()->getRenderer());

	//remember; the paraeters of SDL_RenderCopy is the renderer, the texture, the source rectangle, and the destination rectangle
	SDL_RenderCopy(GameWindow::Instance()->getRenderer(), collectionOfTextures[path], clipRect, textureRect);

}

void GameEssentials::setRenderViewport(int x, int y, int w, int h) {

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

	int w, h;

	SDL_QueryTexture(currentTexture, NULL, NULL, &w, &h);

	currentSurfaceWidth = w;

	currentSurfaceHeight = h;

}

void GameEssentials::setTextureRect(int x, int y, int w, int h) {

	textureRect->x = x;
	textureRect->y = y;

	//if NULL, default the rectangle to the size of the surface
	if (w == NULL || h == NULL) {

		textureRect->w = getCurrentSurfaceWidth();
		textureRect->h = getCurrentSurfaceHeight();

	}

	//this will be used more often than not to handle clipped textures
	else {

		printf("Here");
		textureRect->w = w;
		textureRect->h = h;

	}

}

void GameEssentials::Render() {

	SDL_RenderPresent(GameWindow::Instance()->getRenderer());

}


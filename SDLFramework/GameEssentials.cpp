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

	
}

GameEssentials::~GameEssentials() {

	for (auto x : collectionOfTextures) {

		if (x.second != NULL) {
			
			SDL_DestroyTexture(x.second);

		}
	}

	collectionOfTextures.clear();

}

SDL_Texture* GameEssentials::createTexture(std::string path) {

	if (collectionOfTextures[path]) {

		return collectionOfTextures[path];

	}

	SDL_Texture* newTexture = NULL;

	Loader::Instance()->loadTexture(path);

	if (Loader::Instance()->loaded() == true) {

		newTexture = SDL_CreateTextureFromSurface(GameWindow::Instance()->getRenderer(), Loader::pathToSurface);

		collectionOfTextures[path] = newTexture;

	}

	else {

		printf("SDL ERROR: Could not create texture!");

	}

	return newTexture; 

}

void GameEssentials::renderTexture(std::string path) {

	if (collectionOfTextures[path] == NULL) {

		printf("Error rendering texture: texture has not been created yet. Please call createTexture and ensure the path is correct.");

	}

	SDL_RenderClear(GameWindow::Instance()->getRenderer());

	SDL_RenderCopy(GameWindow::Instance()->getRenderer(), collectionOfTextures[path], NULL, NULL);

	SDL_RenderPresent(GameWindow::Instance()->getRenderer());

}


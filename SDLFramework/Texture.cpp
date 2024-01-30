#include "Texture.h"

Texture* Texture::txInstance = NULL;

Texture* Texture::Instance() {

	if (txInstance == NULL) {

		txInstance = new Texture;

	}

	return txInstance;

}

void Texture::Release() {

	delete txInstance;
	txInstance = NULL;

}

Texture::Texture() {



}

Texture::~Texture() {

	for (auto x : createdTextures) {

		if (x.second != NULL) {

			SDL_DestroyTexture(x.second);

		}
	}

	createdTextures.clear();

	releaseTexture();

	SDL_FreeSurface(surface);

	surface = NULL;

	delete tempTexture;

}

SDL_Texture* Texture::createTexture(std::string path) {

	getSurface(path);

	if (surfaceFlag == false) {

		return NULL;

	}

	if (createdTextures[path]) {

		printf("NOTE: Unnecessary to create texture that has already been created. Returning created texture, please use Texture::loadTexture(path)\n");

		return createdTextures[path];

	}

	releaseTexture();

	tempTexture = SDL_CreateTextureFromSurface(GameWindow::Instance()->getRenderer(), surface);

	if (tempTexture == NULL) {

		printf("SDL Error: could not create texture %s ! SDL_ERROR: %s\n", path.c_str(), SDL_GetError());

		return NULL;

	}

	createdTextures[path] = tempTexture;

	SDL_FreeSurface(surface);
	surface = NULL;


	return tempTexture;

}

SDL_Surface* Texture::getSurface(std::string path) {

	surface = IMG_Load(path.c_str());

	if (surface == NULL) {

		printf("Uh oh! Can't load image onto SDL Surface %s! SDL Error: %s\n", path.c_str(), SDL_GetError());

		surfaceFlag = false;

	}

	else {

		width = surface->w;

		height = surface->h;

		surfaceFlag = true;

	}

	return surface;

}

void Texture::releaseTexture() {

	SDL_DestroyTexture(tempTexture);
	tempTexture = NULL;

}

SDL_Texture* Texture::getTexture(std::string path) {

	return createdTextures[path];

}
#include "Loader.h"

Loader* Loader::ldInstance = NULL;

bool Loader::loadedMedia = false;

SDL_Surface* Loader::pathToSurface = NULL;

Loader* Loader::Instance() {

	//Create a new instance if no instance was created before
	if (ldInstance == NULL)

		ldInstance = new Loader();

	return ldInstance;

}

void Loader::Release() {

	delete ldInstance;
	ldInstance = NULL;
}

Loader::Loader() {


}

Loader::~Loader() {

	surfaceReset();

}

void Loader::loadBMPMedia(std::string path) {

	pathToSurface = NULL;

	//Loading success flag
	bool success = true;

	//Load splash image
	pathToSurface = SDL_LoadBMP(path.c_str());

	if (pathToSurface == NULL){

		printf("Uh oh! Can't load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		success = false;

	}
	else {

		printf("%s LOADED", path.c_str());

	}

	loadedMedia = success;

}

void Loader::loadTexture(std::string path) {

	surfaceReset();

	//Loading success flag
	bool success = true;

	//Load splash image
	pathToSurface = IMG_Load(path.c_str());

	if (pathToSurface == NULL) {

		printf("Uh oh! Can't load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		success = false;

	}
	else {

		printf("%s LOADED", path.c_str());

	}

	loadedMedia = success;

}

//add anything else that needs to be checked if its loaded here
bool Loader::loaded() {

	return loadedMedia;

}

void Loader::surfaceReset() {

	SDL_FreeSurface(pathToSurface);
	pathToSurface = NULL;

	loadedMedia = false;

}
#include "Entity.h"

Entity::Entity(std::string path) {
	
	path = fullPath;

	entityTexture = Texture::Instance()->createTexture(path);

}

Entity::~Entity() {

	SDL_DestroyTexture(entityTexture);
	entityTexture = NULL;

}
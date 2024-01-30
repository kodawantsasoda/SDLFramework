#include "Render.h"

void Render::renderTexture(std::string path) {

	if (Texture::Instance()->getTexture(path) == NULL) {

		printf("Error rendering texture: texture has not been created yet. Please call createTexture and ensure the path is correct.");

	}

	SDL_RenderClear(GameWindow::Instance()->getRenderer());

	SDL_RenderCopy(GameWindow::Instance()->getRenderer(), Texture::Instance()->getTexture(path), NULL, NULL);

}

void Render::renderEverything() {

	SDL_RenderPresent(GameWindow::Instance()->getRenderer());

}
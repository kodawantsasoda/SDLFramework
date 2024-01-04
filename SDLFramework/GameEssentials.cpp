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

/*left off here..im trying to figure out a way where i can access GameWindowand Loader stuff(rendererand loader function) to create a texture
* however.... I dont want confusing cross references either... I need to design it in a way where its easily navigable. I could have a big papa
* parent class that uses stuff from all classes like my screenorganizer does... perhaps it should be done in there... I would make this class
* use all the header files... But then we need to clean up screen organizer... maybe rename it GameTaker that takes from all other classes when
neccessary, then I have another separate class called GameLoop that is where I include GameTaker so i can write everything I need to*/
SDL_Texture* GameEssentials::createTexture(std::string path) {

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


#include <SDL.h>
#include <SDL_image.h>

#include "Loader.h"
#include "GameWindow.h"

#include <map>
#include <string>



class GameEssentials {

private: 

	GameEssentials();

	~GameEssentials();

	static GameEssentials* geInstance;

public:

	static GameEssentials* Instance();

	static void Release();

	std::map<std::string, SDL_Texture*> collectionOfTextures;

	SDL_Texture* createTexture(std::string path);

	void renderTexture(std::string path);

	void renderTexture(std::string path, int x, int y, int w, int h);

};
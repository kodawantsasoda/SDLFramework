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

	int currentSurfaceWidth;

	int currentSurfaceHeight;

	void setSurfaceDimensions();

	void setSurfaceDimensions(int w, int h);

	SDL_Rect* textureRect;

	void setTextureRect(int x, int y, int w = NULL, int h = NULL);

public:

	static GameEssentials* Instance();

	static void Release();

	std::map<std::string, SDL_Texture*> collectionOfTextures;

	SDL_Texture* currentTexture;

	SDL_Texture* createTexture(std::string path);

	void renderTexture(std::string path);

	//custom width and height option for texture
	void setRenderViewport(std::string path, int x, int y, int w, int h);

	int getCurrentSurfaceWidth();

	int getCurrentSurfaceHeight();

	void Render();

};
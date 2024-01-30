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

	SDL_Rect* textureRect;

	void setTextureRect(int x, int y, int w = NULL, int h = NULL);

public:

	static GameEssentials* Instance();

	static void Release();

	std::map<std::string, SDL_Texture*> collectionOfTextures;

	SDL_Texture* currentTexture;

	SDL_Texture* createOrReturnPreviousTexture(std::string path);

	//render full texture
	void renderTexture(std::string path);

	//render clipped texture
	void renderTexture(std::string path, int x, int y, SDL_Rect* clipRect);

	//custom width and height option for texture
	void setRenderViewport(int x, int y, int w, int h);

	int getCurrentSurfaceWidth();

	int getCurrentSurfaceHeight();

	void Render();

};
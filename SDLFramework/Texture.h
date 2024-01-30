#include <SDL.h>
#include <SDL_image.h>

#include "GameWindow.h"

#include <map>
#include <string>

class Texture {

private: 

	static Texture* txInstance;

	Texture();

	~Texture();

	int width;

	int height;

	SDL_Texture* tempTexture;

	SDL_Surface* surface;

	std::map<std::string, SDL_Texture*> createdTextures;

	SDL_Surface* getSurface(std::string path);

	void setTextureRect(int x, int y, int w = NULL, int h = NULL);

	bool surfaceFlag = false;

	void releaseTexture();

public:

	static Texture* Instance();

	static void Release();

	SDL_Texture* createTexture(std::string path);

	SDL_Texture* loadTexture(std::string path);

	SDL_Texture* getTexture(std::string path);

};
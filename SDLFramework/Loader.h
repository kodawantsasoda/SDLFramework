#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
//class that loads different forms of media
class Loader {
private:
	static Loader* ldInstance;

	Loader();

	~Loader();

	static bool loadedMedia;


public:
	static Loader* Instance();
	
	static bool loaded();

	static void Release();

	static void loadSomeMedia(std::string path);

	static SDL_Surface* pathToSurface;

};

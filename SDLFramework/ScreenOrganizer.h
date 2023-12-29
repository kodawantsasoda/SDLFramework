#include "GameWindow.h"
#include "Loader.h"
#include <SDL_image.h>

class ScreenOrganizer {
public: 
	static ScreenOrganizer* Instance();

	static void Release();

	void imageToScreen(std::string path);

	void ManageGameRun(); //this is the bread and butter of running the ganme.

private: 
	ScreenOrganizer();

	~ScreenOrganizer();

	static ScreenOrganizer* soInstance;

	GameWindow* masterWindow;

	Loader* masterLoader;

};

#include "GameEssentials.h"

#include <SDL_image.h>

#include <map>

class ScreenOrganizer {
public: 
	static ScreenOrganizer* Instance();

	static void Release();

	void ManageGameRun(); //this is the bread and butter of running the ganme.

	void addBeforeGameRun();

private: 
	ScreenOrganizer();

	~ScreenOrganizer();

	static ScreenOrganizer* soInstance;

	GameWindow* masterWindow;

	Loader* masterLoader;

	GameEssentials* essentials;

	SDL_Event eventCapture;

	bool quitGame;

	std::map<std::string, SDL_Rect> collectionOfClippedRects;

};
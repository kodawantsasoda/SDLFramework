#include <stdio.h>
#include <SDL.h>

class GameWindow {

public:
	static GameWindow* Instance();

	static void Release(); //this deletes the instance, which makes the destructor call automatically. this is the way to do it when the destructor is private

	const int SCREEN_WIDTH = 1000;

	const int SCREEN_HEIGHT = 600;

	const char* WINDOW_TITLE = "My Game";

	static bool Initialized();
	
	void KeepWindowOpen();

	void blackScreen();

	SDL_Surface* getWindowSurface();

	SDL_Window* getWindow();

private:
	GameWindow();

	~GameWindow();

	bool Init();

	static GameWindow* gwInstance;

	static bool gwInitialized;

	SDL_Window* gwWindow;

	SDL_Renderer* gwRenderer;

	SDL_Surface* gwSurface;

	SDL_Event eventCapture;

	bool quitGame;

};
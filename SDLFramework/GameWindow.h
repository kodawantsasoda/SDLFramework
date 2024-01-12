#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

class GameWindow {

public:
	static GameWindow* Instance();

	static void Release(); //this deletes the instance, which makes the destructor call automatically. this is the way to do it when the destructor is private

	const int SCREEN_WIDTH = 1000;

	const int SCREEN_HEIGHT = 600;

	const char* WINDOW_TITLE = "My Game";

	static bool Initialized();

	void blackScreen();

	SDL_Surface* getWindowSurface();

	SDL_Window* getWindow();

	SDL_Renderer* getRenderer();

	bool setRenderViewPort(int x, int y, int w, int h);

private:
	GameWindow();

	~GameWindow();

	bool Init();

	static GameWindow* gwInstance;

	static bool gwInitialized;

	SDL_Window* gwWindow;

	SDL_Renderer* gwRenderer;

	SDL_Surface* gwSurface;

	bool quitGame;

};
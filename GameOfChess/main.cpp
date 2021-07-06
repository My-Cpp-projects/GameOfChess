

#include <SDL.h>
#include <stdio.h>
#include <iostream>

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Can't initialize SDL ! Reason: " << SDL_GetError();
		return -1;
	}
	
	window = SDL_CreateWindow("GameOfChess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(window == nullptr)
	{
		std::cerr << "Can't create window ! Reason: " << SDL_GetError();
		return -1;
	}

	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);
	SDL_Delay(1000);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
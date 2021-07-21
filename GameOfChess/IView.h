#pragma once

#include <SDL.h>

class IView
{
public:
	virtual void render(const SDL_Point& renderStartLocation = {}) const = 0;
	virtual ~IView() {};
};
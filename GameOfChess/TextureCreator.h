#pragma once

#include "CommonTypes.h"

#include <SDL.h>
#include <string>

namespace textureCreator
{
	SDL_Texture* createTexture(const common::ImageType type,
                               const std::string& pathToTexture,
                               SDL_Renderer* const renderer);
}


#pragma once

#include "CommonTypes.h"

#include <SDL.h>
#include <string>

using textureCreatResult = common::ResultValue<common::sdlTextureUPtr_t>;

namespace textureCreator
{
    textureCreatResult createTexture(const common::ImageType type,
                                     const std::string& pathToTexture,
                                     SDL_Renderer* const renderer);
}


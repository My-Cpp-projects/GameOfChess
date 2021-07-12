#pragma once

#include "CommonTypes.h"

#include <SDL.h>
#include <string>

namespace textureCreator
{
    common::sdlTextureUPtr_t createTexture(const common::ImageType type,
                                           const std::string& pathToTexture,
                                           SDL_Renderer& renderer);
}


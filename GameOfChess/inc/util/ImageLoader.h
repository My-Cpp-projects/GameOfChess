#pragma once

#include "CommonTypes.h"

#include <SDL.h>
#include <memory>
#include <string>
#include <map>
#include <functional>

namespace ImageLoader
{
	common::sdlSurfaceUPtr_t loadImage(const common::ImageType imageType,
									   const std::string& pathToImage);
};
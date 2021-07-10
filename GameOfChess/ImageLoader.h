#pragma once

#include "CommonTypes.h"

#include <SDL.h>
#include <memory>
#include <string>
#include <map>
#include <functional>

using imageLoadResult = common::ResultValue<common::sdlSurfaceUPtr_t>;

namespace ImageLoader
{
	imageLoadResult loadImage(const common::ImageType imageType,
							  const std::string& pathToImage);
};
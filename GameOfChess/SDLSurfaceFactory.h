#pragma once

#include "CommonTypes.h"

#include <SDL.h>
#include <memory>
#include <string>
#include <map>
#include <functional>

using SurfaceCreationResult = common::ResultValue<common::SDLSurfaceUPtr_t>;

class SDLSurfaceFactory
{
public:
	SurfaceCreationResult createSurfaceFromImage(const common::ImageType imageType,
												 const std::string& path,
												 const SDL_Surface& screenSurface) const;

private:
	common::SDLSurfaceUPtr_t loadFromPathPNG(const std::string& path) const;
	common::SDLSurfaceUPtr_t loadFromPathBMP(const std::string& path) const;

private:
	using SurfaceCreator = common::SDLSurfaceUPtr_t(SDLSurfaceFactory::*)(const std::string&) const;

	static const std::map<common::ImageType, SurfaceCreator> SURFACE_CREATION_PICKER;
};
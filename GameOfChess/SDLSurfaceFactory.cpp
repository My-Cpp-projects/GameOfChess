#include "SDLSurfaceFactory.h"

#include <SDL_image.h>
#include <iostream>

const std::map<common::ImageType, SDLSurfaceFactory::SurfaceCreator> SDLSurfaceFactory::SURFACE_CREATION_PICKER =
{
    {common::ImageType::PNG, &loadFromPathPNG},
    {common::ImageType::BMP, &loadFromPathBMP}
};

SurfaceCreationResult SDLSurfaceFactory::createSurfaceFromImage(const common::ImageType imageType,
                                                                const std::string& path,
                                                                const SDL_Surface& screenSurface) const
{
    auto result = common::Result::FAILURE;
	const auto loadedSurface = (this->*SURFACE_CREATION_PICKER.at(imageType))(path);
    if(not loadedSurface)
    {
        return SurfaceCreationResult{result, common::SDLSurfaceUPtr_t{ nullptr, SDL_FreeSurface } };
    }

    const auto optimizedSurface = SDL_ConvertSurface(loadedSurface.get(), screenSurface.format, 0);
    if(not optimizedSurface)
    {
        std::cerr << "Failed to optimize surface: " << path << ". Reason: " << SDL_GetError() << std::endl;
        return SurfaceCreationResult{ result, common::SDLSurfaceUPtr_t{ nullptr, SDL_FreeSurface } };
    }

    result = common::Result::SUCCESS;
    return SurfaceCreationResult{ result, common::SDLSurfaceUPtr_t{ optimizedSurface, SDL_FreeSurface } };
}

common::SDLSurfaceUPtr_t SDLSurfaceFactory::loadFromPathPNG(const std::string& path) const
{
    const auto surface = IMG_Load(path.c_str());
    if(not surface)
    {
        std::cerr << "Failed to load surface from: " << path << ". Reason: " << IMG_GetError() << std::endl;
    }

    return common::SDLSurfaceUPtr_t{ surface, SDL_FreeSurface };
}

common::SDLSurfaceUPtr_t SDLSurfaceFactory::loadFromPathBMP(const std::string& path) const
{
    const auto surface = SDL_LoadBMP(path.c_str());
    if(not surface)
    {
        std::cerr << "Failed to load surface from: " << path << ". Reason: " << SDL_GetError() << std::endl;
    }

    return common::SDLSurfaceUPtr_t{ surface, SDL_FreeSurface };
}

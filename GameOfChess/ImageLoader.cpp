#include "ImageLoader.h"

#include <SDL_image.h>
#include <iostream>

common::sdlSurfaceUPtr_t loadFromPathPNG(const std::string& path)
{
    const auto surface = IMG_Load(path.c_str());
    if(not surface)
    {
        std::cerr << "Failed to load surface from: " << path << ". Reason: " << IMG_GetError() << std::endl;
    }
    return common::sdlSurfaceUPtr_t{ surface, SDL_FreeSurface };
}

common::sdlSurfaceUPtr_t loadFromPathBMP(const std::string& path)
{
    const auto surface = SDL_LoadBMP(path.c_str());
    if(not surface)
    {
        std::cerr << "Failed to load surface from: " << path << ". Reason: " << SDL_GetError() << std::endl;
    }
    return common::sdlSurfaceUPtr_t{ surface, SDL_FreeSurface };
}

using loader = std::function<common::sdlSurfaceUPtr_t(const std::string&)>;
const std::map<common::ImageType, loader> SURFACE_CREATION_PICKER =
{
    {common::ImageType::PNG, &loadFromPathPNG},
    {common::ImageType::BMP, &loadFromPathBMP}
};

namespace ImageLoader
{
    imageLoadResult loadImage(const common::ImageType imageType,
                              const std::string& pathToImage)
    {
        auto result = common::Result::SUCCESS;
        auto loadedSurface = (SURFACE_CREATION_PICKER.at(imageType))(pathToImage);
        if(not loadedSurface)
        {
            result = common::Result::FAILURE;
        }

        return imageLoadResult{ result, std::move(loadedSurface) };
    }
}

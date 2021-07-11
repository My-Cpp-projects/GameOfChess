#include "TextureCreator.h"
#include "ImageLoader.h"

#include <iostream>

textureCreatResult textureCreator::createTexture(const common::ImageType type,
                                                 const std::string& pathToTexture,
                                                 SDL_Renderer* const renderer)
{
    auto loadedImage = ImageLoader::loadImage(type, pathToTexture);
    auto newTexture = SDL_CreateTextureFromSurface(renderer, loadedImage.value.get());
    auto result = common::Result::SUCCESS;
    if(not newTexture)
    {
        std::cerr << "Failed to load texture from: " << pathToTexture << ". Reason: " << SDL_GetError() << std::endl;
        result = common::Result::FAILURE;
    }

    return textureCreatResult{ result,  common::sdlTextureUPtr_t{newTexture, SDL_DestroyTexture } };
}

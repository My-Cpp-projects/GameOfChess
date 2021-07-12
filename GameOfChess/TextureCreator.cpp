#include "TextureCreator.h"
#include "ImageLoader.h"

#include <iostream>

common::sdlTextureUPtr_t textureCreator::createTexture(const common::ImageType type,
                                                       const std::string& pathToTexture,
                                                       SDL_Renderer& renderer)
{
    auto loadedImage = ImageLoader::loadImage(type, pathToTexture);
    auto newTexture = SDL_CreateTextureFromSurface(&renderer, loadedImage.value.get());
    auto result = common::Result::SUCCESS;
    if(not newTexture)
    {
        std::cerr << "Failed to load texture from: " << pathToTexture << ". Reason: " << SDL_GetError() << std::endl;
        result = common::Result::FAILURE;
    }

    return common::sdlTextureUPtr_t{ newTexture, SDL_DestroyTexture };
}

#include "TextureCreator.h"
#include "ImageLoader.h"

#include <iostream>

SDL_Texture* textureCreator::createTexture(const common::ImageType type,
                                           const std::string& pathToTexture,
                                           SDL_Renderer* const renderer)
{
    auto loadedImage = ImageLoader::loadImage(type, pathToTexture);
    auto newTexture = SDL_CreateTextureFromSurface(renderer, loadedImage.value.get());

    if(not newTexture)
    {
        std::cerr << "Failed to load texture from: " << pathToTexture << ". Reason: " << SDL_GetError() << std::endl;
    }

    return newTexture;
}

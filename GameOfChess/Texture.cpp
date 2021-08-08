#include "Texture.h"
#include "ImageLoader.h"

Texture::Texture(const common::ImageType type,
				 const std::string& pathToTexture,
				 SDL_Renderer& renderer)
	: m_renderer(renderer)
{
	auto loadedImage = ImageLoader::loadImage(type, pathToTexture);
	m_texture.reset(SDL_CreateTextureFromSurface(&renderer, loadedImage.get()));
	m_width = loadedImage->w;
	m_height = loadedImage->h;
}

Texture::~Texture()
{
	printf("Destructor called for Texture\n");
}

void Texture::render(const SDL_Point& RenderingPosition,
					 const SDL_Rect* const clipRect)
{
	SDL_Rect renderQuad = { RenderingPosition.x, RenderingPosition.y, m_width, m_height };
	if(clipRect != NULL)
	{
		renderQuad.w = clipRect->w;
		renderQuad.h = clipRect->h;
	}
	SDL_RenderCopy(&m_renderer, m_texture.get(), clipRect, &renderQuad);
}

unsigned int Texture::getWidth() const
{
	return m_width;
}

unsigned int Texture::getHeight() const
{
	return m_height;
}

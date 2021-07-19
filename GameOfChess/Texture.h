#pragma once

#include "CommonTypes.h"

#include <string>
#include <memory>
#include <SDL.h>

class Texture
{
public:
	Texture(const common::ImageType type,
			const std::string& pathToTexture,
			SDL_Renderer& renderer);

	void render(const SDL_Point& RenderingPosition,
				const SDL_Rect* const clipRect = nullptr);

	unsigned int getWidth() const;
	unsigned int getHeight() const;

private:
	unsigned int m_width;
	unsigned int m_height;
	SDL_Renderer& m_renderer;
	common::sdlTextureUPtr_t m_texture{ nullptr, SDL_DestroyTexture };
};

using textureUPtr_t = std::unique_ptr<Texture>;
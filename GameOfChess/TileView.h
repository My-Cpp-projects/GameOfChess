#pragma once

#include "IView.h"
#include "TileData.h"

#include <memory>

class TileView : public IView
{
public:
	TileView(const TileData& tileData,
			 SDL_Renderer& renderer);

	void render() const;

private:
	const TileData& m_tileData;
	SDL_Renderer& m_renderer;
};

using tileViewUPtr_t = std::unique_ptr<TileView>;

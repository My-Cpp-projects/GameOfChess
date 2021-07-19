#pragma once

#include "BoardData.h"

#include <array>
#include <memory>

class Board
{
public:
	Board();
	~Board();

	void resetBoard();

	BoardData& getData();
private:
	std::unique_ptr<BoardData> m_data;
};

using boardUPtr_t = std::unique_ptr<Board>;
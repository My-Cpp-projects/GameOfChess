#pragma once

#include "BoardData.h"
#include "util/CommonTypes.h"

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
	common::ChessPieceColor m_playerSide{ common::ChessPieceColor::WHITE }; //TODO in future user should be able to pick side
	common::ChessPieceColor m_opponentSide;
};

using boardUPtr_t = std::unique_ptr<Board>;
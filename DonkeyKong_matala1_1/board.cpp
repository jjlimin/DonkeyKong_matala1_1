#include <cstring>
#include <iostream>

#include "board.h"
#include "gameConfig.h"

void Board::reset() {
	for (int i = 0; i < GameConfig::MAX_HEIGHT; i++) {
		memcpy(currentBoard[i], originalBoard[i], GameConfig::MAX_WIDTH+1);
	}
}

void Board::print() const {
	for (int i = 0; i < GameConfig::MAX_HEIGHT - 1; i++) {
		std::cout << currentBoard[i] << '\n';
	}
	std::cout << currentBoard[GameConfig::MAX_HEIGHT - 1];
}

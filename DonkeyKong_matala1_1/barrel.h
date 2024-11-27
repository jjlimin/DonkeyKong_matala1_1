#pragma once

#include <iostream>
#include "utils.h"
#include "board.h"
#include "gameConfig.h"
class Barrel
{
	struct Direction { int x, y; };
	static constexpr Direction directions[] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

	// initialize
	int x = GameConfig::BARREL_POS_X, y = GameConfig::BARREL_POS_Y;
	Direction dir = { 1, 0 }; // current direction: dir.x, dir.y
	Direction last_dir = { 0,0 };
	char ch = 'O';
	Board* pBoard = nullptr;
	// draw
	void draw(char c) const {
		gotoxy(x, y);
		std::cout << c;
	}

public:
	void erase() { draw(pBoard->getCharFromOriginal(x, y)); }
	void draw() const { draw(ch); }
	void setBoard(Board& board) { pBoard = &board; }
	void move();

};


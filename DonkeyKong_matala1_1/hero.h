#pragma once

#include <iostream>

#include "utils.h"
#include "board.h"
#include "gameConfig.h"

class Hero {

	// movement
	static constexpr char keys[] = { 'w', 'a', 'x', 'd', 's' };
	static constexpr size_t numKeys = sizeof(keys) / sizeof(keys[0]);
	struct Direction { int x, y; };
	static constexpr Direction directions[] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0}, {0, 0} };

	// initialize
	int x = GameConfig::START_POS_X, y = GameConfig::START_POS_Y;
	Direction dir = { 1, 0 }; // current direction: dir.x, dir.y
	char ch = '@';
	Board* pBoard = nullptr;

	// draw
	void draw(char c) const {
		gotoxy(x, y);
		std::cout << c;
	}

public:
	void draw() const { draw(ch); }
	void erase() { draw(pBoard->getCharFromOriginal(x, y)); }
	void keyPressed(char key);
	void move();
	void setBoard(Board& board) { pBoard = &board; }
	bool checkKindOfUp();
	void jump();
};



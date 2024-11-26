#include "hero.h"
#include <Windows.h>

bool Hero::checkKindOfUp() { // true- jump, false- climb
	char ch = pBoard->getCharFromOriginal(x,y);
	if(ch != 'H'){
		return true; // jump
	}
	return false; // climb
}

void Hero::jump() {
	//up
	dir.y = -2;
	erase();
	move();
	draw();
	Sleep(GameConfig::SLEEP_DURATION);

	//land
	dir.y = 2;
	erase();
	move();
	draw();
	Sleep(GameConfig::SLEEP_DURATION);
}

void Hero::keyPressed(char key) {
	for (size_t i = 0; i < numKeys; i++) {
		if (std::tolower(key) == 'w' && pBoard->getCharFromOriginal(x, y)!= 'H') { // jump if
			jump();
			dir.y = 0;
			break;
		}
		else if (std::tolower(key) == keys[i]) {
			dir = directions[i];
			return;
		}
	}
}

void Hero::move() {
	int newX = x + dir.x;
	int newY = y + dir.y;
	// Better use a function in Board to check if the new position is valid
	// + Better use a constant for the wall character
	if (pBoard->getChar(newX, newY) == 'Q' || pBoard->getChar(newX, newY) == '<' ||
		pBoard->getChar(newX, newY) == '>' || pBoard->getChar(newX, newY) == '=' ||
		pBoard->getChar(newX, newY) == '&') {
		dir = { 0, 0 };
	}
	else {
		x = newX;
		y = newY;
	}
}

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
	Sleep(130);

	//land
	dir.y = 2;
	erase();
	move();
	draw();
	Sleep(130);
}

void Hero::climb() {
	dir.y = -1;
	dir.x = 0;
	while (pBoard->getCharFromOriginal(x, y) != ' ') {
		erase();
		move();
		draw();
		Sleep(GameConfig::SLEEP_DURATION);
	}
	dir.y = 0;
}


void Hero::keyPressed(char key) {
	for (size_t i = 0; i < numKeys; i++) {
		if (std::tolower(key) == 'w') {
			if (pBoard->getCharFromOriginal(x, y) != 'H') {
				jump();
				dir.y = 0;
			}
			else {
				climb();
			}
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

	if (pBoard->getCharFromOriginal(newX, newY + 1) == ' ' && dir.y != -2 ) {
		dir = { 0,1 };
	}
	if (dir.x == -1 || dir.x == 1) {    // a or d
		if (pBoard->getChar(newX, newY) == 'Q') {
			dir = { 0,0 };
			return;
		}
	}
	else if (dir.y == -1) {  // w -climb
		if (pBoard->getChar(x, y) == ' ') {
			dir = { 0, 0 };
		}
	}
	else if (dir.y == 1) { // x- down
		if (pBoard->getChar(newX, newY + 1) == 'H') {
			erase();
			x = newX;
			y = newY;
			draw();
		}
		else if (pBoard->getChar(newX, newY) == '=' || pBoard->getChar(newX, newY) == '>' ||
			pBoard->getChar(newX, newY) == '<') {
			dir = { 0, 0 };
			return;
		}
	}
	else {
		if (pBoard->getChar(newX, newY) == 'Q' || pBoard->getChar(newX, newY) == '=' ||
			pBoard->getChar(newX, newY) == '>' || pBoard->getChar(newX, newY) == '<') {
			dir = { 0, 0 };
		}
	}
	x = newX;
    y = newY;

}


#include "barrel.h"

void Barrel::move() {
	int newX = x + dir.x;
	int newY = y + dir.y;

	if (pBoard->getCharFromOriginal(newX, newY + 1) == ' ') {
		dir = { 0,1 };
	}
	if (dir.y == 1) { // x- down
		if (pBoard->getChar(newX, newY) == '=' || pBoard->getChar(newX, newY) == '>' ||
			pBoard->getChar(newX, newY) == '<') {
			dir = { 0, 0 };
			return;
		}
	}
	else {
		if (pBoard->getCharFromOriginal(x, y + 1) == '>') {
			last_dir = dir;
			dir = { 1, 0 };
		}
		else if (pBoard->getCharFromOriginal(x, y + 1) == '<') {
			last_dir = dir;
			dir = {- 1, 0 };
		}
		else if (pBoard->getCharFromOriginal(x, y + 1) == '=') {
			dir = last_dir;
		}
		if (pBoard->getChar(newX, newY) == 'Q' ) {
			dir = { 0, 0 };
			return;
		}
	}
	x = newX;
	y = newY;
}

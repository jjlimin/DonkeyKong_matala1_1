#include <conio.h>
#include "gameConfig.h"
#include "board.h"
#include "hero.h"
#include "utils.h"
#include "barrel.h"


void GameConfig::run() {

	ShowConsoleCursor(false);
	Board board;
	board.reset();
	board.print();
	Hero mario;
	mario.setBoard(board);
	Barrel b1;
	b1.setBoard(board);


	while (true) {
		mario.draw();
		b1.draw();
		if (_kbhit()) {
			char key = _getch();
			if (key == GameConfig::ESC) break;
			mario.keyPressed(key);
		}
		Sleep(GameConfig::SLEEP_DURATION);
		mario.erase();
		mario.move();
		b1.erase();
		b1.move();
	}
}
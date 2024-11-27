#pragma once
#include "gameConfig.h"

class Board {
	const char* originalBoard[GameConfig::MAX_HEIGHT] = {
		// 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		  "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ", // 0
		  "Q                                                                              Q", // 1
		  "Q                                                                              Q", // 2
		  "Q                                                                              Q", // 3
		  "Q    $                                                                         Q", // 4
		  "Q========== =======                                         ============ ======Q", // 5
		  "Q                H                      &                    H                 Q", // 6
		  "Q                H               <<<<<<<<>>>>>>>             H                 Q", // 7
		  "Q                H                                           H                 Q", // 8
		  "Q                H                                           H                 Q", // 9
		  "Q                H                                           H                 Q", // 10
		  "Q          <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>           Q", // 11
		  "Q           H                                                    H             Q", // 12
		  "Q           H                                                    H             Q", // 13
		  "Q           H                                                    H             Q", // 14
		  "Q   >>>>>>>>>>>>>>>>>>>>>>>>                      <<<<<<<<<<<<<<<<<<<<<<<<     Q", // 15
		  "Q                    H                                    H                    Q", // 16
		  "Q                    H                                    H                    Q", // 17
		  "Q                    H                                    H                    Q", // 18
		  "Q              ======================== ===========================            Q", // 19
		  "Q      H                          H              H                             Q", // 20
		  "Q      H                          H              H                             Q", // 21
		  "Q      H                          H              H                             Q", // 22
		  "Q==============================================================================Q", // 23
		  "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ"  // 24
	};
	char currentBoard[GameConfig::MAX_HEIGHT][GameConfig::MAX_WIDTH + 1]; 

public:
	void reset();
	void print() const;
	char getChar(int x, int y) const {
		return currentBoard[y][x];
	}
	char getCharFromOriginal(int x, int y) const {
		return originalBoard[y][x];
	}
};



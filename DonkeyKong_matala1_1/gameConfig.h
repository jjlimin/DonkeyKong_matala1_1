#pragma once
class GameConfig
{
public:
	static constexpr int MAX_WIDTH = 80;
	static constexpr int MAX_HEIGHT = 25;

	static constexpr int START_POS_X = 3;
	static constexpr int START_POS_Y = 22;

	static constexpr int ESC = 27;

	static constexpr int SLEEP_DURATION = 200;

	void run();

};


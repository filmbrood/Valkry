#pragma once

class player
{
public:
	float getPosX();
	float getPosY();
	void setPos(float x, float y);

	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();

private:
	float posx = 0.0f, posy = 0.0f;
};
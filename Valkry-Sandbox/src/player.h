#pragma once

class player
{
public:
	float getPosX();
	float getPosY();
	void setPos(float x, float y);

	void setDelta(float deltaTime);
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();

	void SetSpeed(float spd);
private:
	float posx = 0.0f, posy = 0.0f;
	float speed = 5.0f;
	float deltaTime;
};
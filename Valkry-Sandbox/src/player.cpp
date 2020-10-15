#include "player.h"

float player::getPosX() 
{ 
	return posx; 
}

float player::getPosY()
{ 
	return posy; 
}

void player::setPos(float x, float y)
{
	posx = x;
	posy = y;
}

void player::setDelta(float deltaTime)
{
	this->deltaTime = deltaTime;
}

void player::moveRight()
{ 
	posx += speed * deltaTime; 
}

void player::moveLeft()
{ 
	posx -= speed * deltaTime;
}

void player::moveDown()
{ 
	posy += speed * deltaTime;
}

void player::moveUp()
{ 
	posy -= speed * deltaTime;
}

void player::SetSpeed(float spd)
{
	speed = spd;
}

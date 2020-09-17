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

void player::moveRight()
{ 
	posx += 5.0f; 
}

void player::moveLeft()
{ 
	posx -= 5.0f; 
}

void player::moveDown()
{ 
	posy += 5.0f; 
}

void player::moveUp()
{ 
	posy -= 5.0f; 
}
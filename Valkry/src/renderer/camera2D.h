#pragma once

class Camera2D
{
private:
	float posx_, posy_;

public:
	void SetPosX(float value);
	void SetPosY(float value);

	float GetPosX();
	float GetPosY();
};
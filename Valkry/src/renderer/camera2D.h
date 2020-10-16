#pragma once

// Data class that contains camera position values for Renderer2D.
class Camera2D
{
public:
	void SetPosX(float value);
	void SetPosY(float value);
	float GetPosX();
	float GetPosY();

private:
	float posx_, posy_;
};

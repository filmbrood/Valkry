#include "valkrypch.h"
#include "camera2D.h"

void Camera2D::SetPosX(float value)
{
	posx_ = value;
}

void Camera2D::SetPosY(float value)
{
	posy_ = value;
}

float Camera2D::GetPosX()
{
	return posx_;
}

float Camera2D::GetPosY()
{
	return posy_;
}

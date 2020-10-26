#include "valkrypch.h"
#include "camera2D.h"

namespace Valkry{

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

	void Camera2D::SetZoom(float value)
	{
		zoom_ = value;
	}

	float Camera2D::GetZoom()
	{
		return zoom_;
	}

}

#pragma once

// Data class that contains camera position values for Renderer2D.

namespace Valkry{

	class Camera2D
	{
	public:
		void SetPosX(float value);
		void SetPosY(float value);
		float GetPosX();
		float GetPosY();

		void SetZoom(float value);
		float GetZoom();
	private:
		float posx_ = 0.0f, posy_ = 0.0f;
		float zoom_ = 1.0f;
	};

}

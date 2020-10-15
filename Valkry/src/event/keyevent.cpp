#include "valkrypch.h"

#include "keyevent.h"

namespace Valkry {

	KeyEvent::KeyEvent(int keycode)
	{
		this->keycode_ = keycode;
	}

	bool KeyEvent::Pressed(Window& win)
	{
		if (glfwGetKey(win.GetWindow(), keycode_) == GLFW_PRESS)
		{
			Logger::Get().LogInfo("Event - Key Pressed", (double)keycode_);
			return true;
		}
		else
			return false;
	}

	bool KeyEvent::Released(Window& win)
	{
		if (glfwGetKey(win.GetWindow(), keycode_) == GLFW_RELEASE)
		{
			return true;
		}
		else
			return false;
	}

	bool KeyEvent::Repeated(Window& win)
	{
		if (glfwGetKey(win.GetWindow(), keycode_) == GLFW_REPEAT)
		{
			return true;
		}
		else
			return false;
	}

	namespace Keys {
		KeyEvent ESC(GLFW_KEY_ESCAPE);

		KeyEvent A(GLFW_KEY_A);
		KeyEvent B(GLFW_KEY_B);
		KeyEvent C(GLFW_KEY_C);
		KeyEvent D(GLFW_KEY_D);
		KeyEvent E(GLFW_KEY_E);
		KeyEvent F(GLFW_KEY_F);
		KeyEvent G(GLFW_KEY_G);
		KeyEvent H(GLFW_KEY_H);
		KeyEvent I(GLFW_KEY_I);
		KeyEvent J(GLFW_KEY_J);
		KeyEvent K(GLFW_KEY_K);
		KeyEvent L(GLFW_KEY_L);
		KeyEvent M(GLFW_KEY_M);
		KeyEvent N(GLFW_KEY_N);
		KeyEvent O(GLFW_KEY_O);
		KeyEvent P(GLFW_KEY_P);
		KeyEvent Q(GLFW_KEY_Q);
		KeyEvent R(GLFW_KEY_R);
		KeyEvent S(GLFW_KEY_S);
		KeyEvent T(GLFW_KEY_T);
		KeyEvent U(GLFW_KEY_U);
		KeyEvent V(GLFW_KEY_V);
		KeyEvent W(GLFW_KEY_W);
		KeyEvent X(GLFW_KEY_X);
		KeyEvent Y(GLFW_KEY_Y);
		KeyEvent Z(GLFW_KEY_Z);

		KeyEvent ZERO(GLFW_KEY_0);
		KeyEvent ONE(GLFW_KEY_1);
		KeyEvent TWO(GLFW_KEY_2);
		KeyEvent THREE(GLFW_KEY_3);
		KeyEvent FOUR(GLFW_KEY_4);
		KeyEvent FIVE(GLFW_KEY_5);
		KeyEvent SIX(GLFW_KEY_6);
		KeyEvent SEVEN(GLFW_KEY_7);
		KeyEvent EIGHT(GLFW_KEY_8);
		KeyEvent NINE(GLFW_KEY_9);
	}

}
#include "testlayer.h"

int main()
{
	Valkry::App sandbox;
	sandbox.PushLayer(new TestLayer);
	sandbox.Run();
}
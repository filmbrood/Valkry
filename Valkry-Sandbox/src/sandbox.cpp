#include "testlayer.h"

int main()
{
	Valkry::App sandbox;
	TestLayer testlayer;
	sandbox.PushLayer(&testlayer);
	sandbox.Run();
}

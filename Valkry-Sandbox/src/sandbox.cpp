#include "testlayer.h"

int main()
{
	Valkry::App::Get().GetWindow().SetDimensions(SCREENWIDTH, SCREENHEIGHT);
	Valkry::App::Get().GetWindow().SetTitle("Valkry Sandbox");
	Valkry::App::Get().GetWindow().SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	Valkry::App::Get().GetWindow().SetFullscreen(false);
	Valkry::App::Get().GetWindow().Create();
	Valkry::App::Get().GetWindow().SetViewportResizeable();

	TestLayer testlayer;
	Valkry::App::Get().PushLayer(&testlayer);
	Valkry::App::Get().Run();
}

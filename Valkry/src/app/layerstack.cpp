#include "valkrypch.h"
#include "layerstack.h"

void Valkry::LayerStack::PushLayer(Layer* layer)
{
	layers_.emplace_back(layer);
}

void Valkry::LayerStack::PopLayer()
{
	layers_.pop_back();
}

void Valkry::LayerStack::InitLayers()
{
	for (unsigned int i = 0; i < layers_.size(); i++)
	{
		layers_[i]->OnInit();
	}
}

void Valkry::LayerStack::RunLayers()
{
	for (int i = 0; i < layers_.size(); i++)
	{
		layers_[i]->OnUpdate();
		layers_[i]->OnEvent();

		if (layers_[i]->ReturnClosingFlag())
			programShouldClose_ = true;
	}
}

bool Valkry::LayerStack::CheckForClosingFlags()
{
	return programShouldClose_;
}

Valkry::LayerStack::~LayerStack()
{
	for (int i = 0; i < layers_.size(); i++)
		layers_[i]->OnClose();
}

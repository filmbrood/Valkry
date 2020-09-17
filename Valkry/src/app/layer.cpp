#include "valkrypch.h"
#include "layer.h"

void Valkry::Layer::SetName(std::string name)
{
	this->name = name;
}

std::string Valkry::Layer::GetName()
{
	return name;
}

void Valkry::Layer::CloseProgram()
{
	closingflag_ = true;
}

bool Valkry::Layer::ReturnClosingFlag()
{
	return closingflag_;
}

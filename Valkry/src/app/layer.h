#pragma once

namespace Valkry {

	class Layer
	{
	private:
		std::string name = "Default Layer Name";

		bool closingflag_ = false;
	public:
		virtual void OnInit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnEvent() = 0;

		void SetName(std::string name);
		std::string GetName();

		void CloseProgram();
		bool ReturnClosingFlag();
	};

}
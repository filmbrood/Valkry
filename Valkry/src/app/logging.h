#pragma once
#include <string>

namespace Valkry {

	void LogInfo(std::string desc, double data = NULL);
	void LogWarn(std::string desc, double data = NULL);
	void LogError(std::string desc, double data = NULL);
	void LogFatal(std::string desc, double data = NULL);

}
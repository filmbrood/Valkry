#pragma once
#include <string>

namespace valkry {

	void LogInfo(std::string desc, double data = NULL);
	void LogWarn(std::string desc, double data = NULL);
	void LogError(std::string desc, double data = NULL);
	void LogFatal(std::string desc, double data = NULL);

}
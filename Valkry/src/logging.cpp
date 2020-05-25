#include "logging.h"
#include <iostream>

namespace valkry {

	void LogInfo(std::string desc, double data)
	{
		std::cout << "[time-placeholder] [VALKRY-INFO] " << desc;
		
		if (data)
			std::cout << " - " << data;

		std::cout << "\n";
	}

	void LogWarn(std::string desc, double data)
	{
		std::cout << "[time-placeholder] [VALKRY-WARN] " << desc;

		if (data)
			std::cout << " - " << data;

		std::cout << "\n";
	}

	void LogError(std::string desc, double data)
	{
		std::cout << "[time-placeholder] [VALKRY-ERROR] " << desc;

		if (data)
			std::cout << " - " << data;

		std::cout << "\n";
	}

	void LogFatal(std::string desc, double data)
	{
		std::cout << "[time-placeholder] [VALKRY-FATAL] " << desc;

		if (data)
			std::cout << " - " << data;

		std::cout << "\n";
	}

}
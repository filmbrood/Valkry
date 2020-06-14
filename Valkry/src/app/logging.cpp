#include "valkrypch.h"

#include "logging.h"

namespace Valkry {

	void LogInfo(std::string desc, double data)
	{
		std::chrono::system_clock::time_point systemTime = std::chrono::system_clock::now();
		std::time_t epochSeconds = std::chrono::system_clock::to_time_t(systemTime);

		auto* timeOutput = std::localtime(&epochSeconds);

		std::cout << "[" << timeOutput->tm_hour << ":" << timeOutput->tm_min << ":" << timeOutput->tm_sec << "] [VALKRY-INFO] " << desc;
		
		if (data != NULL)
			std::cout << " - " << data;

		std::cout << "\n";
	}

	void LogWarn(std::string desc, double data)
	{
		std::chrono::system_clock::time_point systemTime = std::chrono::system_clock::now();
		std::time_t epochSeconds = std::chrono::system_clock::to_time_t(systemTime);

		auto* timeOutput = std::localtime(&epochSeconds);

		std::cout << "[" << timeOutput->tm_hour << ":" << timeOutput->tm_min << ":" << timeOutput->tm_sec << "] [VALKRY-WARNING] " << desc;

		if (data != NULL)
			std::cout << " - " << data;

		std::cout << "\n";
	}

	void LogError(std::string desc, double data)
	{
		std::chrono::system_clock::time_point systemTime = std::chrono::system_clock::now();
		std::time_t epochSeconds = std::chrono::system_clock::to_time_t(systemTime);

		auto* timeOutput = std::localtime(&epochSeconds);

		std::cout << "[" << timeOutput->tm_hour << ":" << timeOutput->tm_min << ":" << timeOutput->tm_sec << "] [VALKRY-ERROR] " << desc;

		if (data != NULL)
			std::cout << " - " << data;

		std::cout << "\n";
	}

	void LogFatal(std::string desc, double data)
	{
		std::chrono::system_clock::time_point systemTime = std::chrono::system_clock::now();
		std::time_t epochSeconds = std::chrono::system_clock::to_time_t(systemTime);

		auto* timeOutput = std::localtime(&epochSeconds);

		std::cout << "[" << timeOutput->tm_hour << ":" << timeOutput->tm_min << ":" << timeOutput->tm_sec << "] [VALKRY-FATAL] " << desc;

		if (data != NULL)
			std::cout << " - " << data;

		std::cout << "\n";
	}

}
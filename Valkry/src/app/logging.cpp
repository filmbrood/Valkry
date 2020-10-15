#include "valkrypch.h"
#include "logging.h"

namespace Valkry {

	Logger Logger::s_Instance; // Instantiate singleton instance of Logger

	Logger::~Logger()
	{
		std::ofstream logFileOutput;
		logFileOutput.open("valkry.log");
		logFileOutput << m_LogStream;
		logFileOutput.close();
	}

	void Logger::LogInfo(std::string desc, double data)
	{
		std::chrono::system_clock::time_point systemTime = std::chrono::system_clock::now();
		std::time_t epochSeconds = std::chrono::system_clock::to_time_t(systemTime);

		auto* timeOutput = std::localtime(&epochSeconds);

		std::stringstream outputStream;
		outputStream << "[" << timeOutput->tm_hour << ":" << timeOutput->tm_min << ":" << timeOutput->tm_sec << "] [VALKRY-INFO] " << desc;
		if (data != 69420)
			outputStream << " - " << data;
		outputStream << "\n";

		std::cout << outputStream.rdbuf();
		m_LogStream += outputStream.str();
	}

	void Logger::LogWarn(std::string desc, double data)
	{
		std::chrono::system_clock::time_point systemTime = std::chrono::system_clock::now();
		std::time_t epochSeconds = std::chrono::system_clock::to_time_t(systemTime);

		auto* timeOutput = std::localtime(&epochSeconds);

		std::stringstream outputStream;
		outputStream << "[" << timeOutput->tm_hour << ":" << timeOutput->tm_min << ":" << timeOutput->tm_sec << "] [VALKRY-WARNING] " << desc;
		if (data != 69420)
			outputStream << " - " << data;
		outputStream << "\n";

		std::cout << outputStream.rdbuf();
		m_LogStream += outputStream.str();
	}

	void Logger::LogError(std::string desc, double data)
	{
		std::chrono::system_clock::time_point systemTime = std::chrono::system_clock::now();
		std::time_t epochSeconds = std::chrono::system_clock::to_time_t(systemTime);

		auto* timeOutput = std::localtime(&epochSeconds);

		std::stringstream outputStream;
		outputStream << "[" << timeOutput->tm_hour << ":" << timeOutput->tm_min << ":" << timeOutput->tm_sec << "] [VALKRY-ERROR] " << desc;
		if (data != 69420)
			outputStream << " - " << data;
		outputStream << "\n";

		std::cout << outputStream.rdbuf();
		m_LogStream += outputStream.str();
	}

	void Logger::LogFatal(std::string desc, double data)
	{
		std::chrono::system_clock::time_point systemTime = std::chrono::system_clock::now();
		std::time_t epochSeconds = std::chrono::system_clock::to_time_t(systemTime);

		auto* timeOutput = std::localtime(&epochSeconds);

		std::stringstream outputStream;
		outputStream << "[" << timeOutput->tm_hour << ":" << timeOutput->tm_min << ":" << timeOutput->tm_sec << "] [VALKRY-FATAL] " << desc;
		if (data != 69420)
			outputStream << " - " << data;
		outputStream << "\n";

		std::cout << outputStream.rdbuf();
		m_LogStream += outputStream.str();
	}

	Logger& Logger::Get()
	{
		return s_Instance;
	}
}
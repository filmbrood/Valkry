#include "valkrypch.h"
#include "logging.h"

namespace Valkry {

	Logger Logger::s_Instance; // Instantiate singleton instance of Logger

	void Logger::DumpLogToFile()
	{
		this->LogInfo("Dumping log to valkry.log");
		std::ofstream logFileOutput;
		logFileOutput.open("valkry.log");
		logFileOutput << m_LogStream;
		logFileOutput.close();
	}

	void Logger::LogInfo(std::string desc)
	{
		LogImpl(desc, "VALKRY-INFO");
	}

	void Logger::LogWarn(std::string desc)
	{
		LogImpl(desc, "VALKRY-WARNING");
	}

	void Logger::LogError(std::string desc)
	{
		LogImpl(desc, "VALKRY-ERROR");
	}

	void Logger::LogFatal(std::string desc)
	{
		LogImpl(desc, "VALKRY-FATAL");
	}

	void Logger::LogImpl(const std::string& desc, const std::string& type)
	{
		std::chrono::system_clock::time_point systemTime = std::chrono::system_clock::now();
		std::time_t epochSeconds = std::chrono::system_clock::to_time_t(systemTime);

		auto* timeOutput = std::localtime(&epochSeconds);

		std::stringstream outputStream;
		outputStream << "[" << timeOutput->tm_hour << ":" << timeOutput->tm_min << ":" << timeOutput->tm_sec << "] [" + type + "] " << desc;
		outputStream << "\n";

		std::cout << outputStream.rdbuf();
		m_LogStream += outputStream.str();
	}

	Logger& Logger::Get()
	{
		return s_Instance;
	}
}

#pragma once
#include <string>

namespace Valkry {

	enum class LogState
	{
		INFO = 0, WARNING, ERROR, FATAL
	};

	// Singleton logging class. Call with Logger::Get().
	class Logger
	{
	public:
		static Logger& Get();

	public:
		void LogInfo(std::string desc, double data = 69420);
		void LogWarn(std::string desc, double data = 69420);
		void LogError(std::string desc, double data = 69420);
		void LogFatal(std::string desc, double data = 69420);

		void DumpLogToFile();

	private:
		Logger() {}
		static Logger s_Instance;
		std::string m_LogStream;
		LogState m_LogState;
	};
}

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
		void LogInfo(std::string desc);
		void LogWarn(std::string desc);
		void LogError(std::string desc);
		void LogFatal(std::string desc);

		void DumpLogToFile();

	private:
		void LogImpl(const std::string& desc, const std::string& type);

		Logger() {}
		static Logger s_Instance;
		std::string m_LogStream;
		LogState m_LogState;
	};
}

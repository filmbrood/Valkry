#pragma once
#include <string>

namespace Valkry {

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

	public:
		// Deconstructor dumps m_LogStream to valkry.log file
		~Logger();

	private:
		Logger() {}
		static Logger s_Instance;
		std::string m_LogStream;
	};
}
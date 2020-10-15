#pragma once
#include <string>

namespace Valkry {

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
		~Logger();

	private:
		void DumpLogStreamToFile();

	private:
		Logger() {}
		static Logger s_Instance;

		std::string m_LogStream;
	};
}
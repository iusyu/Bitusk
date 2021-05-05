/*********************************
 * FileName: BtLogger.h
 *     Date: 2021-05-05 20:32
 *   Author: sunyi
 *  Version: 0.1
 *
 *   @brief: 日志模块 按照c++的OO设计来搞定。
 *
 ********************************
 */



/*===============================
 * Support this interface Logger << date <<info<< ...;
 *
 *===============================
 */
#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class Logger;
class LoggerStream;

enum LogLevel {
	TRACE, DEBUG, INFO, WARN, ERROR
};


class Logger {
public:
	void log(LogLevel level, const std::string& message);
	const std::string logLevelStr(LogLevel lv);
	LoggerStream& log(LogLevel level);

private:

	std::ofstream logfile;

	
};


class LoggerStream {
public:
	~LoggerStream();
	template<typename T>
	LoggerStream& operator<<(const T& value);

private:
	friend class Logger;
	LoggerStream(Logger& lg, LogLevel lv):logger(lg),logleve(lv) {}


private:
	Logger& logger;
	LogLevel logleve;
	std::ostringstream stream;
};








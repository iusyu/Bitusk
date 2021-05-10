/*
=============================================
* @brief    : Bt downloader logger 
* @copyright: Copyright 2021 iusyu
* @license  : Apache
* @birth    : 2021-05-01 23:48
* @author   : sunyi
* @version  : 0.1.0
* @revisions: NA
==============================================
*/

// * Support this interface Logger << date <<info<< ...;


#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <utility>


class Logger;
class LoggerStream;

enum LogLevel {
	TRACE, DEBUG, INFO, WARN, ERROR
};

/* logger的主要实现 */
class Logger {
public:

	Logger(const std::string& filename):logfile(filename, std::ofstream::app) {}

	/*
	 * @brief: log message and logleve
	 * @param: LogLevel how important and  message logged
	 * @ret: void
	 * @birth: 2021-05-5
	 */
	void log(LogLevel level, const std::string& message);

	/*
	 * @brief: 返回loglevel的字符串
	 * @param: LogLevel
	 * @ret: const std::string level string
	 * @birth: 2021-05-5
	 */
	const std::string logLevelStr(LogLevel lv);

	/*
	 * @brief: 返回记录时间
	 * @param: void
	 * @ret: const std::string log time
	 * @birth: 2021-05-5
	 */
	const std::string getTime() const;

	/*
	 * @brief: 返回一个字符串流处理各种信息
	 * @param: LogLevel 
	 * @ret: LoggerStream&& 使用move semantic
	 * @birth: 2021-05-5
	 */
	LoggerStream log(LogLevel level);

private:
	std::ofstream logfile;
};

/* LoggerStream提供更多type推导 */
class LoggerStream {
	friend class Logger;
public:
	~LoggerStream();
	LoggerStream(LoggerStream&& ls):stream(std::move(ls.stream)), logger(ls.logger), logleve(ls.logleve) {}


	/*
	 * @brief: 流处理操作符
	 * @param: typename T& value
	 * @ret: 还是本流
	 * @birth: 2021-05-5
	 */
	template<typename T>
	LoggerStream& operator<<(const T& value) {
		(stream)<<" "<<value;
		return (*this);
	}

private:

	/*
	 * @brief: 返回一个字符串流处理各种信息
	 * @param: LogLevel 
	 * @ret: LoggerStream&& 使用move semantic
	 * @birth: 2021-05-5
	 */
	LoggerStream(Logger& lg, LogLevel lv):logger(lg),logleve(lv)  {
		//stream << logger.getTime();
	}

private:
	std::ostringstream stream;
	Logger& logger;
	LogLevel logleve;
};








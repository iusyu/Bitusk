/*********************************
 * FileName: BtLogger.cpp
 *     Date: 2021-05-05 20:32
 *   Author: sunyi
 *  Version: 0.1
 *
 *   @brief: 日志模块 按照c++的OO设计来搞定。
 *
 ********************************
 */

#include "../include/BtLogger.h"


void Logger::log(LogLevel level, const std::string& message){
	if(logfile.is_open()){
		logfile<<logLevelStr(level)<<message<<std::endl;
	} else {
		throw ;
	}
}


std::shared_ptr<LoggerStream> Logger::log(LogLevel level) {
	return std::make_shared<LoggerStream> (new LoggerStream(*this, level));
}


const std::string Logger::logLevelStr(LogLevel lv) {
	switch(lv){
	case TRACE:
		return "TRACE";
	case DEBUG:
		return "DEBUG";
	case INFO:
		return "INFO";
	case WARN:
		return "WARN";
	case ERROR:
		return "ERROR";
	default:
		break;
	}
}


LoggerStream::~LoggerStream() {
	const std::string message { stream.str() };
	if( !message.empty()) {
		logger.log(logleve,message);
	}
}


template<typename T>
LoggerStream& LoggerStream::operator<<(const T& value) {
	stream<<value;
	return (*this);
}



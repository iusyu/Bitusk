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

#include "../include/BtLogger.h"


void Logger::log(LogLevel level, const std::string& message){
	if(logfile.is_open()){
		logfile<<logLevelStr(level)<<message<<std::endl;
	} else {
		throw ;
	}
}


LoggerStream&& Logger::log(LogLevel level) {
	return std::move(LoggerStream(*this, level));
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



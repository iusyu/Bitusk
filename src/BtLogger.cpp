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

#include <ctime>

#include "BtLogger.h"


void Logger::log(LogLevel level, const std::string& message){
	if(logfile.is_open()){
		logfile<<getTime()<<" "<<logLevelStr(level)<<message<<std::endl;
	} else {
		throw ;
	}
}


LoggerStream Logger::log(LogLevel level) {
	return LoggerStream(*this, level);
}


const std::string Logger::logLevelStr(LogLevel lv) {
	switch(lv){
	case TRACE:
		return "[TRACE]";
	case DEBUG:
		return "[DEBUG]";
	case INFO:
		return "[INFO]";
	case WARN:
		return "[WARN]";
	case ERROR:
		return "[ERROR]";
	default:
		return "[]";
	}
}


const std::string Logger::getTime() const{
	time_t rawTime;
	struct tm * timeinfo;
	time(&rawTime);
	timeinfo = localtime(&rawTime);
	std::string currentTime {asctime(timeinfo)};
	std::string::iterator end = currentTime.end() - 1;
	*end = ' ';

	return currentTime;
}


LoggerStream::~LoggerStream() {
	const std::string message { stream.str() };
	if( !message.empty()) {
		logger.log(logleve,message);
	}
}



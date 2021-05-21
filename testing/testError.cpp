/*
=============================================
* 
* FileName : testError.cpp
*      date: 2021-05-01 23:48
*    Author: sunyi
*
==============================================
*/
#include <iostream>
#include "BtError.h"
#include "BtLogger.h"
#include "BtParse.h"


// @brief test BtError.h

int main(int argc, char* argv[]) {

	// testError 
	std::cout<<ErrorCatcher::invalidHashError()<<std::endl;

	std::cout<<ErrorCatcher::invalidMessageError()<<std::endl;
	std::cout<<ErrorCatcher::invalidParameterError()<<std::endl;
	std::cout<<ErrorCatcher::invalidSocketError()<<std::endl;
	std::cout<<ErrorCatcher::invalidTrackerReplyError()<<std::endl;
	std::cout<<ErrorCatcher::invalidTrackerUrlError()<<std::endl;

	Logger logger("./test.log");
	logger.log(ERROR)<<ErrorCatcher::invalidParameterError();
	logger.log(ERROR)<<ErrorCatcher::invalidSocketError()<<"port:"<<45;
	logger.log(INFO)<<ErrorCatcher::invalidSocketError()<<"port:"<<45;

	ParseMetaFile btfile("./bt.bittorrent");
	btfile.checkParse();
	
	return 0;
}

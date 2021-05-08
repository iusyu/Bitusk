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
#include "../include/BtLogger.h"
#include "../include/BtError.h"
// @brief test BtError.h

int main(int argc, char* argv[]) {
	Logger logger("test.log");
	logger.log(INFO) << ErrorCatcher::invalidMessageError()<< "\n";
	return 0;
}

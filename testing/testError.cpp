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
// @brief test BtError.h

int main(int argc, char* argv[]) {
	std::cout<<ErrorCatcher::invalidHashError()<<std::endl;
	return 0;
}

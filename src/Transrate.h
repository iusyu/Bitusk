/*
=============================================
* @brief    : Peer class to manage peers
* @copyright: Copyright 2021 iusyu
* @license  : Apache
* @birth    : 2021-06-05 23:48
* @author   : sunyi
* @version  : 0.1.0
* @revisions: 2021-06-20
==============================================
*/


#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <utility>
#include <vector>
#include <map>
#include <list>
#include <chrono>

namespace Bitusk{

class TransformSpeed{
public:
	TransformSpeed();
	TransformSpeed(long long);
	typedef std::chrono::system_clock::time_point duration_type;
	typedef std::pair<duration_type, long long> speed_type;

	long long& operator++();
	long long& operator+=(long long);
	TransformSpeed& add(long long);
	const double rate() const;
	
	TransformSpeed& reset();

	operator double() const ;

private:
	speed_type data;
	
};


class DisplaySpeed{
public:



};

}; // namespace Bitusk

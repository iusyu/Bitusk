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


#include "Subscriber.h"

namespace Bitusk{


/*! Abstract Speed Class provide API of speed */
class Speed{
public:
	virtual double getSpeedOf() = 0;
};


/*! Network transform speed counting class, 
 *  also provide a API of subject of Observer Design Pattern */
class TransformSpeed: public Subject, public Speed{
public:
	TransformSpeed();
	TransformSpeed(size_t);
	typedef std::chrono::system_clock::time_point duration_type;

	size_t& operator++();
	size_t& operator+=(size_t);
	TransformSpeed& add(size_t);
	const double rate() const;
	
	TransformSpeed& reset();

	operator double() const ;

private:
	duration_type timepoint;
	size_t counting;
};


class DisplaySpeed: Observer{
public:

};

}; // namespace Bitusk

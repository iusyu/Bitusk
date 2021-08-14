/*
=============================================
* @brief    : Bt downloader logger 
* @copyright: Copyright 2021 iusyu
* @license  : Apache
* @birth    : 2021-05-01 23:48
* @author   : sunyi
* @version  : 0.1.0
* @revisions: 2021-05-22
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
#include <bitset>
#include <list>
#include <algorithm>
#include <iterator>

#include "Transrate.h"


using namespace Bitusk;


TransformSpeed::TransformSpeed():timepoint(std::chrono::system_clock::now()),counting(0)
{
}


TransformSpeed::TransformSpeed(size_t n):timepoint(std::chrono::system_clock::now()), counting(n)
{
}


size_t& TransformSpeed::operator++()
{
	counting++;
	return counting;
}


TransformSpeed& TransformSpeed::add(size_t n){
	counting+= n;
	return *this;
}

size_t& TransformSpeed::operator+=(size_t n)
{
	add(n);
	return counting;
}


const double TransformSpeed::rate() const 
{	
	auto dura = std::chrono::system_clock::now() - timepoint;
	double rate = (double)counting / std::chrono::duration_cast<std::chrono::seconds>(dura).count();
	return rate;
}


TransformSpeed& TransformSpeed::reset()
{
	counting = 0;
	timepoint = std::chrono::system_clock::now();
	return *this;
}

TransformSpeed::operator double() const
{
	return rate();
}




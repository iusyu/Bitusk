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


TransformSpeed::TransformSpeed():data.first(std::chrono::system_clock::now()),data.second(0)
{
}


TransformSpeed::TransformSpeed(long long n):data.first(std::chrono::system_clock::now()), data.second(n)
{
}


long long& TransformSpeed::operator++()
{
	data.second++;
	return data.second;
}


TransformSpeed& TransformSpeed::add(long long n){
	data.second += n;
	return *this;
}


long long& TransformSpeed::operator+=(long long n)
{
	add(n);
	return data.second;
}


const double TransformSpeed::rate() const 
{	
	auto dura = std::chrono::system_clock::now() - data.first;
	double rate = (double)data.second / std::chrono::duration_cast<std::chrono::seconds>(dura).count();
	return rate;
}


TransformSpeed& TransformSpeed::reset()
{
	data.second = 0;
	data.first = std::chrono::system_clock::now();
	return *this;
}

TransformSpeed::operator double() const
{
	rate();
}




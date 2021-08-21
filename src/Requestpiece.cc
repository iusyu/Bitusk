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

#include "Requestpiece.h"
#include "Policy.h"
#include "data.h"


using namespace Bitusk;

RequestPiece::RequestPiece(): index(0), begin(0),length(0){
}


RequestPiece::RequestPiece(const size_t i, const size_t b, const size_t l):index(i), begin(b), length(l)
{
}


RequestPiece::RequestPiece(const size_t i):RequestPiece(i,0,12)
{
}


RequestPiece::RequestPiece(const size_t i, const size_t l):RequestPiece(i,0,l) 
{
}


const size_t RequestPiece::getIndex() const
{
	return index;
}


const size_t RequestPiece::getBegin() const
{	
	return begin;
}


const size_t RequestPiece::getLength() const
{
	return length;
}


RequestPiece& RequestPiece::setIndex(const size_t i)
{
	index = i;
	return *this;
}


RequestPiece& RequestPiece::setBegin(const size_t b)
{
	begin = b;
	return *this;
}


RequestPiece& RequestPiece::setLength(const size_t l)
{
	length = l;
	return *this;
}


RequestPiece::operator std::string()
{
	std::string tmp;
	// convert to string to send.

	return tmp;
}
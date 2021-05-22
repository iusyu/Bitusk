/*
=============================================
* @brief    : Bt bit field manager 
* @copyright: Copyright 2021 iusyu
* @license  : Apache
* @birth    : 2021-05-22 23:48
* @author   : sunyi
* @version  : 0.1.0
* @revisions: 
==============================================
*/

#pragma once

#include <iostream>
#include <memory>

class Bitmap{
public:
	Bitmap();
	Bitmap(std::size_t b):validBits(b),bitfieldLength(validBits/8 +1), bits(new char[bitfieldLength]) {}
	Bitmap(const Bitmap&) = delete;
	Bitmap& setBit(size_t indx);
	Bitmap& setBitOn(size_t indx);
	Bitmap& setBitOff(size_t indx);
	Bitmap& setAllZero();
	Bitmap& setAllOne();

	bool getBitStatus(size_t indx);
	std::size_t countOffBit() const;
	std::size_t countOnBit() const;
	Bitmap& display() const;
	bool operator==(const Bitmap&);

private:
	// Used bits;
	std::size_t validBits;

	// Allocated bits;
	std::size_t bitfieldLength;

	std::unique_ptr<char[]> bits;

};

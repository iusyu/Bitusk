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
	Bitmap(std::size_t);
	Bitmap(const Bitmap&) = delete;
	Bitmap& setBit(size_t indx);
	Bitmap& setBitOn(size_t indx);
	Bitmap& setBitOff(size_t indx);
	Bitmap& setAllZero();
	Bitmap& setAllOne();

	bool getBitStatus(size_t indx);
	std::size_t countZeroBit() const;
	std::size_t countOneBit() const;
	Bitmap& display() const;
	bool operator==(const Bitmap&);

private:
	// Used bits;
	std::size_t validBits;

	// Allocated bits;
	std::size_t bitfieldLength;

	// If just need 1 Byte ?
	std::unique_ptr<char[]> bits;

	std::size_t zeroBitsNumber;
	std::size_t oneBitsNumber;

};

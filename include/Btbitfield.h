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

static const unsigned char bitOn[8]   = {0b10000000,
					0b01000000,
					0b00100000,
					0b00010000,
					0b00001000,
					0b00000100,
					0b00000010,
					0b00000001};
static const unsigned char bitMask[8] ={0b01111111,
					0b10111111,
					0b11011111,
					0b11101111,
					0b11110111,
					0b11111011,
					0b11111101,
					0b11111110};

static const unsigned char bitAllOn  = 0b11111111;
static const unsigned char bitAllOff = 0b00000000;

class Bitmap{
public:
	Bitmap();
	Bitmap(std::size_t);
	Bitmap(std::size_t, std::size_t, std::size_t);
	Bitmap(const Bitmap&) = delete;
	Bitmap& reverseBit(size_t indx);
	Bitmap& reverseAllBit();
	Bitmap& setBitOn(size_t indx);
	Bitmap& setBitOff(size_t indx);
	Bitmap& setAllZero();
	Bitmap& setAllOne();

	bool getBitStatus(size_t indx) ;
	std::size_t countZeroBit() const;
	std::size_t countOneBit() const;
	Bitmap& display() const;
	bool operator==(const Bitmap&);

	~Bitmap();
private:

	Bitmap& getPos(size_t ,size_t *, size_t*);

private:
	// Used bits;
	std::size_t validBits;

	// Allocated bits;
	std::size_t bitfieldLength;

	// If just need 1 Byte ?
	std::unique_ptr<unsigned char[]> bits;
	unsigned char *pbits;

	std::size_t zeroBitsNumber;
	std::size_t oneBitsNumber;

	bool rwStatus;

};


/* out stream */

std::ostream& operator<<(std::ostream& , const Bitmap&);
std::istream& operator>>(std::istream&, Bitmap&);

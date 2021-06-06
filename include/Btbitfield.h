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

// unnessary 

class Bitmap{

friend std::ostream& operator<<(std::ostream&, const Bitmap&);
friend std::istream& operator>>(std::istream&, Bitmap&);

public:
	Bitmap();
	Bitmap(std::size_t);
	Bitmap(std::size_t, std::size_t, std::size_t);
	Bitmap(const Bitmap&) = delete;

	/* Reverse bits */
	Bitmap& reverseBit(size_t indx);
	Bitmap& reverseAllBit();

	/* set a bit */
	Bitmap& setBitOn(size_t indx);
	Bitmap& setBitOff(size_t indx);
	Bitmap& setAllZero();
	Bitmap& setAllOne();

	/* set bits range */
	Bitmap& setBitsOn(size_t, size_t);
	Bitmap& setBitsOff(size_t, size_t);

	bool getBitStatus(size_t indx) ;
	std::size_t countZeroBit() const;
	std::size_t countOneBit() const;
	bool operator==(const Bitmap&);

	~Bitmap();
private:

	Bitmap& getPos(size_t ,size_t *, size_t*);
	Bitmap& displayUnsignedChar(unsigned char P);


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








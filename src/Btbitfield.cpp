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

#include "Btbitfield.h"


Bitmap::Bitmap():validBits(0),bitfieldLength(0),zeroBitsNumber(0),oneBitsNumber(0) {
}

Bitmap::Bitmap(std::size_t b):validBits(b),bitfieldLength(validBits/8 +1), bits(new unsigned char[bitfieldLength]) {
	setAllZero();
	zeroBitsNumber = validBits;
	oneBitsNumber = validBits - b;
}


Bitmap::Bitmap(std::size_t b, std::size_t begin, std::size_t end):Bitmap(b) {
	// TODO a alittle bit hard
}


Bitmap& Bitmap::reverseBit(size_t indx) {
}


Bitmap& Bitmap::reverseAllBit() {
}


Bitmap& Bitmap::setBitOn(size_t indx) {
	if(indx > validBits)
		return *this;
	size_t charNum = 0, wiseIndx = 0;
	getPos(indx, &charNum, &wiseIndx);
	pbits[charNum] |= bitOn[ wiseIndx ];
	return *this;
}


Bitmap& Bitmap::setBitOff(size_t indx) {
	if( indx > validBits)
		return *this;
	size_t charNum = 0, wiseIndx = 0;
	getPos(indx, &charNum, &wiseIndx);
	pbits[charNum] ^= bitOn[wiseIndx];
	return *this;
}


Bitmap& Bitmap::setAllZero() {

	for( size_t i = 0; i < bitfieldLength / 8; i++ ) {
		pbits[i] = bitAllOff;
	}
	return *this;
}


Bitmap& Bitmap::setAllOne() {
	for( size_t i = 0; i < bitfieldLength / 8; i++ ) {
		pbits[i] = bitAllOn;
	}
	return *this;
}


bool Bitmap::getBitStatus(size_t indx){
	if(indx > validBits){
		rwStatus = false;
		return false;
	}

	size_t charNum = 0, wiseIndx = 0;
	getPos(indx, &charNum, &wiseIndx);
	unsigned char tmp = pbits[charNum];
	return  bitOn[wiseIndx];
}


size_t Bitmap::countOneBit() const {
}


size_t Bitmap::countZeroBit() const {
}


Bitmap& Bitmap::display() const {
}


bool Bitmap::operator==( const Bitmap& bitmap) {
	
}


Bitmap::~Bitmap() {
	delete[] pbits;
}


Bitmap& Bitmap::getPos(size_t idx, size_t* charBitPos, size_t* charIndx) {
	if( charBitPos == nullptr || charIndx == nullptr)
		return *this;
	*charBitPos = idx / 8 +1;
	*charIndx = idx % 8;
	return *this;
}


std::ostream& operator<<(std::ostream& os, const Bitmap& bitmap) {

	return os;
}


std::istream& operator>>(std::istream& is, Bitmap& bitmap) {
	return is;
}



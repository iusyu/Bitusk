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
	if(indx > validBits)
		return *this;

	if( getBitStatus(indx) ) {
		oneBitsNumber--;
		zeroBitsNumber++;
	} else {
		oneBitsNumber++;
		zeroBitsNumber--;
	}
	size_t charNum = 0, wiseIndx = 0;
	getPos(indx, &charNum, &wiseIndx);
	pbits[charNum] ^= (0b10000000 >> wiseIndx);
	return *this;
}


Bitmap& Bitmap::reverseAllBit() {
	for( int i = 0; i <validBits; i++ ) {
		reverseBit(i);
	}
	return *this;
}


Bitmap& Bitmap::setBitOn(size_t indx) {
	if(indx > validBits)
		return *this;

	size_t charNum = 0, wiseIndx = 0;
	getPos(indx, &charNum, &wiseIndx);

	/* bitwise tricks */
	pbits[charNum] |= ( 0b10000000 >> wiseIndx );
	oneBitsNumber++;
	zeroBitsNumber--;
	//pbits[charNum] |= bitOn[ wiseIndx ];
	return *this;
}


Bitmap& Bitmap::setBitOff(size_t indx) {
	if( indx > validBits)
		return *this;
	size_t charNum = 0, wiseIndx = 0;
	getPos(indx, &charNum, &wiseIndx);

	pbits[charNum] &= ~( 0b10000000 >> wiseIndx);
	zeroBitsNumber++;
	oneBitsNumber--;
	//pbits[charNum] ^= bitOn[wiseIndx];
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
		// TODO maybe use Exception 
	}

	size_t charNum = 0, wiseIndx = 0;
	getPos(indx, &charNum, &wiseIndx);
	return (pbits[charNum] & ( 0b10000000 >> wiseIndx) ) >0;
}


size_t Bitmap::countOneBit() const {
	return oneBitsNumber;
}


size_t Bitmap::countZeroBit() const {
	return zeroBitsNumber;
}


bool Bitmap::operator==( const Bitmap& bitmap) {
	// TODO 
	// if two maps have differe size of bit??
	if( this->validBits != bitmap.validBits ) {
		throw;
	}
	for(
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
	for( int i = 0; i < bitmap.bitfieldLength / 8; i++ ) {
		for( int ci = 0b100000000; ci > 0; ci /= 2 ) {
			if( bitmap.pbits[i] & ci) {
				os<<"1";
			} else {
				os<<"0";
			}
		}
		os<<" ";
		if( i % 4 == 0 ) {
			os<<std::endl;
		}
	}
	return os;
}


std::istream& operator>>(std::istream& is, Bitmap& bitmap) {
	return is;
}



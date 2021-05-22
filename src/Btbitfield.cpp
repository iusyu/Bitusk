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

Bitmap::Bitmap(std::size_t b):validBits(b),bitfieldLength(validBits/8 +1), bits(new char[bitfieldLength]) {
	setAllZero();
}


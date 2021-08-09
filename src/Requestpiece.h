/*
=============================================
* @brief    : Peer class to manage peers
* @copyright: Copyright 2021 iusyu
* @license  : Apache
* @birth    : 2021-06-05 23:48
* @author   : sunyi
* @version  : 0.1.0
* @revisions: 2021-06-20
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
#include <list>
#include <chrono>

namespace Bitusk{


class RequestPiece{
public:
	RequestPiece();
	RequestPiece(const size_t);
	RequestPiece(const size_t, const size_t);
	RequestPiece(const size_t, const size_t, const size_t);
	const size_t getIndex() const;
	const size_t getBegin() const;
	const size_t getLength() const;
	RequestPiece& setIndex(const size_t);
	RequestPiece& setBegin(const size_t);
	RequestPiece& setLength(const size_t);

	operator std::string();
private:
	size_t index;
	size_t begin;
	size_t length;

/*******************
 *    Piece
 * -----|--------
 *|  :  |
 *|  :| |
 * ---|----------
 *  offset of Piece(slice)
 *******************
 */
};


class updownloadInfo{
public:

	updownloadInfo();


	updownloadInfo& setStartReceiveTimeStamp(btpoint);


private:
	size_t downloadTotal;
	size_t uploadTotal;
};


}; // namespace Bitusk

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

#include "Peer.h"
#include "Policy.h"
#include "data.h"


int Peer::getSocket() const
{
	return this->socket;
}


Peer& Peer::setSocket(int sock)
{
	this->socket = sock;
	return *this;
}


const std::string& Peer::getIPaddress() const
{
	return this->ipAddress;
}


Peer& Peer::setIPaddress(const std::string& ipaddr)
{
	this->ipAddress = ipaddr;
	return *this;
}


unsigned short Peer::getPort() const
{
	return this->port;
}


Peer& Peer::setPort(unsigned short pp)
{
	this->port = pp;
	return *this;
}


const std::string& Peer::getID() const
{
	return this->id;
}


Peer& Peer::setPeerState(PeerState state)
{
	this->state = state;
	return *this;
}


Peer& Peer::setAmChoking(bool bl)
{
	this->amChoking = bl;
	return *this;
}


Peer& Peer::setAmInterested(bool bl)
{
	this->amInterested = bl;
	return *this;
}


Peer& Peer::setPeerChoking(bool bl)
{
	this->peerChoking = bl;
	return *this;
}


Peer& Peer::setPeerInterested(bool bl)
{
	this->peerInterested = bl;
}


Peer::bitfield_type& Peer::getBitsetRef()
{
	return this->bitfield;
}


std::vector<char>& Peer::getBufferRef()
{
	return this->inBuff;
}


std::vector<char>& Peer::getOutMessageRef()
{
	return this->outMessage;
}


std::vector<char>& Peer::getCopyMessageRef()
{
	return this->messageCopy;
}


Peer& Peer::setNextSendMsgOffset(size_t n)
{
	this->NextSendMessageOffset = n;
	return *this;
}


size_t Peer::getNextSendMsgOffset() const
{
	return this->NextSendMessageOffset;
}


// TODO  rewrite with function overload
std::vector<char>::iterator& Peer::getRefSendBegin()
{
	return this->SendBegin;
}


std::vector<char>::iterator Peer::getSendBegin()
{
	return this->SendBegin;
}


Peer& Peer::setSendBegin(const std::vector<char>::iterator& citr)
{
	this->SendBegin = citr;
	return *this;
}


std::list<RequestPiece>& Peer::getRequestRef()
{
	return this->request;
}


std::list<RequestPiece>& Peer::getRequestedRef()
{
	return this->requested;
}


// section two


size_t Peer::getDownloadTotal() const 
{
	return this->downloadTotal;
}


size_t Peer::getUploadTotal() const
{
	return this->uploadTotal;
}


// TODO fix addDownloadTotal
Peer& Peer::setDownloadTotal(const size_t sz) 
{
	downloadTotal = sz;
	return *this;
}


Peer& Peer::setUploadTotal(const size_t sz)
{
	uploadTotal = sz;
	return *this;
}


// TODO rewrite using std or boost class
Peer& Peer::setStartReceiveTS( time_t tt)
{
}


// counting downloadTotal
Peer& Peer::add_N_ByteToDownload(long long tt)
{
	this->downloadByteCount += tt;
	return *this;
}


Peer& Peer::add_N_ByteToUpload(long long tt)
{
	this->uploadByteCount += tt;
	return *this;
}


long long Peer::getDownloadByteCount() const
{
	return this->downloadByteCount;
}


long long Peer::getUploadByteCount() const
{
	return this->uploadByteCount;
}


float Peer::caculateDownloadSpeed()
{
	// TODO
}


float Peer::caculateUploadSpeed()
{
	// TODO
}


Peer& Peer::createHandShakeMsg(const std::string& infoHash, const std::string& peerId)
{
	std::string keyword {"BitTorrent protocol"};
	unsigned char c = 0x00;
	this->inBuff.push_back(19);
	std::copy(keyword.begin(),keyword.end(), std::back_insert_iterator<std::vector<char>>(this->inBuff));
	this->inBuff.push_back(c);
	std::copy(infoHash.begin(), infoHash.end(), std::back_insert_iterator<std::vector<char>>(this->inBuff));
	std::copy(peerId.begin(), peerId.end(), std::back_insert_iterator<std::vector<char>>(this->inBuff));
	return *this;
}


Peer& Peer::createKeepAliveMsg()
{
	// TODO
	// how to design the msg module ??
	// Q: different message in here to send
	// just rewrite the message or using msg list??
	
}


Peer& Peer::createChokInterestedMsg(int typ)
{
}


Peer& Peer::createHaveMsg(int index)
{
}


Peer& Peer::createBitfieldMsg()
{
}


Peer& Peer::createRequestMsg(int index, int begin, int length)
{
}


Peer& Peer::createPieceMsg(int index, int begin, char* block)
{
}


Peer& Peer::createCancelMsg(int index, int begin, int length)
{
}


Peer& createPortMsg(int port)
{
}


bool Peer::isCompleteMsg()
{
}


Peer& Peer::parseResponse()
{
}


Peer& Peer::parseResponseUncompleteMsg() 
{
}


Peer& Peer::createResponseMsg()
{
}


Peer& Peer::prepareSendHaveMsg()
{
}


Peer& Peer::discardSendBuffer()
{
}


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

#include "Peer.h"


int Peer::getSocket() const
{
	return this->socket;
}


Peer& Peer::setSocket(int)
{
}


const std::string& Peer::getIPaddress() const
{
	return this->ipAddress;
}


Peer& Peer::setIPaddress(const std::string& ipaddr)
{
}


unsigned short Peer::getPort() const
{
	return this->port;
}


Peer& Peer::setPort(unsigned short pp)
{
}


const std::string& Peer::getID() const
{
	return this->id;
}


Peer& Peer::setPeerState(PeerState state)
{
	
}


Peer& Peer::setAmChoking(bool bl)
{
}


Peer& Peer::setAmInterested(bool bl)
{
}


Peer& Peer::setPeerChoking(bool bl)
{
}


Peer& Peer::setPeerInterested(bool bl)
{
}


Peer::bitfield_type& Peer::getBitsetRef()
{
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
}


Peer& Peer::setNextSendMsgOffset(size_t n)
{
}


size_t Peer::getNextSendMsgOffset() const
{
}

std::vector<char>::iterator& Peer::getRefSendBegin()
{
}


std::vector<char>::iterator Peer::getSendBegin()
{
}


Peer& Peer::setSendBegin(const std::vector<char>::iterator& citr)
{
}


std::list<RequestPiece>& Peer::getRequestRef()
{
}


std::list<RequestPiece>& Peer::getRequestedRef()
{
}




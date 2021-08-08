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
#include "BituskType.h"

namespace Bitusk{


class MessageGenerator{
public:
	typedef std::string msg;
	virtual const ustring::value_type* operator()() = 0;
	virtual void generateMsg() = 0;
	
};


class MessageGeneratorImp: public MessageGenerator{
public:
};

class HandShakeMsg:public MessageGenerator {
public:
	HandShakeMsg(Peer&);
	HandShakeMsg() = delete;
	HandShakeMsg(const HandShakeMsg&) = delete;


	virtual const ustring::value_type* operator()() override;
	virtual void generateMsg() override;

private:
	Bitusk::Peer& peer;
	ustring msg;

};


}; // namespace Bitusk;

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
#include "Message.h"

using namespace Bitusk;


HandShakeMsg::HandShakeMsg(Peer& p):peer(p)
{
}

const ustring::value_type* HandShakeMsg::operator()()
{
	generateMsg();
	return msg.c_str();
}

void HandShakeMsg::generateMsg()
{
	int i;
	unsigned char keyword[20] = "BitTorrent protocol", c = 0x00;
	unsigned char *buffer = peer.getInfoHansh();
	msg.push_back(0x00);
}

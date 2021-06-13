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

template <typename T, std::size_t N = 1024>
class buffer {
public:
	typedef T type;
	buffer(const buffer<T>& b);
	buffer() = default;
private:
	type ptrToBuf[N];
};


struct RequestPiece{
	typedef std::vector<char>::iterator char_itr;
	char_itr index;
	char_itr begin;
	size_t length;
};

template<std::size_t N>
class Peer{
public:
	enum class PeerState { Initial, HalfShaked, HandShaked, ReceivedBitfield, SendBitfield, Data, Closing };
	enum class DataState { am_choking, am_interested, peer_choking, peer_interested};

	Peer();

	int& getSocket();
	std::string& getIP();
	unsigned short& getPort();
	std::string& getID();
	
	Peer& setPeerState(PeerState);
	Peer& setAmChoking(bool);
	Peer& setAmInterested(bool);
	Peer& setPeerChoking(bool);
	Peer& setPeerInterested(bool);

	std::bitset<N>& getBitset();

	std::vector<char>& getBuff();
	std::vector<char>& getOutMessage();
	std::vector<char>& getCopyMessage();
	
	Peer& setNextSendMsgOffset(size_t);
	Peer& getNextSendMsgOffset() const;
	std::vector<char>::iterator& getRefSendBegin();
	std::vector<char>::iterator getSendBegin();
	Peer& setSendBegin(const std::vector<char>::iterator&);
	std::list<RequestPiece>& getRequest();
	std::list<RequestPiece>& getRequested();




private:
	int  socket;
	std::string ipAddress;
	unsigned short port;
	std::string id;
	
	PeerState state;
	DataState amChoking;
	DataState amInterested;
	DataState peerChoking;
	DataState peerInterested;

	std::bitset<N> bitfield;

	std::vector<char> inBuff;
	std::vector<char> outMessage;
	std::vector<char> messageCopy;
	// maybe have a represent than this
	std::size_t NextSendMessageOffset;
	std::vector<char>::iterator SendBegin;
	std::list<RequestPiece> request;
	std::list<RequestPiece> requested;

	size_t getDownloadTotal()const ;
	size_t getUploadTotal() const;

	Peer& setDownloadTotal(const size_t);
	Peer& setUploadTotal(const size_t);

	size_t downloadTotal;
	size_t uploadTotal;

	Peer& setStartReceiveTS(time_t);
	time_t getStartReceiveTS();

	time_t startReceiveTimeStamp;
	time_t recentSendTimeStamp;
	time_t lastDownloadTimestamp;
	time_t lastUploadTimestamp;

	long long downloadByteCount;
	long long uploadByteCount;
	
	float downloadRate;
	float uploadRate;
};


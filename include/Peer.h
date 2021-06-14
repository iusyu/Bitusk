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
	friend class MessageGenerator;
	friend class MessageGeneratorImp;
	friend std::ostream& operator<<(std::ostream& , const Peer<N>& );

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

	// API design should be careful

	size_t getDownloadTotal()const ;
	size_t getUploadTotal() const;

	Peer& setDownloadTotal(const size_t);
	Peer& setUploadTotal(const size_t);

	Peer& setStartReceiveTS(time_t);
	time_t getStartReceiveTS() const ;

	Peer& setLastDownloadTS();
	time_t getLastDownloadTS() const ;

	Peer& setLastUploadTS();
	time_t getLastUploadTS() const ;

	Peer& add_N_ByteToDownload(long long);
	Peer& add_N_ByteToUpload(long long);
	long long getDownloadByteCount() const;
	long long getUploadByteCount() const;

	float caculateDownloadSpeed();
	float caculateUploadSpeed();

	// Create serveral type message 
	Peer& createHandShakeMsg(const std::string& infoHash, const std::string& peerId);
	Peer& createKeepAliveMsg();
	Peer& createChokInterestedMsg(int type); // TODO rethink there parameter
	Peer& createHaveMsg(int index);
	Peer& createBitfieldMsg();
	Peer& createRequestMsg(int index, int begin, int length);
	Peer& createPieceMsg(int index, int begin, char* block); // TODO different with C++
	Peer& createCancelMsg(int index, int begin, int length);
	Peer& createPortMsg(int port);

	// TODO see source code to understanding
	bool isCompleteMsg();
	Peer& parseResponse();
	Peer& parseResponseUncompleteMsg();
	Peer& createResponseMsg();
	Peer& prepareSendHaveMsg();
	Peer& discardSendBuffer();

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
	// maybe have a better represent than this
	std::size_t NextSendMessageOffset;
	std::vector<char>::iterator SendBegin;
	std::list<RequestPiece> request;
	std::list<RequestPiece> requested;
	size_t downloadTotal;
	size_t uploadTotal;

	time_t startReceiveTimeStamp;
	time_t recentSendTimeStamp;
	time_t lastDownloadTimestamp;
	time_t lastUploadTimestamp;

	long long downloadByteCount;
	long long uploadByteCount;
	
	float downloadRate;
	float uploadRate;
};

template<std::size_t N>
std::ostream& operator<<(std::ostream& os, const Peer<N>& pp);



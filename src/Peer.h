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

#include <boost/asio.hpp>


#include "BituskType.h"
#include "Requestpiece.h"

namespace Bitusk{

class Peer{
	friend class MessageGenerator;
	friend class MessageGeneratorImp;
	friend std::ostream& operator<<(std::ostream& , const Peer& );

public:
	enum class PeerState { Initial, HalfShaked, HandShaked, ReceivedBitfield, SendBitfield, Data, Closing };

	Peer();

	int getSocket() const;
	Peer& setSocket(int);
	const std::string& getIPaddress() const;
	Peer& setIPaddress(const std::string&);
	unsigned short getPort() const;
	Peer& setPort(unsigned short);
	const std::string& getID() const;
	Peer& setID(const std::string&);
	
	Peer& setPeerState(PeerState);
	Peer& setAmChoking(bool);
	Peer& setAmInterested(bool);
	Peer& setPeerChoking(bool);
	Peer& setPeerInterested(bool);


	std::list<RequestPiece>& getRequestRef();
	std::list<RequestPiece>& getRequestedRef();

	// API design should be careful

	size_t getDownloadTotal()const ;
	size_t getUploadTotal() const;

	Peer& setDownloadTotal(const size_t);
	Peer& setUploadTotal(const size_t);

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

	typedef std::string msg_type;

private:

	/// ======== Per Peer Id info
	socket_ptr socket;
	endpeer addr;
	std::string id;
	
	PeerState state;
	bool amChoking;
	bool amInterested;
	bool peerChoking;
	bool peerInterested;

	msg_type inBuff;
	msg_type outMessage;
	msg_type messageCopy;
	// maybe have a better represent than this
	std::list<RequestPiece> request;
	std::list<RequestPiece> requested;


	size_t downloadTotal;
	size_t uploadTotal;
};

template<std::size_t N>
std::ostream& operator<<(std::ostream& os, const Peer& pp);


}; // namespace Bitusk

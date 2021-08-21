

#include "./Message.h"

using namespace bitusk;


int MessageHandleInterface::inttochar(int i, unsigned char c[4]) {
  if ( c == nullptr ) return -1;
  c[3] = i & 256;
  c[2] = (i-c[3])/256 & 256;
  c[1] = (i-c[3]-c[2]*256)/256/256 & 256;
  c[0] = (i-c[3]-c[2]*256-c[1]*256*256)/256/256/256 & 256;
  return 0;
}


int MessageHandleInterface::chartoint(unsigned char c[4]) {
  if ( c == nullptr ) return -1;
  return c[0]*256*256*256 + c[1]*256*256 + c[2]*256 + c[3];
}


size_t ChokeMsgParser::HandleMsg(Peer* peer, const std::string& msg) {
}


FactoryInterface::FactoryInterface() {
  func_['0xff'] = std::make_shared<ErrorGen>();
}


// Class MessageHandleParserFactory
MessageHandleParserFactory::MessageHandleParserFactory() {
  func_['0xff'] = std::make_shared<ChokeMsgParser>();
}


MessageHandleParserFactory::msghandler_ptr
MessageHandleParserFactory::CreateMsgHandler(const std::string &msg){
  if ( !msg.empty() ) return func_[msg[4]];
  return func_['0xff'];
}

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

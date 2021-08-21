// License BSD
// Author uttep
//

#include <iostream>
#include <vector>
#include <map>
#include <exception>
#include <memory>



#pragma once

namespace bitusk{
class Peer;

class MessageHandleInterface{
public:
  MessageHandleInterface();
  ~MessageHandleInterface();
  virtual size_t HandleMsg(Peer* peer, const char* msg) = 0;
  virtual size_t HandleMsg(Peer* peer, const std::string& msg) = 0;
protected:
  int inttochar(int i, unsigned char c[4]);
  int chartoint(unsigned char c[4]);
};


class ChokeMsgParser:public MessageHandleInterface {
public:
  ChokeMsgParser();
  ~ChokeMsgParser();
  virtual size_t HandleMsg(Peer* peer, const char* msg) override;
  virtual size_t HandleMsg(Peer* peer, const std::string& msg) override;
};


class MsgError: public MessageHandleInterface, public std::exception {
public:
  virtual size_t HandleMsg(Peer* peer, const char* msg) override;
  virtual size_t HandleMsg(Peer* peer, const std::string& msg) override;
};


// Message Handler Generator


class FactoryInterface {
public:
  typedef std::map<char,std::shared_ptr<MessageHandleInterface>> rpc_type;
  typedef std::shared_ptr<MessageHandleInterface> msghandler_ptr;

  FactoryInterface();
  virtual msghandler_ptr CreateMsgHandler(const std::string& msg);
  virtual msghandler_ptr CreateMsgHandler(Peer* peer);
protected:
  rpc_type func_;
};


class MessageHandleGenFactory: public FactoryInterface {
public:
  msghandler_ptr CreateMsgHandler(const std::string &msg) override;
};


class MessageHandleParserFactory: public FactoryInterface {
public:
  MessageHandleParserFactory();
  msghandler_ptr CreateMsgHandler(const std::string& msg) override;
};

}; // namespace bitusk;

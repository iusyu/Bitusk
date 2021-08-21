// License (BSD)
// Author uttep

#include <streambuf>
#include <arrary>

struct BtCache{
#ifdef #STREAMBUF
  typedef std::basic_streambuf<unsigned char> btbuf_type;
#elif
  typedef std::arrary<unsigned char,16*1024> btbuf_type;
#endif

  BtCache() : buf(), pieceindex(0), pieceoffset(0), accesscount(9),
              inuse(0), readwrite(0), isfull(0), writedtodisk(0) {}
  btbuf_type buf;
  int pieceindex;
  int pieceoffset;
  int accesscount;
  unsigned char inuse;
  unsigned char readwrite;
  unsigned char isfull;
  unsigned char writedtodisk;
};


class CacheCenter{
public:
  CacheCenter(): cache_(1024) {}
  CacheCenter(unsigned long sz): cache_(sz) {}


private:
  std::vector<BtCache> cache_;
};

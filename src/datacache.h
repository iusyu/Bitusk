#ifndef BITUSK_SRC_DATACACHE_H
#define BITUSK_SRC_DATACACHE_H

#include <iostream>
#include <vector>
#include <memory>
#include <utility>


#define USE true
#define NOTUSE false
#define READ false
#define WRITE true
#define WROTE true
#define NONEWROTE false

constexpr size_t kSliceSize = 16 * 1024;
constexpr size_t kMaxCacheNode = 1024;
constexpr size_t kPieceSteps = 16;
constexpr size_t kPieceSizeByte = 256 * 1024;



// AbsSwapPolicy
template<typename PA, typename PB>
class AbsSwapPolicy{
public:
  virtual int GetNiceBlock(const std::vector<PA,PB>& container) = 0;
};


struct BtCacheNode{
  BtCacheNode();
  BtCacheNode(size_t p, size_t o);
  BtCacheNode(const BtCacheNode& bcache);
  BtCacheNode(BtCacheNode&& bcache);

  // TODO 找个合适的数据结构
  std::vector<unsigned char> buff;
  size_t index;
  size_t offset;
  //size_t length;
};

struct NodeState{
  bool in_use;
  bool read_write;
  bool is_wrote;
  size_t access_count;
};



class BtCacheManager{
public:
  typename std::vector<std::pair<BtCacheNode,NodeState>> CacheType;
  typename std::vector<std::pair<BtCacheNode,NodeState>>::iterator CacheItrType;;
public:
  const BtCacheNode& ReadPiece(size_t piece_index,size_t slice_offset);
  BtCacheManager& WritePiece(const BtCacheNode& bt);
  BtCacheManager& WritePiece(BtCacheNode&& bt);

  bool IsPieceInCache(size_t piece_pos);
public:
  // return value should be optmized
  BtCacheManager& WriteAllToDisk();
  int WritePieceToDisk(size_t piece_index); // will have many node
  BtCacheManager& WriteSliceToDisk(size_t piece_index, size_t slice_offset); // will have many node

// TODO 是否需要这个
  int ReadSliceFromDisk(size_t pos);

  int ReadPieceFromDisk(size_t piece_index);
private:

private:
  std::vector<std::pair<BtCacheNode,NodeState>> cache_;
  std::map<size_t, size_t> piece_table_;

  std::ostream* fstream_;
  std::shared_ptr<AbsSwapPolicy<BtCacheNode,NodeState>> find_empty_block_;
  std::shared_ptr<AbsSwapPolicy<BtCacheNode,NodeState>> swap_policy_;

};



// Find out empty space
template<typename PA, typename PB>
class EmptyBlockFinder: public AbsSwapPolicy {
  virtual int GetNiceBlock(const std::vector<PA,PB>& container);
};



#endif // BITUSK_SRC_DATACACHE_H

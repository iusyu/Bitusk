#include "datacache.h"



BtCacheNode::BtCacheNode():buff(KSLICESIZE), index(0), offset(0) {
}


BtCacheNode::BtCacheNode(size_t p, size_t o):buff(KSLICESIZE), index(p), offset(o) {
}

BtCacheNode::BtCacheNode(const BtCacheNode& bcache): buff(bcache.buff), 
  index(bcache.index), offset(bcache.offset) {
}


BtCacheNode::BtCacheNode(BtCacheNode&& bcache): buff(std::move(bcache.buff)), 
  index(bcache.index), offset(bcache.offset) {
}


const BtCacheNode& BtCacheManager::ReadPiece(size_t piece_index,size_t slice_offset = 0) {
  if ( piece_table_.find(piece_index) == piece_table_.end() ) {
    ReadPieceFromDisk(piece_index);
  }
  auto& ndoestate =  std::get<1>(cache_[piece_table_[piece_index]]);
  nodestate.in_use = USE; // why have this??
  nodestate.read_write = READ;
  nodestate.is_wrote = NONEWROTE;
  nosestate.access_count++;
  return std::get<0>(cache_[piece_table_[piece_index] + slice_offset]); 
}


BtCacheManager& BtCacheManager::WritePiece(const BtCacheNode& bt) {
  if( piece_table_.find(bt.index) == piece_table_.end() ) {
    size_t new_pos = GetEmptySpace();
    piece_table_[new_pos] = bt.index;
  }
  NodeState tmp_state (USE, WRITE, NONEWROTE);
  cache_[bt.index + bt.offset] = std::make_pair(bt, tmp_state);
  return *this;
}


size_t BtCacheManager::GetEmptySpace() {
  if( piece_table_.size() < cache_.size() / kPieceSteps ) {
    return find_empty_block_->GetNiceBlock();
  }
  size_t swap_pos = swap_policy_->GetNiceBlock(cache_);
  WritePieceToDisk(swap_pos);
  return swap_pos;
}


BtCacheManager& BtCacheManager::WritePieceToDisk(size_t piece_index) {
  if( IsPieceInCache() == false ) {
    return *this;
  }
  
  if( cache_[piece_table_[piece_index]].second.read_write == READ ) {
    return *this;
  }

  return *this;
}

BtCacheManager& BtCacheManager::WritePieceToDisk(size_t piece_index, size_t slice_offset) {
  if( IsPieceInCache() == false ) {
    return *this;
  }
  auto& tmp_ref = cache_[piece_table_[piece_index]];
  fstream_->seekp(piece_index * kPieceSizeByte);
  fstream_ << tmp_ref.first.buff;
}

BtCacheManager& BtCacheManager::ReadPieceFromDisk(size_t piece_index) {
  if ( IsPieceInCache() == true ) {
    return *this;
  }

  for ( size_t i = 0; i < kPieceSteps; ++i ) {
    WriteSliceToDisk(size_t piece_index, size_t slice_offset);
  }
}


BtCacheManager& BtCacheManager::ReadSliceFromDisk(size_t piece_index, size_t slice_offset) {
  
}




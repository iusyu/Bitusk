#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <utility>
#include "BtParse.h"



/* struct BittorrentData IMP */
BittorrentData::BittorrentData() {
}


bool BittorrentData::empty() const {
	return info.empty();
}


/* class SegmentParse IMP */

std::string SegmentParse::parseInt(strIterator& itr) {
	std::string tmp;
	for(; *itr != 'e'; itr++ ) {
		tmp.push_back(*itr);
	}

	return tmp;
}

unsigned SegmentParse::parseStrLen(strIterator& itr) {
	std::string tmp;
	for(; *itr != ':'; itr++) {
		tmp.push_back(*itr);
	}
	itr++;
	return std::stoul(tmp,NULL);
}


std::string SegmentParse::parseStr(strIterator& itr) {
	std::string tmp;
	unsigned len = parseStrLen(itr);
	for( size_t i = 0; i < len; i++ ){
		tmp.push_back(*itr++);
	}
	return tmp;
}


std::pair<std::string, unsigned long> SegmentParse::parseDictPair(std::string::iterator& itr) {
	SegmentParse::getSegment(itr);
	unsigned long len = std::stoul(SegmentParse::getSegment(itr));
	SegmentParse::getSegment(itr);
	std::string filepath = SegmentParse::getSegment(itr);
	return std::make_pair(filepath, len);
}


std::string SegmentParse::getSegment(strIterator& itr) {
	switch(*itr) {
		case 'i':
			return parseInt(++itr);
		default:
			return parseStr(itr);
	}
}


/* class ParseInfo IMP */
ParseInfo::valueType ParseInfo::parsing(const std::string& btFile, const std::string& key = "") {
	return parseInfo(btFile, key);
}


ParseInfo::valueType ParseInfo::parseInfo(const std::string& srcStr, const std::string& key) {
	BaseParse::valueType dic;
	auto itr = srcStr.begin();
	srcStr.find("5:files");
	
	return dic;

}


/* class ParseMetaFile IMP */
ParseMetaFile::ParseMetaFile(const std::string& fileName) {
	std::ifstream f(fileName);
	if(f) {
		std::string tmpStr{std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>()};
		MetaFileString = tmpStr;
	}

	parseIt();
}


const std::vector<std::string>& ParseMetaFile::getAnnounceList() const {
	return data.announceList;
}


const unsigned ParseMetaFile::getPieceLength() const {
	return data.piece_length;
}


const std::vector<std::string>& ParseMetaFile::getPieceHash() const {
	return data.pieces;
}


const std::vector<std::string>& ParseMetaFile::getFileName() const {
	return data.name;
}


const std::map<std::string, unsigned long>& ParseMetaFile::getFilePathAndLength() const {
	return data.files;
}


const std::string& ParseMetaFile::getInfoHash() const {
	return data.hashStr;
}


const std::string& ParseMetaFile::getPeerId() const {
	return data.peer_id;
}


void ParseMetaFile::parseIt() {
	readAnnounceList();
	readIsMultiFiles();
	readFileLength();
	readPieceLength();
	readFilesLengthPath();
	readInfoHash();
	readPeerId();
}


bool ParseMetaFile::checkParse() {
	return data.empty();
}


void ParseMetaFile::readAnnounceList() {
	std::string::size_type pos = 0;
	if( (pos = MetaFileString.find("13:announce-list")) == std::string::npos){
		if( (pos = MetaFileString.find("8:announce") )!= std::string::npos)  {
			std::string::iterator itr = MetaFileString.begin() + pos;
			std::string tmp = SegmentParse::getSegment( itr );
			data.announce = SegmentParse::getSegment(itr);
		}
	} else {
		std::string::iterator itr = MetaFileString.begin() + pos;
		std::string tmp = SegmentParse::getSegment(itr);
		for(; *itr != 'e';) {
			data.announceList.push_back( SegmentParse::getSegment(itr));
		}

	}
}


bool ParseMetaFile::readIsMultiFiles() {
	return MetaFileString.find("5:files") != std::string::npos ;
}


void ParseMetaFile::readPieceLength() {
	sizeType pos = 0;
	if( (pos = MetaFileString.find("12:piece_length") )!= std::string::npos) {
		std::string::iterator itr = MetaFileString.begin() + pos;
		data.piece_length = std::stoul(SegmentParse::getSegment(itr));
	}
}


void ParseMetaFile::readPiecesHash() {
	sizeType pos = 0;
	if( (pos = MetaFileString.find("6:pieces")) != std::string::npos) {
		std::string::iterator itr = MetaFileString.begin() + pos;
		std::string tmp = SegmentParse::getSegment(itr);
		data.hashStr = SegmentParse::getSegment(itr);
	}
}


void ParseMetaFile::readFileName() {
	sizeType pos = 0;
	if( (pos = MetaFileString.find("4:name")) != std::string::npos ) {
		std::string::iterator itr = MetaFileString.begin() + pos;
		std::string tmp = SegmentParse::getSegment(itr);
		data.name = SegmentParse::getSegment(itr);
	}
}


void ParseMetaFile::readFileLength() {
	sizeType pos = 0;
	if( readIsMultiFiles() ) {

		// many files need to read
		readFilesLengthPath();
	} else {
		if( (pos = MetaFileString.find("6:length")) != std::string::npos ) {
			std::string::iterator itr = MetaFileString.begin() + pos;
			std::string tmp = SegmentParse::getSegment(itr);
			unsigned long len = std::stoul( SegmentParse::getSegment(itr) );

			std::string filepath = SegmentParse::getSegment(itr);

			data.files[filepath] = len;
			
		}
	}
}

void ParseMetaFile::readFilesLengthPath() {
	std::vector<char> stack;
	// TODO check position isn't right
	std::string::iterator itr = MetaFileString.begin() + MetaFileString.find("5:files") + 7;
	do{
		switch( *itr ) {
			case 'd':
				stack.push_back(*itr);
				itr++;
				data.files.insert(SegmentParse::parseDictPair(itr));
				break;
			case 'l':
				stack.push_back(*itr);
				itr++;
				break;
			case 'e':
				itr++;
				stack.pop_back();
				break;
		}
	}while(!stack.empty());
}


void ParseMetaFile::readInfoHash() {
	std::string::iterator start = MetaFileString.begin() + MetaFileString.find("4:info") + 6;
	std::string::iterator itr = start;
	std::vector<char> stack;
	// TODO debug重灾区
	do {
		switch( *itr ) {
			case 'd':
				stack.push_back( *itr);
				itr++;
				SegmentParse::getSegment(itr);
				break;
			case 'l':
				stack.push_back(*itr);
				itr++;
				SegmentParse::getSegment(itr);
				break;
			case 'e':
				stack.pop_back();
				itr++;
				SegmentParse::getSegment(itr);
				break;
			default:
				SegmentParse::getSegment(itr);
				break;
				
		} 

	}while( !stack.empty() );
}

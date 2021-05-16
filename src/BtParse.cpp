#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "BtParse.h"



/* struct BittorrentData IMP */
BittorrentData::BittorrentData() {
	info["piece_length"] = "";
	info["pieces"] 	     = "";
	info["private"]      = "";

	/* single file */
	info["name"]	     = "";
	info["length"]	     = "";
	info["md5sum"] 	     = "";

	/* multifile mode */
	info["name"]         = "";

	files["length"]      = "";
	files["path"]        = "";
	files["md5sum"]	     = "";
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
}


void ParseMetaFile::parseIt() {
	
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
	return MetaFileString.find("5:files") == std::string::npos ;
}


void ParseMetaFile::readPieceLength() {
	sizeType pos = 0;
	if( (pos = MetaFileString.find("12:piece_length") )!= std::string::npos) {
		std::string::iterator itr = MetaFileString.begin() + pos;
		

	}
}

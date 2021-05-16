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


/* class AbsParseMethod IMP */
AbsParseMethod* AbsParseMethod::getParseMethod(const std::string& key) {
	return this;
}



/* class ParseBittorrentFile IMP */
ParseBittorrentFile::ParseBittorrentFile(const std::string& fileName) {
	std::ifstream f(fileName);
	if(f) {
		std::string tmpStr{std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>()};
		bittorrentFileString = tmpStr;
	}
}


const std::string& ParseBittorrentFile::getString(const std::string& key) {
	
}


const std::string& ParseBittorrentFile::getInfoOf(const std::string& key) {
	
}


void ParseBittorrentFile::parseIt() {
	
}


bool ParseBittorrentFile::checkParse() {
	return data.empty();
}

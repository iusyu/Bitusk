/*
=============================================
* @brief    : Bt downloader logger 
* @copyright: Copyright 2021 iusyu
* @license  : Apache
* @birth    : 2021-05-01 23:48
* @author   : sunyi
* @version  : 0.1.0
* @revisions: 2021-05-15
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

class ParseMetaFile;

/* Bittorrent File keyword struct */
struct BittorrentData {
	BittorrentData();

	bool empty() const ;

	/* keyword 'info' has value of diction 
	 * 
	 * to get keyvalue by 'info["name"]'
	 *
	 * common keyword contained
	 * @piece_length : length of every piece
	 * @pieces 	 : a string of hash value
	 * @private 	 : ......
	 *
	 * single file mode
	 * @name
	 * @length
	 * @md5sum
	 *
	 * multifile mode
	 * @name 	 : store all shared files' directory name
	 * @files	 : have a directory value specifing in 'std::map<std::string, std::string> files '
	 * */
	std::map<std::string, std::string> info;


	/* keyword 'info' has keyword 'files' in multifile mode
	 * @length 	 : shared file length, Unit is Byte
	 * @md5sum
	 * @path	 : store the path and name of shared files
	 */
	std::map<std::string, std::string> files;


	/* Tracker URL */
	std::string announce;


	/* Tracker URL list */
	std::vector<std::string> announceList;
};


/* parse four data type */
class SegmentParse {
public:
	typedef std::string::iterator strIterator;
	static std::string parseInt(strIterator& itr);
	static unsigned parseStrLen(strIterator& itr);
	static std::string parseStr(strIterator& itr);
	static std::string getSegment(strIterator& itr);
};


/* using template method */
template<typename T>
class BaseParse {
public:
	typedef T valueType;
	BaseParse() = delete;
	BaseParse(const BaseParse& ) = delete;

	virtual valueType parsing(const std::string&, const std::string&) = 0;
	virtual ~BaseParse();

};


/* parse info keyword */
class ParseInfo:public BaseParse<std::map<std::string,std::string>> {
public:
	virtual valueType parsing(const std::string&, const std::string&) override ;
	valueType parseInfo(const std::string& srcStr, const std::string& key);
};




/* the basic tools for parse String */
class ParseMetaFile {
public:
	using sizeType = std::string::size_type;
	ParseMetaFile() = delete;
	ParseMetaFile(const ParseMetaFile&) = delete;
	ParseMetaFile(const std::string& );
	virtual const std::string& get();
	
	virtual const std::string& getString(const std::string& );

private:
	void parseIt();
	bool checkParse();
	virtual void readAnnounceList();
	virtual bool readIsMultiFiles();
	virtual void readPieceLength();
	virtual void readPieces();
	virtual void readFileName();
	virtual void readFileLength();
	virtual void readLengthPath();
	virtual void readInfoHash();
	virtual void readPeerId();





private:
	BittorrentData data;
	std::string MetaFileString;
};







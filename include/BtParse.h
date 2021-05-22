/*
=============================================
* @brief    : Bt downloader logger 
* @copyright: Copyright 2021 iusyu
* @license  : Apache
* @birth    : 2021-05-01 23:48
* @author   : sunyi
* @version  : 0.1.0
* @revisions: 2021-05-22
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
	unsigned 		 piece_length = 0;
	std::vector<std::string> pieces;
	std::string 		 bprivate;
	std::string		 name;

	/* shared file length */
	unsigned		 length;

	std::string 		path;
	std::map<std::string, std::string> info;


	/* keyword 'info' has keyword 'files' in multifile mode
	 * @length 	 : shared file length, Unit is Byte
	 * @md5sum
	 * @path	 : store the path and name of shared files
	 * key:   file path
	 * value: file length
	 */
	std::map<std::string, unsigned long> files;


	/* Tracker URL */
	std::string announce;


	/* Tracker URL list */
	std::vector<std::string> announceList;

	/* Hash Str */
	std::string hashStr;

	/* Peer ID */
	std::string peer_id;
};


/* parse four data type */
class SegmentParse {
public:
	typedef std::string::iterator strIterator;
	static std::string 		parseInt(strIterator& itr);
	static unsigned 		parseStrLen(strIterator& itr);
	static std::string 		parseStr(strIterator& itr);
	static std::string 		getSegment(strIterator& itr);
	static std::pair<std::string, unsigned long> parseDictPair(std::string::iterator&itr);
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

	bool isMultiFiles() const;
	
	const std::vector<std::string>& getAnnounceList() const;
	const std::string& 		getAnnounce() const;


	const unsigned     		getPieceLength() const;
	const std::vector<std::string>& getPieceHash() const;
	

	/*
	 * @breif 
	 * @return if multi files it will return folder name;
	 *         if single file it will return file name;
	 */
	const std::vector<std::string>&  getFileName() const;

	/*
	 * @breif
	 * @return if multifiles it will return file path and length keyvalue pair
	 * 	   if single     it will return empty data;
	 */
	const std::map<std::string,unsigned long>& getFilePathAndLength() const;

	/*
	 * @breif  Info_hash will be used when connecting Tracker and Peer
	 * @return info hash
	 */
	const std::string& getInfoHash() const;

	/*
	 * @breif  peer_id
	 * @return Peer ID to connecting PEER
	 */
	const std::string& getPeerId() const;

	bool checkParse();
	void parseIt();

private:
	virtual void readAnnounceList();
	virtual bool readIsMultiFiles();
	virtual void readPieceLength();
	virtual void readPiecesHash();
	virtual void readFileName();
	virtual void readFileLength();
	virtual void readFilesLengthPath();
	virtual void readInfoHash();
	virtual void readPeerId();


private:
	BittorrentData data;
	std::string MetaFileString;
};


// // // // // // // // // // // // // 
//
//NEW DESIGN OF PARSE IMP WITH TMP
//
// // // // // // // // // // // // // 

struct INT_tag {};
struct STR_tag {};
struct DIC_tag {};
struct LIS_tag {};



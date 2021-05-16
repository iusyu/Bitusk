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

class ParseBittorrentFile;

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


/* using abstract factory method */
class AbsParseMethod {
public:
	virtual AbsParseMethod* getParseMethod(const std::string&);
	virtual ~AbsParseMethod();
private:
	BittorrentData* str;
};


/* inherit from AbsParseMethod */
class PAnnounce: public AbsParseMethod {
public:
	virtual AbsParseMethod* getParseMethod(const std::string&) override;
	

	
};


/* different method of parse keyvalue */

class AbsParseInfo{
public:
	typedef std::map<std::string,std::string> infoDic;

	AbsParseInfo() = delete;
	AbsParseInfo(const AbsParseInfo&) = delete;

	AbsParseInfo(ParseBittorrentFile* p):pbf(p) {}
	
	virtual infoDic parseInfo() = 0;
	virtual ~AbsParseInfo();
	
private:
	ParseBittorrentFile* pbf;
};


class ParseInfo:public AbsParseInfo {
public:
	ParseInfo(ParseBittorrentFile* p):AbsParseInfo(p) {}
	

	virtual infoDic parseInfo() override ;
};


/* the basic tools for parse String */
class ParseBittorrentFile {
public:
	ParseBittorrentFile() = delete;
	ParseBittorrentFile(const ParseBittorrentFile&) = delete;
	ParseBittorrentFile(const std::string& );
	virtual const std::string& get();
	
	virtual const std::string& getString(const std::string& );

private:
	virtual const std::string& getInfoOf(const std::string&);
	virtual const std::string& getFilesOf(const std::string&);
	virtual const std::vector<std::string>& getListOf(const std::string&);
	void parseIt();
	bool checkParse();





private:
	BittorrentData data;
	std::string bittorrentFileString;
	std::map<std::string,std::shared_ptr<AbsParseMethod>> parseMethod;
};







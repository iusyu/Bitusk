/*
=============================================
* @brief    : Bt downloader logger 
* @copyright: Copyright 2021 iusyu
* @license  : Apache
* @birth    : 2021-05-01 23:48
* @author   : sunyi
* @version  : 0.1.0
* @revisions: NA
==============================================
*/

// * Support this interface Logger << date <<info<< ...;


#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <utility>




/* 种子文件解析中 */
class Parse {
public:
	Parse() = default;
	Parse(const Parse& ) = delete;
	Parse(const Parse&&);
	Parse(const std::string& bf):ifbtstream(bf) {}
	

	/* Application Programming Interface  */

	/*
	 * @brief: find position of value which key specific
	 * @param: key of key-value pair
	 * @ret: begining position of value 
	 * @birth: 2021-05-11
	 */
	virtual std::string::iterator findKeyPos(const std::string&);

	/*
	 * @brief: find value with key
	 * @param: key which to find [const std::string& ]
	 * @ret: value of key
	 * @birth: 2021-05-11
	 */
	virtual const std::string findKeyValue(const std::string&);

	


private:
	std::ifstream ifbtstream;
};






int main(int argc, char* argv[]) {
	Parse bt("....");

	
}

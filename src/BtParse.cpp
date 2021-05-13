#include <iostream>
#include <string>
#include <vector>

#include "BtParse.h"



AbsParse::AbsParse(const AbsParse&& ap):ifbtstream(std::move(ap.ifbtstream)){
}


std::string::iterator AbsParse::findKeyPos(const std::string& key) {
	
}


const std::string AbsParse::findKeyValue(const std::string& key) {
	
}


Parse::Parse() {

}


const std::string::iterator Parse::findKeyPos(const std::string& key) {
	
}


const std::string Parse::findKeyValue(const std::string& key) {

}




#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <gtest/gtest.h>


#include "BtParse.h"


int main() {
	std::string filename = "./bt.bittorrent";
	ParseMetaFile metafile(ParseMetaFile::readMetafileToString(filename));
}

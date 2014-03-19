#pragma once

#include <fstream>
#include <iostream>
#include "DataBlock.h"

DataBlock ReadFile(const char* filename)
{
	std::ifstream myfile = std::ifstream(filename, std::ios::in | std::ios::binary | std::ios::ate);
	if (!myfile)
		return DataBlock();
	unsigned int size = (unsigned int)myfile.tellg();
	myfile.seekg(0, std::ios::beg);
	unsigned char* data = new unsigned char[size];
	myfile.read((char*)data, size);
	myfile.close();
	return DataBlock(data, size);
}
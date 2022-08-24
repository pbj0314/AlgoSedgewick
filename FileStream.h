#pragma once
#include <iostream>
#include <string>
#include <fstream>
class FileStream
{
private:
	std::ifstream stream;
public:
	FileStream(std::string fileName);
	bool hasNext();
	int readInt();
};


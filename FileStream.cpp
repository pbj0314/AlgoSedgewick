#include "FileStream.h"

FileStream::FileStream(std::string fileName)
{
	stream.open(fileName);

	if (!stream.is_open())
	{
		std::cerr << "can't open file" << std::endl;
		exit(EXIT_FAILURE);
	}
}

bool FileStream::hasNext()
{
	while (stream.peek() != EOF)
	{
		char c = stream.peek();
		if (c == '\n' || c == ' ')
		{
			stream.get();
			continue;
		}
		return true;
	}
	return false;
}

int FileStream::readInt()
{
	char c;
	std::string str;

	while (stream.peek()!= EOF)
	{
		c = stream.get();
		if (c == '\n' || c == ' ')
		{
			continue;
		}
		str.push_back(c);
		break;
	}

	while (stream.peek() != EOF)
	{
		c = stream.get();
		if (c == '\n' || c == ' ')
		{
			break;
		}
		str.push_back(c);
	}

	return std::stoi(str);
}

#pragma once
#include <string>
#include <vector>
#include <forward_list>

#include "FileStream.h"

class Digraph
{
private:
	std::vector<std::forward_list<int>> data;
public:
	int V;
public:
	Digraph(std::string fileName);
	void addEdge(int from, int to);
	std::forward_list<int>* getNeighbor(int v);
	void showAll();
};


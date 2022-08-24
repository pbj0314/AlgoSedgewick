#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>

#include "FileStream.h"

class Graph
{
public:
	int V;
	int E;
private:
	std::vector<std::forward_list<int>> data;
public:
	Graph(std::string fileName);

	void addEdge(int v, int w);
	std::forward_list<int>* getNeighbor(int v);
	void showAll();
};


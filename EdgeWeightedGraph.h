#pragma once
#include <string>
#include <vector>
#include <forward_list>
#include "Edge.h"

class EdgeWeightedGraph
{
private:
	std::vector<std::forward_list<Edge>> data;
public:
	int V;
	int E;
public:
	EdgeWeightedGraph(std::string fileName);
	void addEdge(Edge e);
	std::forward_list<Edge>* getNeightbor(int v);
	void showAll();
};


#pragma once
#include <queue>
#include <vector>

#include "Graph.h"
#include "Digraph.h"
class BreadthFirstSearch
{
private:
	std::vector<bool> marker;
	std::vector<int> path;
public:
	void findPath(Graph& g, int src, int dst);
private:
	void search(Graph& g, int s);
};


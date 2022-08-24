#pragma once
#include "Graph.h"
#include <vector>
#include <stack>

#include "Digraph.h"

class DepthFirstSearch
{
private:
	std::vector<bool> marker;
	std::vector<int> path;
public:
	DepthFirstSearch();
	void findPath(Graph& g, int src, int dst);
private:
	void search(Graph& g, int s);
	void recursive(Graph& g, int s);

};


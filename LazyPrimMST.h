#pragma once
#include <vector>
#include <queue>
#include "EdgeWeightedGraph.h"

class LazyPrimMST
{
private:
	std::vector<bool> marker;
	std::vector<Edge> mst;
public:
	LazyPrimMST(EdgeWeightedGraph& g);
};


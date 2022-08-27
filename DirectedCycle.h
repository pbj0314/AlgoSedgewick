#pragma once

#include <vector>
#include <stack>

#include "Digraph.h"

class DirectedCycle
{
private:
	std::vector<bool> marker;
	std::vector<bool> route;
	std::vector<int> trail;
	std::vector<std::stack<int>> cycles;


public:
	DirectedCycle(Digraph& dg);
	void showCycles();
	bool hasCycle();
private:
	void dfs(Digraph& dg, int v);
	void recursive(Digraph& dg, int v);
};

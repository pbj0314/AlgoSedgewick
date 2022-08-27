#pragma once
#include <stack>
#include <queue>
#include <vector>

#include "Digraph.h"

class DepthFirstOrder
{
private:
	std::vector<bool> marker;

	std::queue<int> pre;
	std::queue<int> post;
	std::stack<int> revPost;

public:
	DepthFirstOrder(Digraph& dg);
	void preOrder();
	void postOrder();
	void revPostOrder();
private:
	void dfs(Digraph& dg, int v);
};


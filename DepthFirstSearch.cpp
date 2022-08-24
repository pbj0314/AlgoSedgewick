#include "DepthFirstSearch.h"

DepthFirstSearch::DepthFirstSearch()
{

}

void DepthFirstSearch::search(Graph& g, int s)
{
	marker.clear();
	marker.resize(g.V);
	path.clear();
	path.resize(g.V);

	recursive(g, s);
}

void DepthFirstSearch::findPath(Graph& g, int src, int dst)
{
	search(g, src);

	if (!marker[dst])
	{
		std::cout << "No Path" << std::endl;
		return;
	}

	std::stack<int> st;
	int curr = dst;
	st.push(curr);
	while (curr != src)
	{
		curr = path[curr];
		st.push(curr);
	}

	while (!st.empty())
	{
		std::cout << st.top() << " ";
		st.pop();
	}
}

void DepthFirstSearch::recursive(Graph& g, int s)
{
	marker[s] = true;
	//std::cout << s << " ";
	for (int v : *g.getNeighbor(s))
	{
		if (!marker[v])
		{
			path[v] = s;
			recursive(g, v);
		}
	}
}

//int main(void)
//{
//	Graph g("algs4-data\\tinyG.txt");
//	DepthFirstSearch dfs;
//	dfs.findPath(g, 10, 12);
//}
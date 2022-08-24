#include "BreadthFirstSearch.h"

#include <stack>

void BreadthFirstSearch::findPath(Graph& g, int src, int dst)
{
	marker.resize(g.V);
	path.resize(g.V);

	search(g, src);
	
	if (!marker[dst])
	{
		std::cout << "can't find path" << std::endl;
		return;
	}

	std::stack<int> st;
	int i = dst;
	st.push(i);
	while (i != src)
	{
		i = path[i];
		st.push(i);
	}

	while (!st.empty())
	{
		std::cout << st.top() << " ";
		st.pop();
	}
}

void BreadthFirstSearch::search(Graph& g, int s)
{
	
	std::queue<int> q;
	q.push(s);
	marker[s] = true;
	while (!q.empty())
	{
		s = q.front();
		q.pop();

		//std::cout << s << " ";
		for (int v : *g.getNeighbor(s))
		{
			if (!marker[v])
			{
				q.push(v);
				marker[v] = true;
				path[v] = s;
			}
		}
	}
}


int main(void)
{
	Graph g("..\\algs4-data\\tinyG.txt");
	BreadthFirstSearch bfs;
	bfs.findPath(g, 11, 10);
}
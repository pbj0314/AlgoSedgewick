#include "DirectedCycle.h"

DirectedCycle::DirectedCycle(Digraph& dg)
{
	int vertexCount = dg.V;
	marker.resize(vertexCount);
	route.resize(vertexCount);
	trail.resize(vertexCount);

	for (int i = 0; i < vertexCount; i++)
	{
		if (!marker[i])
		{
			dfs(dg, i);
		}
	}
}

void DirectedCycle::showCycles()
{
	for (int i = 0; i < cycles.size(); i++)
	{
		std::stack<int> st = cycles[i];
		std::cout << "new cycle" << std::endl;
		while (!st.empty())
		{
			std::cout << st.top() << " ";
			st.pop();
		}
		std::cout << std::endl;
	}
}

bool DirectedCycle::hasCycle()
{
	if (!cycles.empty())
	{
		return true;
	}
	return false;
}

void DirectedCycle::dfs(Digraph& dg, int v)
{
	recursive(dg, v);
}

void DirectedCycle::recursive(Digraph& dg, int v)
{
	marker[v] = true;
	route[v] = true;

	std::cout << v << std::endl;

	for (int w : *dg.getNeighbor(v))
	{
		if (!marker[w])
		{
			trail[w] = v;
			recursive(dg, w);
		}
		else
		{
			if (route[w]) // && w != trail[v] 맞순환 방지용 코드
			{
				int curr = v;
				std::stack<int> st;
				st.push(curr);
				while (curr != w)
				{
					curr = trail[curr];
					st.push(curr);
				}
				cycles.push_back(st);
			}
		}
	}

	route[v] = false;
	std::cout << v << std::endl;
}

//int main(void)
//{
//	Digraph dg("..\\algs4-data\\tinyDG.txt");
//	DirectedCycle dc(dg);
//	dc.showCycles();
//}

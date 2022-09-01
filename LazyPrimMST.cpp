#include "LazyPrimMST.h"
#include <iostream>
LazyPrimMST::LazyPrimMST(EdgeWeightedGraph& g)
{
	int vSize = g.V;
	marker.resize(vSize);

	if (vSize == 0)
	{
		std::cerr << "don't have vertex" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::priority_queue<Edge> pq;
}

int main(void)
{
	std::priority_queue<Edge> pq;
	Edge e1(1, 1, 0.4f);
	Edge e2(1, 1, 0.1f);
	Edge e3(1, 1, 0.5f);
	Edge e4(1, 1, 0.8f);
	Edge e5(1, 1, 0.3f);

	pq.push(e1);
	pq.push(e2);
	pq.push(e3);
	pq.push(e4);
	pq.push(e5);


	while (!pq.empty())
	{
		Edge te = pq.top();
		pq.pop();
		std::cout << te.getWeight() << std::endl;
	}
}
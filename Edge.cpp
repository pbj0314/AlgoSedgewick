#include "Edge.h"
#include <algorithm>
#include <vector>
#include <iostream>
Edge::Edge(int v, int w, float weight)
{
	this->v = v;
	this->w = w;
	this->weight = weight;
}

int Edge::either()
{
	return v;
}

int Edge::other(int u)
{
	if (u == v)
	{
		return w;
	}
	return v;
}

float Edge::getWeight()
{
	return weight;
}

bool Edge::operator<(const Edge& operand)
{
	if (this->weight < operand.weight)
	{
		return true;
	}
	return false;
}

//int main(void)
//{
//	Edge e1(0, 1, 4);
//	Edge e2(0, 1, 1);
//	Edge e3(0, 1, 10);
//	std::vector<Edge> v{e1, e2, e3};
//	std::sort(v.begin(), v.end());
//	for (auto e : v)
//	{
//		std::cout << e.getWeight() << " ";
//	}
//}
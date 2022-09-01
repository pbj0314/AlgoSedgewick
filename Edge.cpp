#include "Edge.h"

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

bool Edge::operator==(Edge& e)
{
	float anotherWeight = e.getWeight();
	if (weight == anotherWeight)
	{
		return true;
	}
	return false;
}

bool Edge::operator<(Edge& e)
{
	float anotherWeight = e.getWeight();
	if (weight < anotherWeight)
	{
		return true;
	}
	return false;
}

bool Edge::operator>(Edge& e)
{
	float anotherWeight = e.getWeight();
	if (weight > anotherWeight)
	{
		return true;
	}
	return false;
}

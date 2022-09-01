#pragma once
class Edge
{
private:
	int v;
	int w;
	float weight;

public:
	Edge(int v, int w, float weight);
	int either();
	int other(int v);
	float getWeight();
	bool operator==(Edge& e);
	bool operator<(Edge& e);
	bool operator>(Edge& e);
};


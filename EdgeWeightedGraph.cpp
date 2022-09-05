#include "EdgeWeightedGraph.h"
#include "FileStream.h"
#include <algorithm>
EdgeWeightedGraph::EdgeWeightedGraph(std::string fileName)
{
	FileStream fs(fileName);
	
	if (fs.hasNext())
	{
		V = fs.readInt();
		data.resize(V);
	}

	if (fs.hasNext())
	{
		E = fs.readInt();
	}

	while (fs.hasNext())
	{
		int v = fs.readInt();
		int w = fs.readInt();
		float weight = fs.readFloat();
		Edge e(v, w, weight);
		addEdge(e);
	}
}

void EdgeWeightedGraph::addEdge(Edge e)
{
	int v = e.either();
	int w = e.other(v);
	data[v].push_front(e);
	data[w].push_front(e);
}

std::forward_list<Edge>* EdgeWeightedGraph::getAdjEdge(int v)
{
	return &data[v];
}

void EdgeWeightedGraph::showAll()
{
	for (int v = 0; v < data.size(); v++)
	{
		for (Edge& e : data[v])
		{
			int w = e.other(v);
			std::cout << v << "-" << w << " " << e.getWeight();
			std::cout << std::endl;
		}
	}
}

void EdgeWeightedGraph::showNeighbor(int v)
{
	std::vector<Edge> vec;
	for (auto& e : data[v])
	{
		vec.push_back(e);
	}
	std::sort(vec.begin(),vec.end());
	for (auto& e : vec)
	{
		int w = e.other(v);
		std::cout << v << "-" << w << " " << e.getWeight() << std::endl;
	}
}

int main(void)
{
	//EdgeWeightedGraph ewg("..\\algs4-data\\tinyEWG.txt");
	////ewg.showAll();
	//for (int i = 0; i < ewg.V; i++)
	//{
	//	ewg.showNeighbor(i);
	//	std::cout << std::endl;
	//}
	
}
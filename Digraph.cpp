#include "Digraph.h"

Digraph::Digraph(std::string fileName)
{
	FileStream fs(fileName);

	if (fs.hasNext())
	{
		V = fs.readInt();
		data.resize(V);
	}

	if (fs.hasNext())
	{
		fs.readInt();
	}

	while (fs.hasNext())
	{
		int v = fs.readInt();
		int w = fs.readInt();
		addEdge(v, w);
	}
}

void Digraph::addEdge(int from, int to)
{
	data[from].push_front(to);
}

std::forward_list<int>* Digraph::getNeighbor(int v)
{
	return &data[v];
}

void Digraph::showAll()
{
	for (int v = 0; v < data.size(); v++)
	{
		for (int w : data[v])
		{
			std::cout << v << " - " << w << std::endl;
		}
	}
}

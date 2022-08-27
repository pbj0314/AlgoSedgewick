#include "DepthFirstOrder.h"

DepthFirstOrder::DepthFirstOrder(Digraph& dg)
{
	int vertexCount = dg.V;
	marker.resize(vertexCount);

	for (int i = 0; i < vertexCount; i++)
	{
		if (!marker[i])
		{
			dfs(dg, i);
		}
	}

 	for (int i = 0; i < vertexCount; i++)
	{
		if (!marker[i])
		{
			dfs(dg, i);
		}
	}
}

void DepthFirstOrder::preOrder()
{
	std::cout << "PreOrder" << std::endl;
	while (!pre.empty())
	{
		std::cout << pre.front() << " ";
		pre.pop();
	}
	std::cout << std::endl;
}

void DepthFirstOrder::postOrder()
{
	std::cout << "PostOrder" << std::endl;
	while (!post.empty())
	{
		std::cout << post.front() << " ";
		post.pop();
	}
	std::cout << std::endl;
}

void DepthFirstOrder::revPostOrder()
{
	std::cout << "ReversePostOrder" << std::endl;
	while (!revPost.empty())
	{
		std::cout << revPost.top() << " ";
		revPost.pop();
	}
	std::cout << std::endl;
}

void DepthFirstOrder::dfs(Digraph& dg, int v)
{
	pre.push(v);

	marker[v] = true;
	for (int w : *dg.getNeighbor(v))
	{
		if (!marker[w])
		{
			dfs(dg, w);
		}
	}

	post.push(v);
	revPost.push(v);
}

int main(void)
{
	Digraph dg("..\\algs4-data\\tinyDAG.txt");
	DepthFirstOrder dfo(dg);
	dfo.preOrder();
	dfo.postOrder();
	dfo.revPostOrder();
}
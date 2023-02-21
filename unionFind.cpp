#include "unionFind.h"

int findParent(int a, unordered_map<int, int> &parent)
{
	if (parent[a] == a)
		return a;
	int root = findParent(parent[a], parent);
	parent[a] = root;
	return root;
}

void unionSets(int a, int b, unordered_map<int, int> &parent, unordered_map<int, int> &rank)
{
	int rootA = findParent(a, parent), rootB = findParent(b, parent);
	if (rootA == rootB)
		return;
	int rankA = rank[rootA], rankB = rank[rootB];
	if(rankA <= rankB)
	{
		rank[rootB] += rankA;
		parent[rootA] = rootB;
		rank.erase(rootA);
	}
	else
	{
		rank[rootA] += rankB;
		parent[rootB] = rootA;
		rank.erase(rootB);
	}
}
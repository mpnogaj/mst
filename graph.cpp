#include "graph.h"
#include "unionFind.h"
#include <queue>
#include <unordered_map>

Graph::Graph()
{
	this->mEdges = vector<edge>();
}

Graph::~Graph()
{
	mEdges.clear();
}

void Graph::AddEdge(int a, int b, double w)
{
	this->mEdges.push_back({w, {a, b}});
}

Graph Graph::CreateMST()
{
	Graph mst = Graph();
	auto pq = priority_queue<edge, vector<edge>, greater<edge>>(this->mEdges.begin(), this->mEdges.end());
	auto parent = unordered_map<int, int>();
	auto rank = unordered_map<int, int>();
	for (const auto &e : this->mEdges)
	{
		int a = e.second.first, b = e.second.second;
		parent[a] = a;
		parent[b] = b;
		rank[a] = 1;
		rank[b] = 1;
	}

	int n = parent.size();
	for (int i = 0; i < n - 1; )
	{
		edge e = pq.top();
		pq.pop();
		int a = e.second.first, b = e.second.second;
		if(findParent(a, parent) == findParent(b, parent))
			continue;
		mst.AddEdge(a, b, e.first);
		unionSets(a, b, parent, rank);
		i++;
	}

	return mst;
}

void Graph::PrintGraph(ostream &outputStream)
{
	bool fr = false;
	for (const auto &e : this->mEdges)
	{
		if (fr)
			outputStream << ", ";
		outputStream << "(" << e.second.first << ", " << e.second.second << ", " << e.first << ")";
		fr = true;
	}
	outputStream << endl;
}
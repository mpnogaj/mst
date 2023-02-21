#include <vector>
#include <utility>
#include <ostream>
#pragma once

using namespace std;

/// @brief Typ krawedzi
typedef pair<double, pair<int, int>> edge;

/// @brief Klasa przechowujaca graf
class Graph
{
private:
	vector<edge> mEdges; 

public:
	Graph();
	~Graph();

	/**
	 * @brief Funkcja dodajaca krawedz pomiedzy dwoma wierzcholkami 
	 * 
	 * @param a pierwszy wierzcholek
	 * @param b drugi wierzcholek
	 */
	void AddEdge(int a, int b, double w);

	/**
	 * @brief Tworzy MST z grafu
	 * 
	 * @return Graph MST
	 */
	Graph CreateMST();

	/**
	 * @brief Wypisz graf na strumien wyjsciowy
	 * 
	 * @param outputStream strumien wyjsciowy na ktory nalezy wypisac graf
	 */
	void PrintGraph(ostream& outputStream);
};
/** @file unionFind.h
 * Plik pomocniczy zawierajacy implementacje niektorych funkcji na zbiorach rozlacznych
 */

#include <unordered_map>
#pragma once

using namespace std;

/**
 * @brief Szuka reprezentanta zbioru do ktorego nalezy a
 * 
 * @param a 
 * @param parent tablica reprezentantow
 * @return int reprezentant
 */
int findParent(int a, unordered_map<int, int> &parent);

/**
 * @brief Laczy dwa zbiory do ktorych naleza a i b
 * 
 * @param a 
 * @param b 
 * @param parent tablica reprezentantow
 * @param rank tablica rang zbiorow
 */
void unionSets(int a, int b, unordered_map<int, int> &parent, unordered_map<int, int> &rank);

#pragma once

//Aby korzystaæ z funkcji bsearch nale¿y za³¹czyæ plik nag³ówkowy stdlib.h
#include <stdlib.h>
#include <stdio.h> 
#include <iostream>

using namespace std;

/// <summary>
///	funkcja bsearch wyszukuje dany klucz w tablicy
/// </summary>
static class Bsearch
{
public:
	/// <summary>
	/// Przedstawia dzia³anie funkcji bsearch
	/// </summary>
	static void Start()
	{
		int tab[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17 };
		int szukanyElement = 0;

		cout << "W tablicy znajduj¹ siê liczby: ";

		for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
		{
			cout << tab[i] << ", ";
		}

		cout << "Wpisz jak¹ wartoœæ chcesz znaleŸæ: ";
		cin >> szukanyElement;

		int * element;
		qsort(tab, 6, sizeof(int), compareints);
		element = (int*)bsearch(&szukanyElement, tab, sizeof(tab) / sizeof(tab[0]), sizeof(int), compareints);
		if (element != NULL)
			std::cout << szukanyElement << " znajduje siê w tablicy";
		else
			std::cout << szukanyElement << " nie znajduje siê w tablicy";
	}

private:
	/// <summary>
	/// WskaŸnik do funkcji, która porównuje 2 elementy
	/// </summary>
	static int compareints(const void * a, const void * b)
	{
		return (*(int*)a - *(int*)b);
	}
};


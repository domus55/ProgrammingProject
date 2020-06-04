#pragma once

//Aby korzysta� z funkcji bsearch nale�y za��czy� plik nag��wkowy stdlib.h
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
	/// Przedstawia dzia�anie funkcji bsearch
	/// </summary>
	static void Start()
	{
		int tab[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17 };
		int szukanyElement = 0;

		cout << "W tablicy znajduj� si� liczby: ";

		for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
		{
			cout << tab[i] << ", ";
		}

		cout << "Wpisz jak� warto�� chcesz znale��: ";
		cin >> szukanyElement;

		int * element;
		qsort(tab, 6, sizeof(int), compareints);
		element = (int*)bsearch(&szukanyElement, tab, sizeof(tab) / sizeof(tab[0]), sizeof(int), compareints);
		if (element != NULL)
			std::cout << szukanyElement << " znajduje si� w tablicy";
		else
			std::cout << szukanyElement << " nie znajduje si� w tablicy";
	}

private:
	/// <summary>
	/// Wska�nik do funkcji, kt�ra por�wnuje 2 elementy
	/// </summary>
	static int compareints(const void * a, const void * b)
	{
		return (*(int*)a - *(int*)b);
	}
};


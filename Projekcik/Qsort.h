#pragma once

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <time.h>

using namespace std;

/// <summary>
/// Funkcja qsort sortuje podan¹ tablice korzystaj¹c z algorytmu szybkiego sortowanie(quick sort)
/// </summary>
static class Qsort
{
public:
	static const int rozmiarTablicy = 200;

	/// <summary>
	/// Przedstawia dzia³anie funkcji qsort
	/// </summary>
	static void Start()
	{
		srand(time(0));
		int tab[rozmiarTablicy];
		for (int i = 0; i < rozmiarTablicy; i++)
		{
			tab[i] = rand() % 100;
		}

		cout << "-------------------------------------------------------------" << endl;
		cout << "tablica przed posortowaniem" << endl;

		ShowArray(tab);
		posortuj(tab, sizeof(tab) / sizeof(int), sortujRosnaco);

		cout << "-------------------------------------------------------------" << endl;
		cout << "tablica po posortowaniu" << endl;

		ShowArray(tab);
	}

private:

	static void posortuj(int * tablica, int ilosc, int(*funkcjaSortujaca)(const int *, const int *))
	{
		qsort(tablica, ilosc, sizeof(*tablica), (int(*)(const void *, const void *)) funkcjaSortujaca);
	}

	static int * CreateArray()
	{
		int * tab = new int[rozmiarTablicy];
		srand(time(NULL));

		for (int i = 0; i < 1000; i++)
		{
			tab[i] = rand() % 1000;
		}

		return tab;
	}

	static void ShowArray(int * tab)
	{
		for (int i = 0; i < rozmiarTablicy; i++)
		{
			cout << i << ". " << tab[i] << endl;
		}
	}

	static int sortujRosnaco(const int * arg1, const int * arg2)
	{
		if (*arg1 < *arg2)
			return -1;

		if (*arg1 > * arg2)
			return 1;

		return 0;
	}

	static int sortujMalejaco(const int * arg1, const int * arg2)
	{
		if (*arg1 > * arg2)
			return -1;

		if (*arg1 < *arg2)
			return 1;

		return 0;
	}
};


#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class typDanych>
class Sortuj
{
public:
	static void Start(int ilosc)
	{
		srand(time(0));
		typDanych tablica[100];
		for (int i = 0; i < ilosc; i++)
		{
			cin >> tablica[i];
		}

		posortuj(tablica, ilosc, sortujRosnaco);

		cout << endl << "---------------------------------------------------------" << endl;
		cout << "Posortowane elementy" << endl;
		wyswietl(tablica, ilosc);
	}

private:
	static int sortujRosnaco(const typDanych * arg1, const typDanych * arg2)
	{
		if (*arg1 < *arg2)
			return -1;

		if (*arg1 > * arg2)
			return 1;

		return 0;
	}

	static int sortujMalejaco(const typDanych * arg1, const typDanych * arg2)
	{
		if (*arg1 > * arg2)
			return -1;

		if (*arg1 < *arg2)
			return 1;

		return 0;
	}

	static void posortuj(typDanych * tablica, int ilosc, int(*funkcjaSortujaca)(const typDanych *, const typDanych *))
	{
		qsort(tablica, ilosc, sizeof(*tablica), (int(*)(const void *, const void *)) funkcjaSortujaca);
	}

	static void wyswietl(typDanych * tablica, int ilosc)
	{
		for (int i = 0; i < ilosc; i++)
			cout << tablica[i] << endl;

		cout << endl;
	}
};



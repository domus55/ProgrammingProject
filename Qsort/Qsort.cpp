#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <string>
#include "Sortuj.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");  //funkcja umożliwia korzystanie z polskich znaków
	cout << "Jaki parametr chcesz użyć: " << endl <<
		"brak - sortowanie liczb całkowitych" << endl <<
		"-n - sortowanie liczb zmiennoprzecinkowych" << endl <<
		"-s - sortowanie tekstu" << endl;

	string wybor = "";
	int ilosc = 0;

	cin >> wybor;

	std::transform(wybor.begin(), wybor.end(), wybor.begin(),	//zamiana wszystkich liter na małe
		[](unsigned char c) { return std::tolower(c); });

	cout << "Podaj ilość elementów do posortowania(maksymalnie 100): ";
	cin >> ilosc;
	if (ilosc > 100 || ilosc < 1) return 0;


	if (wybor == "-n" || wybor == "n")
	{
		Sortuj<float> s;
		s.Start(ilosc);
	}
	else if (wybor == "-s" || wybor == "s")
	{
		Sortuj<string> s;
		s.Start(ilosc);
	}
	else
	{
		Sortuj<int> s;
		s.Start(ilosc);
	}
}

#pragma once

//Aby korzystaæ z funkcji atexit nale¿y za³¹czyæ plik nag³ówkowy iostream
#include <iostream>

using namespace std;
/// <summary>
///		Funkcja atexit wywo³uje funkcjê, b¹dŸ metodê po zakoñczeniu programu, w odwrotnej kolejnoœci ni¿ owe funkcje zosta³y wywo³ane,
///		czyli je¿eli tak jak w przyk³adzie poni¿ej wywo³amy atexit(funkcja1), atexit(funkcja2), to po zakoñczeniu programu wywo³aj¹
///		siê funkcja2, a nastêpnie funkcja1, ca³oœæ jest zaprezentowana w programie poni¿ej
/// </summary>
static class Atexit
{
public:

	/// <summary>
	/// Przedstawienie dzia³ania funkcji atexit();
	/// </summary>
	static void Start()
	{
		atexit(funkcja1);
		atexit(funkcja2);
		std::cout << "Koniec metody Start w klasie Atexit" << endl;

		/*
		Po uruchomieniu program powinien wypisaæ:
		Koniec programu
		funkcja2
		funkcja1
		*/
	}

private:
	static void funkcja1()
	{
		std::cout << "funkcja1" << endl;
	}

	static void funkcja2()
	{
		std::cout << "funkcja2" << endl;
	}
};


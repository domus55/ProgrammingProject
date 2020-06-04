#pragma once

//Aby korzystaæ z funkcji at_quick_exit nale¿y za³¹czyæ plik nag³ówkowy iostream
#include <iostream>

using namespace std;

/// <summary>
///		Funkcja at_quick_exit wywo³uje funkcje, b¹dŸ metodê po uruchomieniu funkcji std::quick_exit, w odwrotnej kolejnoœci
///		ni¿ owe funkcje zosta³y wywo³ane, czyli je¿eli tak jak w przyk³adzie poni¿ej wywo³amy at_quick_exit(funkcja1), at_quick_exit(funkcja2),
///		to po zakoñczeniu programu wywo³aj¹ siê funkcja2, a nastêpnie funkcja1, ca³oœæ jest zaprezentowana w programie poni¿ej
/// </summary>
static class At_quick_exit
{
public:
	/// <summary>
	/// Przedstawienie dzia³ania funkcji at_quick_exit()
	/// w przypadku gdy nie wywo³amy funkcji std::quick_exit()
	/// </summary>
	static void Start()
	{
		at_quick_exit(funkcja1);
		at_quick_exit(funkcja2);
		std::cout << "Koniec metody Start w klasie At_quick_exit" << endl;

		/*
		Po uruchomieniu program powinien wypisaæ:
		Koniec programu
		dzieje siê tak poniewa¿ nie u¿yliœmy funkcji quick_exit()
		*/
	}

	/// <summary>
	/// Przedstawienie dzia³ania funkcji at_quick_exit()
	/// w przypadku gdy nie wywo³amy funkcji std::quick_exit()
	/// </summary>
	static void StartAndQuickExit()
	{
		at_quick_exit(funkcja1);
		at_quick_exit(funkcja2);
		std::cout << "Koniec metody Start w klasie At_quick_exit" << endl;

		quick_exit(0);

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


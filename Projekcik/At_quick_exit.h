#pragma once

//Aby korzysta� z funkcji at_quick_exit nale�y za��czy� plik nag��wkowy iostream
#include <iostream>

using namespace std;

/// <summary>
///		Funkcja at_quick_exit wywo�uje funkcje, b�d� metod� po uruchomieniu funkcji std::quick_exit, w odwrotnej kolejno�ci
///		ni� owe funkcje zosta�y wywo�ane, czyli je�eli tak jak w przyk�adzie poni�ej wywo�amy at_quick_exit(funkcja1), at_quick_exit(funkcja2),
///		to po zako�czeniu programu wywo�aj� si� funkcja2, a nast�pnie funkcja1, ca�o�� jest zaprezentowana w programie poni�ej
/// </summary>
static class At_quick_exit
{
public:
	/// <summary>
	/// Przedstawienie dzia�ania funkcji at_quick_exit()
	/// w przypadku gdy nie wywo�amy funkcji std::quick_exit()
	/// </summary>
	static void Start()
	{
		at_quick_exit(funkcja1);
		at_quick_exit(funkcja2);
		std::cout << "Koniec metody Start w klasie At_quick_exit" << endl;

		/*
		Po uruchomieniu program powinien wypisa�:
		Koniec programu
		dzieje si� tak poniewa� nie u�yli�my funkcji quick_exit()
		*/
	}

	/// <summary>
	/// Przedstawienie dzia�ania funkcji at_quick_exit()
	/// w przypadku gdy nie wywo�amy funkcji std::quick_exit()
	/// </summary>
	static void StartAndQuickExit()
	{
		at_quick_exit(funkcja1);
		at_quick_exit(funkcja2);
		std::cout << "Koniec metody Start w klasie At_quick_exit" << endl;

		quick_exit(0);

		/*
		Po uruchomieniu program powinien wypisa�:
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


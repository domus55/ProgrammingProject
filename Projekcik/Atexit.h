#pragma once

//Aby korzysta� z funkcji atexit nale�y za��czy� plik nag��wkowy iostream
#include <iostream>

using namespace std;
/// <summary>
///		Funkcja atexit wywo�uje funkcj�, b�d� metod� po zako�czeniu programu, w odwrotnej kolejno�ci ni� owe funkcje zosta�y wywo�ane,
///		czyli je�eli tak jak w przyk�adzie poni�ej wywo�amy atexit(funkcja1), atexit(funkcja2), to po zako�czeniu programu wywo�aj�
///		si� funkcja2, a nast�pnie funkcja1, ca�o�� jest zaprezentowana w programie poni�ej
/// </summary>
static class Atexit
{
public:

	/// <summary>
	/// Przedstawienie dzia�ania funkcji atexit();
	/// </summary>
	static void Start()
	{
		atexit(funkcja1);
		atexit(funkcja2);
		std::cout << "Koniec metody Start w klasie Atexit" << endl;

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


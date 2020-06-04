#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Atexit.h"
#include "At_quick_exit.h"
#include "Qsort.h"
#include "Bsearch.h"
#include "Set_constraint_handler_s.h"

using namespace std;

int WybierzFunkcje()
{
	cout << "Którą z funkcji chcesz sprawdzić:" << endl <<
		"1. atexit" << endl <<
		"2. at_quick_exit w przypadku gdy nie użyjemy funkcji quick_exit" << endl <<
		"3. at_quick_exit w przypadku gdy użyjemy funkcji quick_exit" << endl <<
		"4. qsort z wprowadzonymi wcześniej danymi" << endl <<
		"5. qsort z danymi wprowadzonymi przez użytkownika" << endl <<
		"6. bsearch" << endl <<
		"7. set_constraint_handler_s" << endl;

	char wybor = 'd';
	wybor = _getch();
	int intWybor = wybor - '0';	//zamiana char na int


	return intWybor;
}

int main()
{
	setlocale(LC_ALL, "");  //funkcja umożliwia korzystanie z polskich znaków

	int wybor = 0;
	
	do
	{
		wybor = WybierzFunkcje();
		
		system("cls");
		if(wybor < 1 || wybor > 6) cout << "Wybrano niepoprawną opcje, musisz wybrać numer z zakresu 1 - 3";

	} while (wybor < 1 || wybor > 6);

	switch(wybor)
	{
		case 1: Atexit::Start(); break;
		case 2: At_quick_exit::Start(); break;
		case 3: At_quick_exit::StartAndQuickExit(); break;
		case 4: Qsort::Start(); break;
		case 5: cout << "Fukncja qsort, z możliwością wpisania danych przez użytkownika znajduje się w projekcie qsort"; break;
		case 6: Bsearch::Start(); break;
		case 7: Set_constraint_handler_s::Start(); break;
	}
	
	

	return 0;
}
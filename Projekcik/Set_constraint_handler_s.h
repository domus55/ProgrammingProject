#pragma once
//Niezb�dne jest zdefiniowanie __STDC_WANT_LIB_EXT1__ do sta�ej ca�kowitej 1, aby funkcja set_constraint_handler_s mog�a dzia�a�
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

static class Set_constraint_handler_s
{
public:
	static void Start()
	{
		//Niezb�dne jest zdefiniowanie __STDC_LIB_EXT1__, aby funkcja set_constraint_handler_s mog�a dzia�a�
		#ifdef __STDC_LIB_EXT1__
			char dst[2];
			set_constraint_handler_s(ignore_handler_s);
			int r = strcpy_s(dst, sizeof dst, "Za d�ugi!");
			printf("dst = \"%s\", r = %d\n", dst, r);
			set_constraint_handler_s(abort_handler_s);
			r = strcpy_s(dst, sizeof dst, "Za d�ugi!");
			printf("dst = \"%s\", r = %d\n", dst, r);
		#endif
	}
};


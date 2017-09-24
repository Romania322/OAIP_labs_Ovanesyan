// Duim c++.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include "stdafx.h"
#include <iostream>
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	double a, mm, metr, arsh;
	scanf("%f" &a);
	if (a > 0) {
		mm = a * 25.4;//перевели дюймы в миллиметры
		metr = mm / 1000;//перевели дюймы>мм>метр
		arsh = (metr * 100) / 71.1;//перевели метры в см, а см в аршины
		printf("%f metr -метров");
		printf("%f arsh -аршин");
	}
	else
	{
		printf("Нет решений");
	}
	system("pause");
	return 0;




}


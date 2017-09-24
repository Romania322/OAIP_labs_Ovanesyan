// Duim c++.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include "stdafx.h"
#include <iostream>



int _tmain(int argc, _TCHAR* argv[])
{
	system("chcp 1251");
	system("cls");
	float a = 0, mm, metr, arsh;
	scanf_s("%e", &a);
	if (a > 0) {
		mm = a * 25.4;//перевели дюймы в миллиметры
		metr = mm / 1000;//перевели дюймы>мм>метр
		arsh = (metr * 100) / 71.1;//перевели метры в см, а см в аршины
		printf("%f дюймов-это %f метров \n", a, metr );
		printf("%f дюймов-это %f аршин \n" ,a,arsh );
	}
	else
	{
		printf("Нет решений");
	}
	system("pause");
	return 0;




}


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
		mm = a * 25.4;//�������� ����� � ����������
		metr = mm / 1000;//�������� �����>��>����
		arsh = (metr * 100) / 71.1;//�������� ����� � ��, � �� � ������
		printf("%f metr -������");
		printf("%f arsh -�����");
	}
	else
	{
		printf("��� �������");
	}
	system("pause");
	return 0;




}


#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

int main()
{
	system("chcp 1251");
	system("cls");

	float a = 0, rez, mm, metr, arsh;

	printf("Введите количество дюймов:");
	do {
		rez = scanf("%f", &a);
		if (!rez) {
			printf("Повторите попытку ввода: ");
			while (getchar() != '\n');
		}
	} while (rez != 1);

	mm = a * 25.4;
	metr = mm / 1000;
	arsh = (metr * 100) / 71.1;

	printf("%f Метров \n", metr);
	printf("%f Дюймов \n", arsh);

	system("pause");
	return 0;

}

/*
Ованесян Даниил Арменович КТБО 1-8
Лабораторная №2 вариант 4
Найти сумму всех положительных элементов массива
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <conio.h> 

#define ARRAY_SIZE 100

int enterArray(void);
int enterSum(void);

int mainArray[100];
int main()
{
	int sum = 0, size, userLength;
	printf("Enter nomber of the size:");
	userLength = enterArray();
	int array[ARRAY_SIZE];

	for (int i = 0; i < userLength; i++) {
		printf("Enter element:");
		mainArray[i] = enterArray();
	}
	size = enterSum();

	printf("%d", size);
	_getch();
	return 0;
}

int enterArray(void) 
{
	int number;
	scanf("%d", &number);

	if (getchar() != '\n') 
	{
		printf("Error number. Try again:");
		while (getchar() != '\n');
		number = enterArray();
	}

	return number;
}
int enterSum(void)
{

	int sum = 0;
	for (int i = 0; i < 100; i++)
	{
		if(mainArray[i] > 0)
		{
			sum = sum + mainArray[i];
		}
		
	}
	return sum;
}

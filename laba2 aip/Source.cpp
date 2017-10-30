#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h> 

int main()
{
	int sum = 0, size, count2, count1,check, cheksize;
	cheksize = scanf("%d", &size);
	while (!cheksize)
	{
		printf("Ошибка ввода. Повторите попытку:");
		while (getchar() != '\n');
		cheksize = scanf("%d", &size);
	}

	while (getchar() != '\n');

	int array[100];
	for (count1 = 0; count1<size; count1++)
	{
		check = scanf("%d", &array[count1]);
		while (!check) 
		{
			printf("Ошибка ввода. Повторите попытку:");
			while (getchar() != '\n');
			check = scanf("%d", &array[count1]);
		}
		

	}

	while (getchar() != '\n');

	for (count2 = 0; count2<size; count2++)
	{
		if (array[count2]>0)
		{
			sum = sum + array[count2];
		}
	}
	printf("%d", sum);
	_getch();
	return 0;

}
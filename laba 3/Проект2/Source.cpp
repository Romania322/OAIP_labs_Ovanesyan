*/
	Ованесян Даниил Арменович
	КТБО1-8 
	4 лаба, 10 вариант
	Поменять последнюю и первую букву местами
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h> 
#include <locale> 
#define MAX_LENGTH 1024

int replace(char *t);

int main()
{
	system("chcp 1251");
	system("cls");
	char text[MAX_LENGTH];
	printf("\tВведите ваш текст:\n");
	fgets(text, MAX_LENGTH, stdin);
	replace(text);
	printf("\tИзменённый текст:\n");
	printf("%s", text);
	_getch();
	return 0;
}

int replace(char *t)
{
	char buff;
	int k = 0; 
	for (int i = 1; t[i] != '\0'; i++)
	{
		if (t[i] == ' ')
		{
			k = i + 1;
		}
		if ((t[i+1] == ' ' || t[i + 1] == '\n') && t[k] != ' ' )
		{
			buff = t[k];
			t[k] = t[i];
			t[i] = buff;
		}
	}
	return 0;
}

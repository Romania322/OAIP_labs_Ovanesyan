/*
Ованесян Даниил 4 лаба 10 вариант
Сделать считывание данных с файла
КТБО 1-8
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale>
#define MAX_LENGTH 1024

int replace_text(int stop, char *text);
int Get_lenght_stroki(FILE *File);
int read_file(int stop, char *text, FILE *SourceFile);

int main()
{
	system("chcp 1251");
	system("cls");
	FILE *File = fopen("text1.txt", "r");
	FILE *NewFile = fopen("text2.txt", "w");
	if (File == NULL)
	{
		printf("Error, file is not found!");
		_getch();
		exit(0);
	}
	char text[MAX_LENGTH];
	int stop;
	stop = Get_lenght_stroki(File);
	fclose(File);
	FILE *SourceFile = fopen("text1.txt", "r");
	read_file(stop, text, SourceFile);

	replace_text(stop, text);
	for (int i = 0; i < stop; i++)
	{
		fprintf(NewFile, "%c", text[i]);
	}
	fclose(NewFile);
	fclose(SourceFile);


	return 0;
}

int Get_lenght_stroki(FILE *SourceFile)
{
	int stop = 0;
	while(fgetc(SourceFile) != EOF)
	{
		stop = stop + 1;
	}
	return stop;
}

int read_file(int stop, char *text, FILE *SourceFile)
{
	int i;
	for (i = 0; i < stop; i++)
	{
		text[i] = fgetc(SourceFile);
	}
	return 0;
}

int replace_text(int stop, char *text)
{
	char buff;
	int k = 0;

	for (int i = 1; text[i] != '\0'; i++)
	{
		if (text[i] == ' ' || text[i] == '\n')
		{
			k = i + 1;
		}
		if ((text[i + 1] == ' ' || text[i + 1] == '\n' || i == stop - 1) && text[k] != ' ')
		{
			buff = text[k];
			text[k] = text[i];
			text[i] = buff;
		}
	}
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h> 
#include <locale> 
#define MAX_LENGTH 1024

int replace(int stop , char *text );
int ret(FILE *File);
int pop(int stop, char *text, FILE *SourceFile);

int main()
{
	system("chcp 1251");
	system("cls");
	FILE *File = fopen("text1.txt", "r");
	FILE *NewFile = fopen("text2.txt", "w");
	char text[MAX_LENGTH];
	int stop;
	
	stop = ret(File);
	
	fclose(File);
	FILE *SourceFile = fopen("text1.txt", "r");
	pop(stop, text, SourceFile);
	
	replace(stop, text);
	for (int i = 0; i < stop; i++)
		fprintf(NewFile, "%c", text[i]);
	fclose(NewFile);
	fclose(SourceFile);
	
	
	return 0;
}

int ret(FILE *SourceFile)
{
	int stop = 0;
	for (int i = 0; fgetc(SourceFile) != EOF; i++)
		stop = stop + 1;
	return stop;
}

int pop(int stop, char *text, FILE *SourceFile)
{
	int i;
	for (i = 0; i < stop; i++)
	{
		text[i] = fgetc(SourceFile);
	}
	return 0;
}

int replace(int stop, char *text)
{
	char buff;
	int k = 0;

	for (int i = 1; text[i] != '\0'; i++)
	{
		if (text[i] == ' ')
		{
			k = i + 1;
		}
		if ((text[i + 1] == ' ' || text[i + 1] == '\n' || i == stop-1 ) && text[k] != ' ')
		{
			buff = text[k];
			text[k] = text[i];
			text[i] = buff;
		}
	}
	return 0;
}
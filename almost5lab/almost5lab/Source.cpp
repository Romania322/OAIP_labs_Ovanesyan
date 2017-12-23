/*
Ованесян Даниил
Лабораторная работа №5
Вариант 10
Задание:Написать программу, которая записывает с клавиатуры в файл структуру
согласно выданному варианту задания. В качестве разделителя полей структуры
использовать символ табуляции. В программе реализовать:
а) дополнение существующего массива структур новыми структурами;
б) поиск структуры с заданным значением выбранного элемента;
в) вывод на экран содержимого массива структур;
г) упорядочение массива структур по заданному полю (элементу), например
государство по численности.
Вариант задания: «Государство»: название страны, столица, язык, население, площадь
территории, денежная единица, государственный строй.
*/

#define _CRT_SECURE_NO_WARNINGS 

#include "locale"
#include <stdio.h>


#define LENGTH_WORD_FOR_STRUCT 1000
#define COUNT_STRUCTS 100
using namespace std;

struct country
{
	char nameCountry[LENGTH_WORD_FOR_STRUCT];
	char maincity[LENGTH_WORD_FOR_STRUCT];
	char language[LENGTH_WORD_FOR_STRUCT];
	char peoples[LENGTH_WORD_FOR_STRUCT];
	char ploshad[LENGTH_WORD_FOR_STRUCT];
	char money[LENGTH_WORD_FOR_STRUCT];
	char gosstroy[LENGTH_WORD_FOR_STRUCT];

};

void sorting_f(int number, int field, struct country *gos);
void sort(int number_of_structers, struct country *gos);
void addStruct(int k, struct country *gos);
void outputFile(int p, struct country *gos);
int gettingStructs(struct country *gos);
//void sortirovkaGosudarstva(country *gos);
//void swap(struct country &gos1, struct country &gos2);
void new_INPUT(int number_of_structures, struct country *gos);

int main()
{
	struct country gos[COUNT_STRUCTS];
	int main_screen = 0;
	int number_of_structures = gettingStructs(gos);
	int sorting = 0;
	int search = 0;
	int not_yes_structs = 0;
	int i = 0;

	do
	{
		printf("(vvedite nomer)\n");
		printf("1. Dopolnit' massiv struktur novymi strukturami.\n");
		printf("2. Poisk struktury po zadannym znachenijam vybrannogo jelementa.\n");
		printf("3. Vyvod na jekran soderzhimogo massiva struktur.\n");
		printf("4. Uporjadochenie massiva struktur po gosudarstvu.\n");
		printf("5. Vyhod iz programmy.\n");
		printf("--> ");
		scanf_s("%d", &main_screen);
		system("cls");

		switch (main_screen)
		{
		case 1:
			printf("--- Dopolnit' massiv struktur novymi strukturami ---\n");
			if (number_of_structures < COUNT_STRUCTS)
			{
				addStruct(number_of_structures, gos);
				number_of_structures++;
				system("pause");
				system("cls");
			}
			else
			{
				printf("--- Vvedenno maksimal'no vozmozhnoe kolichestvo struktur ---");
			}
			break;
		case 2:
			if (number_of_structures != 0)
			{
				printf("(vvedite nomer)\n");
				printf("--- Poisk struktury po zadannym znachenijam vybrannogo jelementa --- \n");
				printf("1. Poisk po gosvu.\n");
				printf("2. Poisk po maincity.\n");
				printf("3. Poisk po language.\n");
				printf("4. Poisk po ludiam.\n");
				printf("5. Poisk po ploshadi.\n");
				printf("6. Poisk po dengam.\n");
				printf("7. Poisk po gossstroyu.\n");
				printf("--> ");

				scanf("%d", &search);
				system("cls");

				switch (search)
				{
				case 1: printf(" --- Poisk po nazvaniyu gosudarstva --- \n"); printf("Vvedite nazvanie gosva\n -->"); char search_gosvo[LENGTH_WORD_FOR_STRUCT]; scanf("%s", &search_gosvo);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_gosvo, gos[i].nameCountry))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							outputFile(i, gos);
						}
					}
					break;
				case 2: printf(" --- Poisk po glavnomu gorodu --- \n"); printf("Vvedite glavniy gorod\n -->"); char search_maincity[LENGTH_WORD_FOR_STRUCT]; scanf("%s", &search_maincity);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_maincity, gos[i].maincity))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							outputFile(i, gos);
						}
					}
					break;
				case 3: printf(" --- Poisk po yaziky --- \n"); printf("Vvedite yazik\n -->"); char search_language[LENGTH_WORD_FOR_STRUCT]; scanf("%s", &search_language);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_language, gos[i].language))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							outputFile(i, gos);
						}
					}

					break;
				case 4: printf(" --- Poisk ludiam --- \n"); printf("Vvedite kol-vo ludei\n -->"); char search_peoples[LENGTH_WORD_FOR_STRUCT]; scanf("%s", &search_peoples);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_peoples, gos[i].peoples))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							outputFile(i, gos);
						}
					}

					break;
				case 5: printf(" --- Poisk po ploshadi --- \n"); printf("Vvediteploshad\n -->"); char search_ploshad[LENGTH_WORD_FOR_STRUCT]; scanf("%s", &search_ploshad);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_ploshad, gos[i].ploshad))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							outputFile(i, gos);
						}
					}

					break;
				case 6: printf(" --- Poisk po dengam --- \n"); printf("Vvedite kol-vo deneg(rubley)\n -->"); char search_money[LENGTH_WORD_FOR_STRUCT]; scanf("%s", &search_money);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_money, gos[i].money))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							outputFile(i, gos);
						}
					}

					break;
				case 7: printf(" --- Poisk po gosstyoryu --- \n"); printf("Vvedite gosstroy\n -->"); char search_gosstroy[LENGTH_WORD_FOR_STRUCT]; scanf("%s", &search_gosstroy);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_gosstroy, gos[i].gosstroy))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							outputFile(i, gos);
						}
					}

					break;
				default: printf("Takogo varianta vybora net.");
				}
				if (not_yes_structs == 0)
				{
					printf("Struktura ne najdenna\n");
				}
				not_yes_structs = 0;
				system("pause");
				system("cls");
			}
			else
			{
				printf("--- Zapolnennyh struktur net ---\n");
			}
			system("pause");
			system("cls");
			break;
		case 3:
			printf("--- Vyvod na jekran soderzhimogo massiva struktur ---\n");
			if (number_of_structures == 0)
			{
				printf("Zapolnennyh struktur net\n");
			}
			else
			{
				for (i = 0; i < number_of_structures; i++)
				{
					outputFile(i, gos);
				}
			}
			system("pause");
			system("cls");
			break;
		case 4:
		{
			
			sort(number_of_structures, gos);
			break;
		}


		case 5:
			exit(0);
			break;
		default: printf("Takogo varianta vybora net.");
		}
	} while (true);
	system("pause");
	return 0;
}

void addStruct(int k, struct country *gos)
{
	printf("Vvod struktur\n");
	printf("Vvedite nazvanie gosudarstva --> ");
	scanf("%s", &gos[k].nameCountry);
	printf("Vvedite nazvanie glavnogo goroda --> ");
	scanf("%s", &gos[k].maincity);
	printf("Vvedite yazik --> ");
	scanf("%s", &gos[k].language);
	printf("Vvedite kol-vo ludei --> ");
	scanf("%s", &gos[k].peoples);
	printf("Vvedite ploshad gos-va --> ");
	scanf("%s", &gos[k].ploshad);
	printf("Vvedite kol-vo deneg --> ");
	scanf("%s", &gos[k].money);
	printf("Vvedite gosstroy --> ");
	scanf("%s", &gos[k].gosstroy);

	printf("Struktura vvedenna.\n\n");

	FILE *text_file_output = fopen("output.txt", "a");

	fprintf(text_file_output, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", &gos[k].nameCountry, &gos[k].maincity, &gos[k].language, &gos[k].peoples, &gos[k].ploshad, &gos[k].money, &gos[k].gosstroy);
	fclose(text_file_output);
}

int sorting_comparison(int field, int i, struct country *gos)
{
	int code;
	switch (field) {
	case 1:code = strcmp(gos[i + 1].nameCountry, gos[i].nameCountry); return code;
	case 2:code = strcmp(gos[i + 1].maincity, gos[i].maincity); return code;
	case 3:code = strcmp(gos[i + 1].language, gos[i].language); return code;
	case 4:code = strcmp(gos[i + 1].peoples, gos[i].peoples); return code;
	case 5:code = strcmp(gos[i + 1].ploshad, gos[i].ploshad); return code;
	case 6:code = strcmp(gos[i + 1].money, gos[i].money); return code;
	case 7:code = strcmp(gos[i + 1].maincity, gos[i].maincity); return code;

	}
}

void sort(int number_of_structures, struct country *gos)
{
	int sorting_s = 0;
	printf(" --- Uporjadochenie massiva struktur po zadannomu polju --- \n");
	printf("(vvedite nomer)\n");
	printf("--- Sortirovka po zadannomu polju --- \n");
	printf("1. Sortirovka po gosadarstvu.\n");
	printf("2. Sortirovka po stolice.\n");
	printf("3. Sortirovka po yaziky.\n");
	printf("4. Sortirovka po kol- vu ludiam.\n");
	printf("5. Sortirovka po ploshadi.\n");
	printf("5. Sortirovka po dengam.\n");
	printf("6. Sortirovka po gosstroyu.\n");

	printf("--> ");
	scanf("%d", &sorting_s);
	system("cls");



	if (number_of_structures != 0)

	{
		switch (sorting_s)
		{
		case 1: printf(" --- Sortirovka po gosudarstvu --- \n"); sorting_f(number_of_structures, sorting_s, gos);
			break;
		case 2: printf(" --- Sortirovka po stolice --- \n"); sorting_f(number_of_structures, sorting_s, gos);
			break;
		case 3: printf(" --- Sortirovka po yaziky --- \n"); sorting_f(number_of_structures, sorting_s, gos);
			break;
		case 4: printf(" --- Sortirovka po kol-vu ludei --- \n"); sorting_f(number_of_structures, sorting_s, gos);
			break;
		case 5: printf(" --- Sortirovka po ploshadi --- \n"); sorting_f(number_of_structures, sorting_s, gos);
			break;
		case 6: printf(" --- Sortirovka po money --- \n"); sorting_f(number_of_structures, sorting_s, gos);
			break;
		case 7: printf(" --- Sortirovka po gosstroyu --- \n"); sorting_f(number_of_structures, sorting_s, gos);
			break;


		default: printf("Takogo varianta vybora net.");
		}
		printf("Structura otsortirovanna");
		system("pause");
	}
	else
	{
		printf("--- Zapolnennyh struktur net ---\n");
		system("pause");
	}
	system("cls");


}



void sorting_s(int number, int field, struct country *gos)
{

	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number - i - 1; j++)
		{
			if ((sorting_comparison(field, j, gos)) < 0)
			{
				country Buff = gos[j];
				gos[j] = gos[j + 1];
				gos[j + 1] = Buff;
			}
		}
	}
	outputFile(number, gos);
	new_INPUT(number, gos);
	system("pause");
	system("cls");
}




void outputFile(int p, struct country *gos)
{
	printf("Gosudarstvo --> %s\t", gos[p].nameCountry);
	printf("Glavni gorod --> %s\t", gos[p].maincity);
	printf("Yazik --> %s\t", gos[p].language);
	printf("Ludi --> %s\t", gos[p].peoples);
	printf("Ploshad --> %s\t", gos[p].ploshad);
	printf("Dengi --> %s\t", gos[p].money);
	printf("Gosstroy --> %s\t", gos[p].gosstroy);

}

void new_INPUT(int number_of_structures, struct country *gos)
{
	FILE *text_file_output = fopen("output.txt", "w");
	int i = 0;
	for (i = 0; i < number_of_structures; i++)
	{
		fprintf(text_file_output, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", &gos[i].nameCountry, &gos[i].maincity, &gos[i].language, &gos[i].peoples, &gos[i].ploshad, &gos[i].money, &gos[i].gosstroy);
	}
	fclose(text_file_output);
}


int gettingStructs(struct country *gos)
{
	FILE *text_file_output = fopen("output.txt", "r");
	FILE *text_file_output_test = fopen("output.txt", "r");
	int k = 0;

	if (text_file_output != NULL)
	{
		while (fscanf(text_file_output_test, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &gos[k].nameCountry, &gos[k].maincity, &gos[k].language, &gos[k].peoples, &gos[k].ploshad, &gos[k].money, &gos[k].gosstroy) != EOF)
		{
			fscanf(text_file_output, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &gos[k].nameCountry, &gos[k].maincity, &gos[k].language, &gos[k].peoples, &gos[k].ploshad, &gos[k].money, &gos[k].gosstroy);
			k++;
		}
	}
	else
	{
		printf("--- Fajla net ili on ne otkrylsja ---");
		system("pause");
		exit(0);
	}
	fclose(text_file_output);
	fclose(text_file_output_test);
	return k;
}








#include "locale"	//chto za hren' tut tipo iz C++
#include <stdio.h>
#pragma warning(disable : 4996)	//bez jetogo u menja oshibka
#define N 1000	//dlinna massivov v strukturah
#define Y 100	//kolichestvo struktur
using namespace std;

struct Mag	//struktura koroch
{
	char gosvo[N];
	char maincity[N];
	char language[N];
	char peoples[N];
	char ploshad[N];
	char money[N];
	char gosstroy[N];

} Gos[Y];

void INPUT(int k);
void OUTPUT(int p);
int INITIALIZATION();
void sortirovka_gosudarstva(Mag *Gos);
void obmen(struct Mag &Gos1, struct Mag &Gos2);

int main()
{
	int main_screen = 0;
	int number_of_structures = INITIALIZATION();
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
		system("cls");	//ochishhaet jekran

		switch (main_screen)
		{
		case 1:
			printf("--- Dopolnit' massiv struktur novymi strukturami ---\n");
			if (number_of_structures < Y)	//proverka 
			{
				INPUT(number_of_structures);
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
				case 1: printf(" --- Poisk po nazvaniyu gosudarstva --- \n"); printf("Vvedite nazvanie gosva\n -->"); char search_gosvo[N]; scanf("%s", &search_gosvo);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_gosvo, Gos[i].gosvo))	//tip sravnivaet kody strok
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1); //posmoti kod sam znaesh' kogo
							OUTPUT(i);
						}
					}
					break;
				case 2: printf(" --- Poisk po glavnomu gorodu --- \n"); printf("Vvedite glavniy gorod\n -->"); char search_maincity[N]; scanf("%s", &search_maincity);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_maincity, Gos[i].maincity))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							OUTPUT(i);
						}
					}
					break;
				case 3: printf(" --- Poisk po yaziky --- \n"); printf("Vvedite yazik\n -->"); char search_language[N]; scanf("%s", &search_language);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_language, Gos[i].language))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							OUTPUT(i);
						}
					}

					break;
				case 4: printf(" --- Poisk ludiam --- \n"); printf("Vvedite kol-vo ludei\n -->"); char search_peoples[N]; scanf("%s", &search_peoples);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_peoples, Gos[i].peoples))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							OUTPUT(i);
						}
					}

					break;
				case 5: printf(" --- Poisk po ploshadi --- \n"); printf("Vvediteploshad\n -->"); char search_ploshad[N]; scanf("%s", &search_ploshad);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_ploshad, Gos[i].ploshad))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							OUTPUT(i);
						}
					}

					break;
				case 6: printf(" --- Poisk po dengam --- \n"); printf("Vvedite kol-vo deneg(rubley)\n -->"); char search_money[N]; scanf("%s", &search_money);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_money, Gos[i].money))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							OUTPUT(i);
						}
					}

					break;
				case 7: printf(" --- Poisk po gosstyoryu --- \n"); printf("Vvedite gosstroy\n -->"); char search_gosstroy[N]; scanf("%s", &search_gosstroy);
					for (i = 0; i<number_of_structures; i++)
					{
						if (!strcmp(search_gosstroy, Gos[i].gosstroy))
						{
							not_yes_structs++;
							printf("Struktura najdenna\n Nomer struktury -> %d\n", i + 1);
							OUTPUT(i);
						}
					}

					break;
				default: printf("Takogo varianta vybora net.");
				}
				if (not_yes_structs == 0) //koroch jeto nuzhno vyvesti za kejsi ti v konec svicha
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
			if (number_of_structures == 0)	//proverka na nalichie zapolnennyh struktur
			{
				printf("Zapolnennyh struktur net\n");
			}
			else
			{
				for (i = 0; i < number_of_structures; i++)
				{
					OUTPUT(i);
				}
			}
			system("pause");
			system("cls");
			break;
		case 4:
			printf(" --- Uporjadochenie massiva struktur po zadannomu polju --- \n");
			printf("(vvedite nomer)\n");
			printf("--- Sortirovka po zadannomu polju --- \n");
			printf("1. Sortirovka po gosudarstvu.\n");


			printf("--> ");
			scanf_s("%d", sorting);
			system("cls");


			switch (sorting)
			{
			case 1: printf(" --- Sortirovka po gosudarstvu --- \n");
				sortirovka_gosudarstva(Gos);

				break;


			default: printf("Takogo varianta vybora net.");
				break;
			}


		case 5:
			exit(0);	//vyhod iz programmy
			break;
		default: printf("Takogo varianta vybora net.");
		}
	} while (true);
	system("pause");
	return 0;
}

void INPUT(int k)	//funkcija dlja vvoda dannyh v strukturu, a tak zhe zapis' dannyh v fajl	
{
	printf("Vvod struktur\n");
	printf("Vvedite nazvanie gosudarstva --> ");
	scanf("%s", &Gos[k].gosvo);
	printf("Vvedite nazvanie glavnogo goroda --> ");
	scanf("%s", &Gos[k].maincity);
	printf("Vvedite yazik --> ");
	scanf("%s", &Gos[k].language);
	printf("Vvedite kol-vo ludei --> ");
	scanf("%s", &Gos[k].peoples);
	printf("Vvedite ploshad gos-va --> ");
	scanf("%s", &Gos[k].ploshad);
	printf("Vvedite kol-vo deneg --> ");
	scanf("%s", &Gos[k].money);
	printf("Vvedite gosstroy --> ");
	scanf("%s", &Gos[k].gosstroy);

	printf("Struktura vvedenna.\n\n");

	FILE *text_file_output = fopen("output.txt", "a");	//otkryti fajla 

	fprintf(text_file_output, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", &Gos[k].gosvo, &Gos[k].maincity, &Gos[k].language, &Gos[k].peoples, &Gos[k].ploshad, &Gos[k].money, &Gos[k].gosstroy);
	fclose(text_file_output);
}

void OUTPUT(int p)
{
	printf("Gosudarstvo --> %s\t", Gos[p].gosvo);
	printf("Glavni gorod --> %s\t", Gos[p].maincity);
	printf("Yazik --> %s\t", Gos[p].language);
	printf("Ludi --> %s\t", Gos[p].peoples);
	printf("Ploshad --> %s\t", Gos[p].ploshad);
	printf("Dengi --> %s\t", Gos[p].money);
	printf("Gosstroy --> %s\t", Gos[p].gosstroy);

}


int INITIALIZATION()	//inicializacija(pri otkrytii programmy ona vvodit v struktury dannye iz fajla)
{
	FILE *text_file_output = fopen("output.txt", "r");
	FILE *text_file_output_test = fopen("output.txt", "r");	//vtoroj raz otkryvaem fajl dlja proverki strok 
	int k = 0;

	if (text_file_output != NULL)
	{
		while (fscanf(text_file_output_test, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &Gos[k].gosvo, &Gos[k].maincity, &Gos[k].language, &Gos[k].peoples, &Gos[k].ploshad, &Gos[k].money, &Gos[k].gosstroy) != EOF)
		{
			fscanf(text_file_output, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &Gos[k].gosvo, &Gos[k].maincity, &Gos[k].language, &Gos[k].peoples, &Gos[k].ploshad, &Gos[k].money, &Gos[k].gosstroy);
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

void sortirovka_gosudarstva(Mag *Gos)//struct Mag *Gos[])
{
	FILE *text_file_output = fopen("output.txt", "r");
	FILE *text_file_output_test = fopen("output.txt", "r");
	int k = 0;

	//if (text_file_output != NULL)
	//{
	//	while (fscanf(text_file_output_test, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &Gos[k].gosvo, &Gos[k].maincity, &Gos[k].language, &Gos[k].peoples, &Gos[k].ploshad, &Gos[k].money, &Gos[k].gosstroy) != EOF)
	//	{
	//		fscanf(text_file_output, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &Gos[k].gosvo, &Gos[k].maincity, &Gos[k].language, &Gos[k].peoples, &Gos[k].ploshad, &Gos[k].money, &Gos[k].gosstroy);
	//		k++;
	//	}
	//}
	//else
	//{
	//	printf("--- Fajla net ili on ne otkrylsja ---");
	//	system("pause");
	//	exit(0);
	//}

	int max = 0;
	for (int i = 0; i < k; i++)
	{
		if (strlen(Gos[i].gosvo) > max)
		{
			max = strlen(Gos[i].gosvo);
		}

	}
	for (int i = 0; i<max; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int h = j + 1; h < k; h++)
			{
				if (Gos[j].gosvo[i] && Gos[h].gosvo[i])
				{
					if (i == 0)
					{
						if (int(Gos[j].gosvo[0]) > int(Gos[h].gosvo[0]))
						{
							obmen(Gos[j], Gos[h]);
						}
					}
					if (i != 0)
					{
						if (int(Gos[j].gosvo[i]) > int(Gos[h].gosvo[i]))
						{
							int tr = 1;
							for (int q = i - 1; q> 0; q--)
							{
								if (int(Gos[j].gosvo[q]) != int(Gos[h].gosvo[q]))
								{
									tr = 0;
									break;
								}
							}
							if (tr == 1)
							{
								obmen(Gos[j], Gos[h]);
							}
						}
					}
				}
			}
		}


	}
	fclose(text_file_output);
	fclose(text_file_output_test);
}

void obmen(struct Mag &Gos1, struct Mag &Gos2)
{
	struct Mag buf;
	buf = Gos2;
	Gos2 = Gos1;
	Gos1 = buf;
}
/*

*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <conio.h> 

#define ARRAY_SIZE 100

int function_enter(void); 

int main() 
{ 
  int sum = 0, size, check, chekSize; 
  printf("Enter nomber of the size:"); 
  cheksize = function_enter(); 
  int array[ARRAY_SIZE]; 

  for (int i = 0; i < cheksize; i++) { 
    printf("Enter element:"); 
    array[i] = function_enter(); 
  } 
  for (int i = 0; i < cheksize; i++) 
  { 
    if (array[i] > 0) {
      sum += array[i]; 
    }
  } 

  printf("%d", sum); 
  _getch(); 
  return 0; 
} 

int function_enter(void) { 
  int number; 
  scanf("%d", &number); 
  
  if (getchar() != '\n') { 
    printf("Error number. Try again:"); 
    while (getchar() != '\n'); 
    number = function_enter(); 
  } 
  
  return number; 
}

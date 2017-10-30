#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <conio.h> 
int function_enter(void); 
int main() 
{ 
int sum = 0, size, count2, count1, check, cheksize; 
printf("Enter nomber of the size:"); 
cheksize = function_enter(); 
int array[100]; 

for (count1 = 0; count1 < cheksize; count1++) { 
printf("Enter element:"); 
array[count1] = function_enter(); 
} 
for (count2 = 0; count2 < cheksize; count2++) 
{ 
if (array[count2]>0) 
sum = sum + array[count2]; 
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

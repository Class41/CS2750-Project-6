// # Vasyl Onufriyev
// # CS2750 PA6
// # 11-6-18

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

typedef struct 
{
   double balance;
   int account;
   char name[];
} account;

int main()
{
   int selection;
   while(1)
   {
   DisplayMenu();
   scanf("%d", &selection);
   ExecuteFunction(selection);  
   }
   
   return 0;
}

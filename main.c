// # Vasyl Onufriyev
// # CS2750 PA6
// # 11-6-18

#include <stdio.h>
#include "menu.h"

typedef struct 
{
   double balance;
   int account;
   char name[];
} account;

int main()
{
   DisplayMenu();   

   return 0;
}

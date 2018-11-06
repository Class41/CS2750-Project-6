// # Vasyl Onufriyev
// # CS2750 PA6
// # 11-6-18

#include <stdio.h>
#include "bank.h"

void DisplayMenu()
{
   system("clear");
   printf("\
           0. Exit\n\
           1. Deposit\n\
           2. Withdraw\n\
           3. Add Account\n\
           4. Remove Account\n\
           5. Balance inquiry\n\
           6. View accounts\n");
}

int ExecuteFunction(int option)
{
   switch(option)
   {
      case 0:
         BankExit();
         return 1;
      case 1:
         return 1;
      case 2:
         return 1;
      case 3:
         return 1;
      case 4:
         return 1;
      case 5:
         return 1;
      case 6:
         return 1;
      default:
         return 0;
   }
}

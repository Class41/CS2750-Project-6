// # Vasyl Onufriyev
// # CS2750 PA6
// # 11-6-18

#include <stdio.h>
#include "bank.h"
#include "main.h"

//Shows the menu on call
void DisplayMenu()
{
   system("clear");
   printf("\
           Choose an operation (0-6):\n\
           0. Exit\n\
           1. Deposit\n\
           2. Withdraw\n\
           3. Add Account\n\
           4. Remove Account\n\
           5. Balance inquiry\n\
           6. View accounts\n");
}

//Calls option with structure array bnk.
int ExecuteFunction(int option, struct account bnk[])
{
   switch(option)
   {
      case 0:
         printf("\n-> Exit\nGoodbye!\n\n");
         BankExit(bnk);
         return 1;
      case 1:
         printf("-> Deposit\n");
         BankDeposit(bnk);
         return 1;
      case 2:
         printf("-> Withdraw\n");
         BankWithdraw(bnk);
         return 1;
      case 3:
         printf("-> Add Account\n");
         BankAddAccount(bnk);
         return 1;
      case 4:
         printf("-> Del Account\n");
         BankRemoveAccount(bnk);
         return 1;
      case 5:
         printf("-> Balance\n");
         BankBalanceInquire(bnk);
         return 1;
      case 6:
         printf("-> View Accounts\n");
         BankViewAccounts(bnk);
         return 1;
      default:
         return 0;
   }
}

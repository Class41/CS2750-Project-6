// # Vasyl Onufriyev
// # CS2750 PA6
// # 11-6-18

#include <stdio.h>
#include "bank.h"
#include "main.h"

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

int ExecuteFunction(int option, struct account bnk[])
{
   switch(option)
   {
      case 0:
         BankExit();
         return 1;
      case 1:
         BankDeposit(bnk);
         return 1;
      case 2:
         BankWithdraw(bnk);
         return 1;
      case 3:
         BankAddAccount(bnk);
         return 1;
      case 4:
         BankRemoveAccount(bnk);
         return 1;
      case 5:
         BankBalanceInquire(bnk);
         return 1;
      case 6:
         BankViewAccounts(bnk);
         return 1;
      default:
         return 0;
   }
}

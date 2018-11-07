// # Vasyl Onufriyev
// # CS2750 PA6
// # 11-6-18

#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

void BankExit()
{
   exit(0);
}

void BankDeposit(struct account bnk[])
{
   char accountNum[7];
   int i;
   do
   {
   printf("\nWhat account number would you like to deposit to?\n");
   
   scanf(" %s", accountNum);
   
   for(i = 0; i < 6; i++)
      if(!isdigit(accountNum[i]))
         accountNum[6] = 'F';

   } while(accountNum[6] != NULL);
   
   int acctNum = atoi(accountNum);
   int found = 0;
   
   for(i = 0; i < 50; i++)
   {
      if(bnk[i].account == acctNum)
         found = 1;
   }

   if(found == 0)
   {
      printf("Account not found!\n");
      return;
   }
   
   int depositVal;
   printf("How much would you like to deposit?\n");
   scanf(" %d", depositVal);

   bnk[i].balance += depositVal;
   writeData(bnk);
   printf("The balance on account %d is now %d\n", acctNum, bnk[i].balance);
      
}

void BankWithdraw(struct account bnk[])
{

}

void BankAddAccount(struct account bnk[])
{
        
}

void BankRemoveAccount(struct account bnk[])
{

}

void BankBalanceInquire(struct account bnk[])
{

}

void BankViewAccounts(struct account bnk[])
{

}

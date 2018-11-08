// # Vasyl Onufriyev
// # CS2750 PA6
// # 11-6-18

#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

int GetNextAvailableBankSlot(struct account bnk[])
{
   int i;
   for(i = 0; i < 50; i++)
   {
      if(bnk[i].account == 0)
         return i;
   }

   return -1;
}

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
         {
            found = 1;
            break;
         }
   }

   if(found == 0)
   {
      printf("Account not found!\n");
      return;
   }

   float depositVal;
   printf("Holder: %s %s %s\nBalance: $%.2f\nHow much would you like to deposit?\n",
      bnk[i].name[0], bnk[i].name[1], bnk[i].name[2],bnk[i].balance);

   scanf(" %f", &depositVal);

   if(depositVal < 0)
   {
      printf("\nInvalid entry\n");
      return;
   }
   bnk[i].balance += depositVal;
   writeData(bnk);
   printf("The balance on account %d is now $%.2f\n", 
      bnk[i].account, bnk[i].balance);
      
}

void BankWithdraw(struct account bnk[])
{
   char accountNum[7];
   int i;
   do
   {
   printf("\nWhat account number would you like to withdraw from?\n");
   
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
         {
            found = 1;
            break;
         }
   }

   if(found == 0)
   {
      printf("Account not found!\n");
      return;
   }
   
   float withVal;
   printf("Holder: %s %s %s\nBalance: $%.2f\nHow much would you like to withdraw?\n",
      bnk[i].name[0], bnk[i].name[1], bnk[i].name[2], bnk[i].balance);
   scanf(" %f", &withVal);

   if(bnk[i].balance - withVal < 0)
   {
      printf("\nNot enough funds in account!\n");
      return;
   }

   if(withVal < 0)
   {
      printf("\nInvalid entry\n");
      return;
   }

   bnk[i].balance -= withVal;
   writeData(bnk);
   printf("The balance on account %d is now $%.2f\n", 
      bnk[i].account, bnk[i].balance);

}

void BankAddAccount(struct account bnk[])
{
   int position = GetNextAvailableBankSlot(bnk);
   if(position == -1)
   {
         printf("\nThe bank is full!");
         return;
   }

   char accountNum[7];
   int i;

   do
   {
   printf("\nWhat is the desired account number?\n");
   
   scanf(" %s", accountNum);
   
   for(i = 0; i < 6; i++)
      if(!isdigit(accountNum[i]))
      {
         printf("\nINVALID INPUT!\n");
         accountNum[6] = 'F';
      }
   } while(accountNum[6] != NULL);

   int acctNum = atoi(accountNum);
   
   for(i = 0; i < 50; i++)
   {
      if(acctNum == bnk[i].account)
      {
         printf("\nAccount already exists. Returning to menu.\n");
         return;
      }
   }

   printf("\nFirst Name: ");
   scanf(" %s", bnk[position].name[0]);

   printf("\nMiddle Name: ");
   scanf(" %s", bnk[position].name[1]);

   printf("\nLast Name: ");
   scanf(" %s", bnk[position].name[2]);
   
   bnk[position].account = acctNum;
   bnk[position].balance = 0.00;

   printf("\nAccount created!\n");
   writeData(bnk);
}

void BankRemoveAccount(struct account bnk[])
{
   int acctNum;
   printf("What account number should be removed?\n ");
   
   scanf(" %d",&acctNum);

   int position;
   int i;
   for(i = 0; i < 50; i++)
   {
      if(bnk[i].account == acctNum)
      {
         bnk[i].account = 0;
         bnk[i].balance = 0;

         strcpy(bnk[i].name[0], "");
         strcpy(bnk[i].name[1], "");
         strcpy(bnk[i].name[2], "");

         writeData(bnk);
         printf("\nAccount deleted.\n");
         return;
      }
   }

   printf("\nNo such account found!\n");
}

void BankBalanceInquire(struct account bnk[])
{
        
   int acctNum;
   printf("What account number's balance should be checked?\n ");
   
   scanf(" %d",&acctNum);

   int position;
   int i;
   for(i = 0; i < 50; i++)
   {
      if(bnk[i].account == acctNum)
      {
         printf("Account: %d\nHolder: %s %s %s\nBalance: $%.2f\n",
            bnk[i].account, bnk[i].name[0], bnk[i].name[1], bnk[i].name[2],
            bnk[i].balance);
         return;
      }
   }
   printf("\nNo such bank account found!\n");
}

void BankViewAccounts(struct account bnk[])
{
   int i;
   for(i = 0; i < 50; i++)
   {
      if(bnk[i].account != 0)
      {
      printf("\n|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
      printf("\tHolder: %s %s %s\n\tAccount: %d\n\tBalance: $%.2f\n\n", 
         bnk[i].name[0], bnk[i].name[1], bnk[i].name[2],
         bnk[i].account, bnk[i].balance);
      }
   }
   printf("|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
}

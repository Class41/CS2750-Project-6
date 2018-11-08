// # Vasyl Onufriyev
// # CS2750 PA6
// # 11-6-18

#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

//returns the array index of the next available bank slot if any
int GetNextAvailableBankSlot(struct account bnk[])
{
   int i;
   for(i = 0; i < 50; i++)
   {
      if(bnk[i].account == 0) //bank slot empty, return its position
         return i; 
   }

   return -1; //bank full
}

//quit the application
void BankExit(struct account bnk[])
{
   free(bnk);
   exit(0);
}

//deposit money to bank menu call
void BankDeposit(struct account bnk[])
{
   char accountNum[7]; //hold 7 chars (1 extra to check for valid input)
   int i;
   do
   {
   printf("\nWhat account number would you like to deposit to?\n");
   
   scanf(" %s", accountNum);
   
   for(i = 0; i < 6; i++)
      if(!isdigit(accountNum[i])) //if any of the first 6 are not digits, fail
         accountNum[6] = 'F';

   } while(accountNum[6] != NULL); //while there is a 7th value
   
   int acctNum = atoi(accountNum); //conver to integer
   int found = 0;
   
   for(i = 0; i < 50; i++)
   {
      if(bnk[i].account == acctNum)
         {
            found = 1; //bank account found
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

   scanf(" %f", &depositVal); //get the amount to deposit

   if(depositVal < 0) //check for negatives
   {
      printf("\nInvalid entry\n");
      return;
   }
   bnk[i].balance += depositVal;
   writeData(bnk); //write data to file after updating balance
   printf("The balance on account %d is now $%.2f\n", 
      bnk[i].account, bnk[i].balance);
      
}

//withdraw call from menu
void BankWithdraw(struct account bnk[])
{
   char accountNum[7]; //same as deposit for this section
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

   if(bnk[i].balance - withVal < 0) //check if funds exist in the account
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

//create bank account call
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
   } while(accountNum[6] != NULL); //make sure no letters and only 6 input

   int acctNum = atoi(accountNum);
   
   for(i = 0; i < 50; i++)
   {
      if(acctNum == bnk[i].account) //check if account exists
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
   writeData(bnk); //update file
}

//remove account menu call
void BankRemoveAccount(struct account bnk[])
{
   int acctNum;
   printf("What account number should be removed?\n ");
   
   scanf(" %d",&acctNum);

   int position;
   int i;
   for(i = 0; i < 50; i++)
   {
      if(bnk[i].account == acctNum) //if we find the bank acc, set all to default
      {
         bnk[i].account = 0;
         bnk[i].balance = 0;

         strcpy(bnk[i].name[0], "");
         strcpy(bnk[i].name[1], "");
         strcpy(bnk[i].name[2], "");

         writeData(bnk); //write to file
         printf("\nAccount deleted.\n");
         return;
      }
   }

   printf("\nNo such account found!\n");
}

//Get bank balance menu call
void BankBalanceInquire(struct account bnk[])
{
        
   int acctNum;
   printf("What account number's balance should be checked?\n ");
   
   scanf(" %d",&acctNum); //get account number

   int position;
   int i;
   for(i = 0; i < 50; i++)
   {
      if(bnk[i].account == acctNum) //print details if account is found
      {
         printf("Account: %d\nHolder: %s %s %s\nBalance: $%.2f\n",
            bnk[i].account, bnk[i].name[0], bnk[i].name[1], bnk[i].name[2],
            bnk[i].balance);
         return;
      }
   }
   printf("\nNo such bank account found!\n");
}

//Get bank account list menu call
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

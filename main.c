// # Vasyl Onufriyev
// # CS2750 PA6
// # 11-6-18

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

struct account
{
   int balance;
   int account;
   char name[100];
};

int writeData(struct account bnk[])
{
   printf("in write: %d", bnk[1].balance);
   FILE* fsout = fopen("accounts.dat", "wb");
   
   if(bnk == NULL)
   {
      printf("accounts.dat missing and unable to open!");
      return -1;
   }

   int i;
   for(i = 0; i < 50; i++)
   {
      fwrite(&bnk[i], sizeof(struct account), 1, fsout);
   }

   fclose(fsout);
   return 0;
}


int readData(struct account bnk[])
{
   FILE* fsin = fopen("accounts.dat", "rb");
   
   if(bnk == NULL)
   {
      printf("accounts.dat missing and unable to open!");
      return -1;
   }

   int i;
   for(i = 0; i < 50; i++)
   {
      fread(&bnk[i], sizeof(struct account), 1, fsin);
   } 
 
   fclose(fsin);
   return 0;
}

int main()
{
   int selection;
   struct account bnk[50];
   readData(bnk);
    
   //readData(bankaccounts);
   //writeData(bankaccounts);
   

  // bankaccounts[1].balance = 5;
  // bankaccounts[1].account = 123456;
  // strcpy(bankaccounts[1].name, "bob");
  

   while(1)
   {
   //DisplayMenu();
   scanf("%d", &selection);
   ExecuteFunction(selection);  
   }
   
   return 0;
}

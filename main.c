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

int writeData(struct account* bnk)
{
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


void readData()
{

}

int main()
{
   int selection;
   struct account bankaccounts[50];

   writeData(bankaccounts);
   

   //bankaccounts[count].balance = 5;
   //bankaccounts[count].account = 123456;
   //strcpy(bankaccounts[count].name, "bob");
   

   //FILE* data2 = fopen("accounts.dat", "rb");

   //fread(&bankaccounts[1], sizeof(struct account), 1, data2);


   //printf("%d", bankaccounts[1].balance);

   while(1)
   {
   //DisplayMenu();
   scanf("%d", &selection);
   ExecuteFunction(selection);  
   }
   
   return 0;
}

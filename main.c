// # Vasyl Onufriyev
// # CS2750 PA6
// # 11-6-18

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "main.h"
#include <ctype.h>
#include <unistd.h>

int writeData(struct account bnk[])
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
   struct account* bnk = malloc(sizeof(struct account) * 50); 
   char pause;

   if(!(access("accounts.dat", F_OK) != -1) )
      writeData(bnk);

   while(1)
   {
      DisplayMenu();
      readData(bnk);
      scanf(" %d", &selection);
      ExecuteFunction(selection, bnk);
      printf("Continuing in 5 seconds...\n");
      sleep(5);
      selection = 0;
   }
   
   return 0;
}

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

//writes the array of structs to file
int writeData(struct account bnk[])
{
   FILE* fsout = fopen("accounts.dat", "wb"); //open file
   
   if(bnk == NULL)
   {
      printf("accounts.dat missing and unable to open!"); //something went wrong
      return -1;
   }

   int i;
   for(i = 0; i < 50; i++) //write all 50 accounts to file
   {
      fwrite(&bnk[i], sizeof(struct account), 1, fsout);
   }

   fclose(fsout); //close stream
   return 0;
}

//reads array of structs into memory
int readData(struct account bnk[])
{
   FILE* fsin = fopen("accounts.dat", "rb"); //open file
   
   if(bnk == NULL)
   {
      printf("accounts.dat missing and unable to open!"); //something went wrong
      return -1;
   }

   int i;
   for(i = 0; i < 50; i++) //get all 50 accounts into memory
   {
      fread(&bnk[i], sizeof(struct account), 1, fsin);
   } 
 
   fclose(fsin);
   return 0;
}

int main()
{
   int selection; //keeps track of user's selection
   struct account* bnk = calloc(50, sizeof(struct account)); //allocate memory 
   char pause; //unused

   if(bnk == NULL)
   {
      printf("Failed to allocated memory. Aborting.");
      return 1;
   }

   if(!(access("accounts.dat", F_OK) != -1) )
      writeData(bnk);

   while(1)
   {
      DisplayMenu(); //display menu
      readData(bnk); //read the data from file
      scanf(" %d", &selection); //scan for selection
      ExecuteFunction(selection, bnk); //execute selection
      printf("Continuing in 5 seconds...\n");
      sleep(5); //wait 5 sec and clear screen
      selection = 0; //default selection to exit
   }
   
   return 0;
}

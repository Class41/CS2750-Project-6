// # Vasyl Onufriyev
// # CS2750 PA6
// # 11-6-18

#ifndef _MAIN_H
#define _MAIN_H

//Account structure
struct account
{
   float balance;
   int account;
   char name[3][50];
};

int writeData(struct account bnk[]);
int readData(struct account bnk[]);


#endif

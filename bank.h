// # Vasyl Onufriyev
// # CS2750 PA6
// # 11-6-18

#ifndef _BANK_H
#define _BANK_H

#include "main.h"

void BankExit();
void BankDeposit(struct account bnk[]);
void BankWithdraw(struct account bnk[]);
void BankAddAccount(struct account bnk[]);
void BankRemoveAccount(struct account bnk[]);
void BankBalanceInquire(struct account bnk[]);
void BankViewAccounts(struct account bnk[]);

#endif

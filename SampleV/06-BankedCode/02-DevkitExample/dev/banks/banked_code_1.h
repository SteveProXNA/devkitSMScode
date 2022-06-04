#ifndef _BANK_1_H_
#define _BANK_1_H_

#ifdef _CONSOLE
int banked_code_1();
#else
int banked_code_1() __banked;
#endif

#endif//_BANK_1_H_
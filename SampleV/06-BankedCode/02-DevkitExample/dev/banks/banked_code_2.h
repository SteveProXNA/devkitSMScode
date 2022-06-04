#ifndef _BANK_2_H_
#define _BANK_2_H_

#ifdef _CONSOLE
int banked_code_2();
#else
int banked_code_2() __banked;
#endif

#endif//_BANK_2_H_
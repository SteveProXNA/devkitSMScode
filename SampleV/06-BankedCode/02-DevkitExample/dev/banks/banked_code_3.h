#ifndef _BANK_3_H_
#define _BANK_3_H_

#ifdef _CONSOLE
int banked_code_3();
#else
int banked_code_3() __banked;
#endif

#endif//_BANK_3_H_
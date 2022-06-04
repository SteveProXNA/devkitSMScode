#ifndef _SCROLL_MANAGER_H_
#define _SCROLL_MANAGER_H_

#include "../object/scroll_object.h"

// Global variable.
extern struct_scroll_object global_scroll_object;

// Methods.
void engine_scroll_manager_init();
void engine_scroll_manager_up();
void engine_scroll_manager_down();

#endif//_SCROLL_MANAGER_H_
#ifndef _GAMER_MANAGER_H_
#define _GAMER_MANAGER_H_

#include "../object/gamer_object.h"

// Global variable.
extern struct_gamer_object global_gamer_object;

// Methods.
void engine_gamer_manager_init( unsigned char px, unsigned char py, unsigned char vel, unsigned int tile );
void engine_gamer_manager_update( char dx, char dy );
void engine_gamer_manager_draw();

#endif//_GAMER_MANAGER_H_

#ifndef _MAP_MANAGER_H_
#define _MAP_MANAGER_H_

#include "../object/map_object.h"

// Global variable.
extern struct_map_object global_map_object;

void engine_map_manager_init( unsigned char *level_data );
void engine_map_manager_draw_map_screen();
void engine_map_manager_draw_map();

#endif//_MAP_MANAGER_H_
#include "screen_manager.h"
#include "content_manager.h"
#include "global_manager.h"
#include "input_manager.h"
#include "map_manager.h"
#include "../content/gfx.h"

void engine_screen_manager_init()
{
	engine_map_manager_init( ( unsigned char * ) level1_bin );
	engine_map_manager_draw_map_screen();
}

void engine_screen_manager_update()
{
	unsigned char input1;
	unsigned char input2;
	input1 = engine_input_manager_move_up();
	input2 = engine_input_manager_move_fire1();

	if( input1 || input2 )
	{
		engine_map_manager_draw_map();
	}
}

#include "screen_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "input_manager.h"
#include "gamer_manager.h"
#include "tile_manager.h"
#include "tree_manager.h"

void engine_screen_manager_init()
{
	engine_gamer_manager_init( 56, 48, 1, 256 );
	engine_tree_manager_draw();
	engine_tile_manager_draw_sides( 8, 6 );
}

void engine_screen_manager_update()
{
	unsigned char input;
	signed char dx = 0;
	signed char dy = 0;

	input = engine_input_manager_move_left();
	if( input )
	{
		dx = -1;
	}
	else
	{
		input = engine_input_manager_move_right();
		if( input )
		{
			dx = 1;
		}
	}

	input = engine_input_manager_move_up();
	if( input )
	{
		dy = -1;
	}
	else
	{
		input = engine_input_manager_move_down();
		if( input )
		{
			dy = 1;
		}
	}

	if( 0 != dx || 0 != dy )
	{
		engine_gamer_manager_update( dx, dy );
	}

	engine_gamer_manager_draw();
}
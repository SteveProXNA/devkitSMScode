#include "test_screen.h"
#include "../engine/enum_manager.h"
#include "../engine/input_manager.h"
#include "../engine/scroll_manager.h"

void screen_test_screen_load()
{
	engine_scroll_manager_load();
}

void screen_test_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	unsigned char delta;
	unsigned char loops;

	delta = 1;
	input = engine_input_manager_move_fire1();
	if( input )
	{
		delta = 2;
	}

	input = engine_input_manager_move_right();
	if( input )
	{
		for( loops = 0; loops < delta; loops++ )
		{
			engine_scroll_manager_update_right( 1 );
		}
	}
	input = engine_input_manager_move_left();
	if( input )
	{
		for( loops = 0; loops < delta; loops++ )
		{
			engine_scroll_manager_update_left( 1 );
		}
	}

	*screen_type = screen_type_test;
}
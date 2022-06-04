#include "screen_manager.h"
#include "content_manager.h"
#include "input_manager.h"
#include "scroll_manager.h"
	
void engine_screen_manager_init()
{
}

void engine_screen_manager_update()
{
	unsigned char input;
	input = engine_input_manager_move_down();
	if( input )
	{
		engine_scroll_manager_down();
	}
	
	input = engine_input_manager_move_up();
	if( input )
	{
		engine_scroll_manager_up();
	}
}

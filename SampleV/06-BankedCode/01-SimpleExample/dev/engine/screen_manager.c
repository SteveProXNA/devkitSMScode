#include "screen_manager.h"
#include "font_manager.h"
#include "input_manager.h"
#include "../banks/banked_code_1.h"
#include "../banks/banked_code_2.h"
#include "../banks/banked_code_3.h"

void engine_screen_manager_init()
{
	engine_font_manager_draw_text( "== BANKED CODE EXAMPLE ==", 4, 6 );
	engine_font_manager_draw_text( "PRESS LEFT, RIGHT OR DOWN", 4, 8 );
	engine_font_manager_draw_text( "PRESS FIRE1 TO CLEAR DATA", 4, 9 );
}

void engine_screen_manager_update()
{
	unsigned char input;
	unsigned char value;

	value = 0;
	input = engine_input_manager_hold_left();
	if( input )
	{
		value = banked_code_1();
		engine_font_manager_draw_data( value, 10, 12 );
		engine_font_manager_draw_text( "VALUE", 4, 12 );
	}

	input = engine_input_manager_hold_right();
	if( input )
	{
		value = banked_code_2();
		engine_font_manager_draw_data( value, 10, 13 );
		engine_font_manager_draw_text( "VALUE", 4, 13 );
	}

	input = engine_input_manager_hold_down();
	if( input )
	{
		value = banked_code_3();
		engine_font_manager_draw_data( value, 10, 14 );
		engine_font_manager_draw_text( "VALUE", 4, 14 );
	}

	input = engine_input_manager_hold_fire1();
	if( input )
	{
		engine_font_manager_draw_text( "       ", 4, 12 );
		engine_font_manager_draw_text( "       ", 4, 13 );
		engine_font_manager_draw_text( "       ", 4, 14 );
	}
	
}
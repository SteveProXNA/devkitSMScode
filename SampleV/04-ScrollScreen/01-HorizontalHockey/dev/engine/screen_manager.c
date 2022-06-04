#include "screen_manager.h"
#include "enum_manager.h"

#define MAX_SCREEENS		2

// Screens
#include "../screen/none_screen.h"
#include "../screen/test_screen.h"

static unsigned char curr_screen_type;
static unsigned char next_screen_type;

void engine_screen_manager_init( unsigned char open_screen_type )
{
	curr_screen_type = screen_type_none;
	next_screen_type = open_screen_type;
}

void engine_screen_manager_update()
{
	if( curr_screen_type != next_screen_type )
	{
		curr_screen_type = next_screen_type;
		switch( curr_screen_type )
		{
		case screen_type_none:
			screen_none_screen_load();
			break;
		case screen_type_test:
			screen_test_screen_load();
			break;
		}
	}

	switch( curr_screen_type )
	{
	case screen_type_none:
		screen_none_screen_update( &next_screen_type );
		break;
	case screen_type_test:
		screen_test_screen_update( &next_screen_type );
		break;
	}
}
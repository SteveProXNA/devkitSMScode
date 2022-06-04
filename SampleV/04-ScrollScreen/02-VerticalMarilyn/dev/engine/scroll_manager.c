#include "scroll_manager.h"
#include "../devkit/_sms_manager.h"
#include "../content/gfx.h"

// Global variable.
struct_scroll_object global_scroll_object;

// Methods.
void engine_scroll_manager_init()
{
	struct_scroll_object *so = &global_scroll_object;
	so->scroll = 0;
	so->height = 32 * 8 - 1;

	// 32 tiles * 2 bytes each 
	so->size = 32 * 2;
}

void engine_scroll_manager_up()
{
	struct_scroll_object *so = &global_scroll_object;
	unsigned int index;
	unsigned int y;

	if( so->scroll > 0 )
	{
		so->scroll--;
		devkit_SMS_setBGScrollY( so->scroll );

		if( ( so->scroll % 8 ) == 0 )
		{
			y = ( 27 + ( so->scroll / 8 ) ) % 28;
			index = ( ( so->scroll / 8 ) - 1 ) * 32 * 2;
			devkit_SMS_loadTileMap( 0, y, ( void * ) &MM__tilemap__bin[ index ], so->size );
		}
	}
}

void engine_scroll_manager_down()
{
	struct_scroll_object *so = &global_scroll_object;
	unsigned int index;
	unsigned int y;

	if( so->scroll < so->height )
	{
		so->scroll++;
		devkit_SMS_setBGScrollY( so->scroll );

		if( ( so->scroll % 8 ) == 0 )
		{
			y = ( 24 + ( so->scroll / 8 ) ) % 28;
			index = ( 24 + ( so->scroll / 8 ) ) * 32 * 2;
			devkit_SMS_loadTileMap( 0, y, ( void * ) &MM__tilemap__bin[ index ], so->size );  
		}
	}
}
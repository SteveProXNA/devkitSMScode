#include "tree_manager.h"
#include "enum_manager.h"
#include "tile_manager.h"
#include "../devkit/_sms_manager.h"
#include "../content/gfx.h"

static void draw( unsigned char x, unsigned char y );

void engine_tree_manager_draw()
{
	unsigned char tx = 0;
	unsigned char ty = 0;

	for( tx = 2; tx < 26; tx += 2 )
	{
		draw( tx, 0 );
		draw( tx, 22 );
	}

	for( ty = 2; ty < 22; ty += 2 )
	{
		draw( 2, ty );
		draw( 24, ty );
	}
}

static void draw( unsigned char x, unsigned char y )
{
	engine_tile_manager_draw_trees( tree_type_death, x, y );
}
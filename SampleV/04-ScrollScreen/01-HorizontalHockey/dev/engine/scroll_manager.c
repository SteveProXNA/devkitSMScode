#include "scroll_manager.h"
#include "content_manager.h"
#include "../devkit/_sms_manager.h"
#include "../content/gfx.h"
#include <stdlib.h>

// 400px wide / 8px tiles
unsigned int BG_TILE_WIDTH = 50;		// Hockey = 400 x 192	i.e. 50 x 8 tiles wide
unsigned int X_TILE_MAX = 32;
unsigned int Y_TILE_MAX = 24;

//static unsigned char delta = 1;
static unsigned int scroll = 0;
static unsigned int scrollDivided8 = 0;
static unsigned int scrollRight = 0;
static unsigned int scrollRightDivided8 = 0;
static unsigned int scrollWidth = 0;

void engine_scroll_manager_load()
{
	unsigned char *src = NULL;
	unsigned char ytile = 0;
	unsigned int index = 0;
	unsigned int size = 0;

	for( ytile = 0; ytile < Y_TILE_MAX; ytile++ )
	{
		// 32 tiles * 2 bytes each.
		index = BG_TILE_WIDTH * ytile * 2;
		src = ( void * ) &hockey__tilemap__bin[ index ];
		size = X_TILE_MAX * 2;

		devkit_SMS_loadTileMap( 0, ytile, src, size );
	}

	scrollWidth = BG_TILE_WIDTH - X_TILE_MAX;
}

void engine_scroll_manager_update_left( unsigned char delta )
{
	unsigned char *src = NULL;
	unsigned char ytile = 0;
	unsigned int index = 0;
	const unsigned int size = 2;

	unsigned int x = 0;
	unsigned char y = 0;

	if( scrollRight > 0 )
	{
		scroll += delta;
		scrollRight -= delta;
		scrollRightDivided8 = scrollRight / 8;
		devkit_SMS_setBGScrollX( scroll );

		if( ( scrollRight % 8 ) == 0 )
		{
			for( ytile = 1; ytile < Y_TILE_MAX; ytile++ )
			{
				// 1 tile * 2 bytes.
				x = X_TILE_MAX + scrollRightDivided8;
				y = ytile - 1;
				index = ( ( BG_TILE_WIDTH*ytile ) + scrollRightDivided8 ) * 2;
				src = ( void * ) &hockey__tilemap__bin[ index ];

				devkit_SMS_loadTileMap( x, y, src, size );
			}
		}
	}
}

void engine_scroll_manager_update_right( unsigned char delta )
{
	unsigned char *src = NULL;
	unsigned char ytile = 0;
	unsigned int index = 0;
	const unsigned int size = 2;

	unsigned int x = 0;
	unsigned char y = 0;

	if( scrollRightDivided8 < scrollWidth )
	{
		scroll -= delta;
		scrollRight += delta;
		scrollRightDivided8 = scrollRight / 8;
		devkit_SMS_setBGScrollX( scroll );

		if( ( scrollRight % 8 ) == delta )
		{
			for( ytile = 1; ytile < Y_TILE_MAX; ytile++ )
			{
				x = X_TILE_MAX + scrollRightDivided8;
				y = ytile - 1;
				index = ( ( BG_TILE_WIDTH*ytile ) + ( X_TILE_MAX + scrollRightDivided8 ) ) * 2;
				src = ( void * ) &hockey__tilemap__bin[ index ];

				devkit_SMS_loadTileMap( x, y, src, size );
			}
		}
	}
}
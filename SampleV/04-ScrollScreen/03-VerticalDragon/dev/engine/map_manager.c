#include "map_manager.h"
#include "global_manager.h"
#include "../devkit/_sms_manager.h"

// IMPORTANT disable compiler warning 158
#ifdef _CONSOLE
#else
	#pragma disable_warning 158
#endif

// Global variable.
struct_map_object global_map_object;

static void decompress_map_row( unsigned char *buffer );
static void draw_map_row();

void engine_map_manager_init( unsigned char *level_data )
{
	struct_map_object *map_data = &global_map_object;
	map_data->level_data = level_data;
	map_data->next_row = level_data;
	map_data->background_y = SCROLL_CHAR_H - 2;
	map_data->lines_before_next = 0;
	map_data->scroll_y = 0;
}

void engine_map_manager_draw_map_screen()
{
	struct_map_object *map_data = &global_map_object;
	map_data->background_y = SCREEN_CHAR_H - 2;

	while( map_data->background_y < SCREEN_CHAR_H )
	{
		draw_map_row();
	}

	draw_map_row();
}

void engine_map_manager_draw_map()
{
	struct_map_object *map_data = &global_map_object;
	unsigned char lines_before_next;
	unsigned char scroll_y;

	lines_before_next = map_data->lines_before_next;
	if( map_data->lines_before_next )
	{
		map_data->lines_before_next--;
	}
	else 
	{
		draw_map_row();
	}

	scroll_y = map_data->scroll_y;
	devkit_SMS_setBGScrollY( map_data->scroll_y );
	if( map_data->scroll_y ) 
	{
		map_data->scroll_y--;
	}
	else 
	{
		map_data->scroll_y = SCROLL_H - 1;
	}
	scroll_y = map_data->scroll_y;
}

static void draw_map_row()
{
	struct_map_object *map_data = &global_map_object;
	unsigned char i, j;
	unsigned char y;
	unsigned char *map_char;
	unsigned int base_tile, tile;
	unsigned char buffer[ 16 ];

	decompress_map_row( buffer );
	for( i = 2, y = map_data->background_y, base_tile = 256; i; i--, y++, base_tile++ ) 
	{
		devkit_SMS_setNextTileatXY( 0, y );
		for( j = 16, map_char = buffer; j; j--, map_char++ ) 
		{
			tile = base_tile + ( *map_char << 2 );
			devkit_SMS_setTile( tile );
			devkit_SMS_setTile( tile + 2 );
		}
	}

	//map_data->next_row += 16;
	if( *map_data->next_row == 0xFF ) 
	{
		// Reached the end of the map; reset
		map_data->next_row = map_data->level_data;
	}

	if( map_data->background_y ) 
	{
		map_data->background_y -= 2;
	}
	else
	{
		map_data->background_y = SCROLL_CHAR_H - 2;
	}

	map_data->lines_before_next = 15;
}

static void decompress_map_row( unsigned char *buffer )
{
	struct_map_object *map_data = &global_map_object;
	unsigned char *o, *d;
	unsigned char remaining, ch, repeat;

	unsigned char test;

	o = map_data->next_row;
	d = buffer;
	for( remaining = 16; remaining; ) 
	{
		ch = *o;
		o++;

		test = ch & 0x80;
		if( ch & 0x80 )
		{
			// Has repeat flag: repeat n times
			repeat = ch & 0x7F;
			ch = *o;
			o++;

			for( ; repeat && remaining; repeat--, remaining-- ) {
				*d = ch;
				d++;
			}
		}
		else
		{
			// Just use the char
			*d = ch;
			d++;
			remaining--;
		}
	}

	map_data->next_row = o;
}
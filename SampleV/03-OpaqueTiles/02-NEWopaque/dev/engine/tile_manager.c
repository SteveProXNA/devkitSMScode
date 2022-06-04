#include "tile_manager.h"
#include "tile_manager.h"
#include "../devkit/_sms_manager.h"
#include "../content/gfx.h"

#define BASE_TILES_OFFSET	26
#define BASE_BLOCK_OFFSET	12
#define BASE_CANDY_OFFSET	52

static void draw_tile( unsigned char offset, unsigned char x, unsigned char y );
static void draw_tile_priority( unsigned char offset, unsigned char x, unsigned char y );
static void comm_tile( const unsigned char *pnt, unsigned char offset, unsigned int priority, unsigned char x, unsigned char y );

void engine_tile_manager_draw_trees( unsigned char type, unsigned char x, unsigned char y )
{
	unsigned char offset = type * 2;
	draw_tile( offset, x, y );
}

void engine_tile_manager_draw_sides( unsigned char x, unsigned char y )
{
	unsigned char offset = BASE_BLOCK_OFFSET * 2 + BASE_CANDY_OFFSET;
	draw_tile_priority( offset, x, y );
}

static void draw_tile( unsigned char offset, unsigned char x, unsigned char y )
{
	const unsigned char priority = 0;
	comm_tile( game_tiles__tilemap__bin, offset, priority, x, y );
}

static void draw_tile_priority( unsigned char offset, unsigned char x, unsigned char y )
{
	unsigned int priority = devkit_TILE_PRIORITY() | devkit_TILE_USE_SPRITE_PALETTE();
	comm_tile( game_tiles__tilemap__bin, offset, priority, x, y );
}


static void comm_tile( const unsigned char *pnt, unsigned char offset, unsigned int priority, unsigned char x, unsigned char y )
{
	devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTile( ( *pnt + offset + 0 ) | priority );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTile( ( *pnt + offset + 1 ) | priority );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTile( ( *pnt + offset + BASE_TILES_OFFSET + 0 ) | priority );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTile( ( *pnt + offset + BASE_TILES_OFFSET + 1 ) | priority );
}
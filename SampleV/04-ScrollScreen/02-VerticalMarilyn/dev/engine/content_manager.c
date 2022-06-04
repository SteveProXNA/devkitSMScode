#include "content_manager.h"
#include "../devkit/_sms_manager.h"
#include "../content/gfx.h"

void engine_content_manager_load_bgtiles()
{
	// BGgame tiles.
	devkit_SMS_loadPSGaidencompressedTiles( ( unsigned char * ) MM__tiles__psgcompr, 0 );
	devkit_SMS_loadTileMap( 0, 0, ( void * ) MM__tilemap__bin, 32 * 25 * 2 );     // 32 tiles * 25 lines * 2 bytes each 
	devkit_SMS_loadBGPalette( ( void * ) MM__palette__bin );
}

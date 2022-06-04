#include "content_manager.h"
#include "../devkit/_sms_manager.h"
#include "../content/gfx.h"

#define FONT_TILES		0

void engine_content_manager_load_tiles()
{	
	// Font tiles.
	devkit_SMS_loadPSGaidencompressedTiles( ( unsigned char * ) font__tiles__psgcompr, FONT_TILES );
	devkit_SMS_loadBGPalette( ( void * ) font__palette__bin );
}

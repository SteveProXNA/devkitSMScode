#include "content_manager.h"
#include "../devkit/_sms_manager.h"
#include "../content/gfx.h"

void engine_content_manager_load_tiles()
{
	devkit_SMS_loadPSGaidencompressedTiles( hockey__tiles__psgcompr, 0 );
	devkit_SMS_loadBGPalette( ( void * ) hockey__palette__bin );
}
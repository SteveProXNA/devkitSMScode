#include "audio_manager.h"
#include "../object/audio_object.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"

static unsigned char music_bank;

// Sound.
void engine_audio_manager_sfx_play( unsigned char index )
{
	const unsigned char *data;
	unsigned char bank;

	data = sfx_object_data[ index ];
	bank = sfx_object_bank[ index ];
	devkit_SMS_mapROMBank( bank );
	devkit_PSGSFXPlay( ( unsigned char* ) data, devkit_SFX_CHANNEL2() );
}
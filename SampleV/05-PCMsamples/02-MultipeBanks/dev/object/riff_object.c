#include "riff_object.h"
#include "../banks/bank3.h"
#include "../banks/bank4.h"
#include "../banks/bank5.h"
#include "../banks/bank6.h"
#include "../banks/bank7.h"

const unsigned char *riff_sample_data[] =
{
	SoundFx_wav_pcmenc,
	Riff_1981_01_wav_pcmenc,
	Riff_1981_02_wav_pcmenc,
	Riff_1981_03_wav_pcmenc,
	Riff_1981_04_wav_pcmenc,
};

const unsigned char riff_sample_bank[] =
{
	SoundFx_wav_pcmenc_bank,
	Riff_1981_01_wav_pcmenc_bank,
	Riff_1981_02_wav_pcmenc_bank,
	Riff_1981_03_wav_pcmenc_bank,
	Riff_1981_04_wav_pcmenc_bank,
};

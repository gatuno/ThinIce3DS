#include <stdlib.h>
#include <stdio.h>
#include <3ds.h>
#include "sfx.h"
#include "filesystem.h"

bool soundEnabled;
int channel;

void initSound (void) {
	if(csndInit()==0)soundEnabled=true;
	else soundEnabled=false;
}

void freeSFX (SFX_s *s) {
	if (s->data) {
		linearFree (s->data);
		s->data = NULL;
	}
}

int loadSFX (SFX_s* s, const char* filename, u32 format) {
	if (!s) return -1;
	if (!soundEnabled) return -1;
	
	s->data = NULL;
	s->size = 0;

	s->data = bufferizeFile(filename, &s->size, true, true);
	s->format = format;
	if (!s->data) return -1;
	return 0;
}

void exitSound (void) {
	if (soundEnabled) csndExit();
}

void playSFX (SFX_s* s) {
	if (!s || !s->data || !soundEnabled) return;

	channel++;
	channel %= 8;

	// soundPlaySample(s->data, s->format, s->size, 22050, 127, 64, false, 0);
	csndPlaySound(channel+8, s->format, 44100, 1.0, 0.0, (u32*)s->data, (u32*)s->data, s->size);
}


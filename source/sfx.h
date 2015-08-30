#ifndef SFX_H
#define SFX_H

typedef struct {
	u8* data;
	u32 size;
	u32 format;
} SFX_s;

void initSound (void);
void freeSFX (SFX_s *s);
int loadSFX (SFX_s* s, const char* filename, u32 format);
void exitSound (void);
void playSFX (SFX_s* s);

#endif

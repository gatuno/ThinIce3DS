/*
 * thinice.c
 * This file is part of Thin Ice
 *
 * Copyright (C) 2015 - Félix Arreola Rodríguez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* ----------------
 * LEGAL NOTICE
 * ----------------
 *
 * This game is NOT related to Club Penguin in any way. Also,
 * this game is not intended to infringe copyrights, the graphics and
 * sounds used are Copyright of Disney.
 *
 * The new 3DS code is written by Gatuno, and is released under
 * the term of the GNU General Public License.
 */

#include <3ds.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tiles_bgra.h"

#define TILE_HEIGHT 24
#define TILE_WIDTH 24

#define TILE_MAP_WIDTH 528

#define FPS (268123480/12)

typedef struct SDL_Rect {
	s16 x, y;
	u16 w, h;
} SDL_Rect;

/* Enumerar cada uno de los Tiles */
enum {
	TILE_PORTAL_1,
	TILE_PORTAL_2,
	TILE_PORTAL_3,
	TILE_PORTAL_4,
	TILE_PORTAL_5,
	TILE_PORTAL_6,
	TILE_PORTAL_7,
	TILE_PORTAL_8,
	
	TILE_KEY_1,
	TILE_KEY_2,
	TILE_KEY_3,
	TILE_KEY_4,
	TILE_KEY_5,
	TILE_KEY_6,
	TILE_KEY_7,
	TILE_KEY_8,
	TILE_KEY_9,
	TILE_KEY_10,
	TILE_KEY_11,
	TILE_KEY_12,
	TILE_KEY_13,
	TILE_KEY_14,
	TILE_KEY_15,
	TILE_KEY_16,
	
	TILE_KEY_B_1,
	TILE_KEY_B_2,
	TILE_KEY_B_3,
	TILE_KEY_B_4,
	TILE_KEY_B_5,
	TILE_KEY_B_6,
	TILE_KEY_B_7,
	TILE_KEY_B_8,
	TILE_KEY_B_9,
	TILE_KEY_B_10,
	TILE_KEY_B_11,
	TILE_KEY_B_12,
	TILE_KEY_B_13,
	TILE_KEY_B_14,
	TILE_KEY_B_15,
	TILE_KEY_B_16,
	
	TILE_KEY_C_1,
	TILE_KEY_C_2,
	TILE_KEY_C_3,
	TILE_KEY_C_4,
	TILE_KEY_C_5,
	TILE_KEY_C_6,
	TILE_KEY_C_7,
	TILE_KEY_C_8,
	TILE_KEY_C_9,
	TILE_KEY_C_10,
	TILE_KEY_C_11,
	TILE_KEY_C_12,
	TILE_KEY_C_13,
	TILE_KEY_C_14,
	TILE_KEY_C_15,
	TILE_KEY_C_16,
	
	TILE_BAG,
	TILE_GOAL,
	TILE_EMPTY,
	TILE_ICE,
	TILE_BOXSPACE,
	TILE_DOBLE,
	TILE_PORTAL_EMPTY,
	TILE_LOCK,
	
	TILE_SWITCH_A,
	TILE_SWITCH_B,
	TILE_WALL,
	TILE_BLOCK,
	
	TILE_LOSE_1,
	TILE_LOSE_2,
	TILE_LOSE_3,
	TILE_LOSE_4,
	TILE_LOSE_5,
	TILE_LOSE_6,
	TILE_LOSE_7,
	TILE_LOSE_8,
	TILE_LOSE_9,
	TILE_LOSE_10,
	TILE_LOSE_11,
	TILE_LOSE_12,
	TILE_LOSE_13,
	TILE_LOSE_14,
	TILE_LOSE_15,
	TILE_LOSE_16,
	TILE_LOSE_17,
	TILE_LOSE_18,
	TILE_LOSE_19,
	TILE_LOSE_20,
	
	TILE_BLACK_NORMAL_1,
	TILE_BLACK_NORMAL_2,
	TILE_BLACK_NORMAL_3,
	TILE_BLACK_NORMAL_4,
	TILE_BLACK_NORMAL_5,
	TILE_BLACK_NORMAL_6,
	TILE_BLACK_NORMAL_7,
	
	TILE_BLACK_START_1,
	TILE_BLACK_START_2,
	TILE_BLACK_START_3,
	TILE_BLACK_START_4,
	TILE_BLACK_START_5,
	
	TILE_BLACK_OFF_1,
	TILE_BLACK_OFF_2,
	TILE_BLACK_OFF_3,
	TILE_BLACK_OFF_4,
	TILE_BLACK_OFF_5,
	TILE_BLACK_OFF_6,
	TILE_BLACK_OFF_7,
	TILE_BLACK_OFF_8,
	TILE_BLACK_OFF_9,
	TILE_BLACK_OFF_10,
	TILE_BLACK_OFF_11,
	TILE_BLACK_OFF_12,
	TILE_BLACK_OFF_13,
	TILE_BLACK_OFF_14,
	TILE_BLACK_OFF_15,
	TILE_BLACK_OFF_16,
	TILE_BLACK_OFF_17,
	TILE_BLACK_OFF_18,
	TILE_BLACK_OFF_19,
	TILE_BLACK_OFF_20,
	TILE_BLACK_OFF_21,
	TILE_BLACK_OFF_22,
	TILE_BLACK_OFF_23,
	TILE_BLACK_OFF_24,
	TILE_BLACK_OFF_25,
	TILE_BLACK_OFF_26,
	TILE_BLACK_OFF_27,
	TILE_BLACK_OFF_28,
	
	TILE_MELT_1,
	TILE_MELT_2,
	TILE_MELT_3,
	TILE_MELT_4,
	TILE_MELT_5,
	TILE_MELT_6,
	TILE_MELT_7,
	TILE_MELT_8,
	TILE_MELT_9,
	TILE_MELT_10,
	TILE_MELT_11,
	TILE_MELT_12,
	TILE_MELT_13,
	TILE_MELT_14,
	TILE_MELT_15,
	TILE_MELT_16,
	TILE_MELT_17,
	TILE_MELT_18,
	TILE_MELT_19,
	TILE_MELT_20,
	TILE_MELT_21,
	TILE_MELT_22,
	TILE_MELT_23,
	TILE_MELT_24,
	TILE_MELT_25,
	TILE_MELT_26,
	TILE_MELT_27,
	TILE_MELT_28,
	TILE_MELT_29,
	TILE_MELT_30,
	TILE_MELT_31,
	TILE_MELT_32,
	TILE_MELT_33,
	TILE_MELT_34,
	TILE_MELT_35,
	TILE_MELT_36,
	TILE_MELT_37,
	TILE_MELT_38,
	TILE_MELT_39,
	TILE_MELT_40,
	TILE_MELT_41,
	TILE_MELT_42,
	TILE_MELT_43,
	TILE_MELT_44,
	TILE_MELT_45
};

/* Codigos de salida */
enum {
	GAME_NONE = 0, /* No usado */
	GAME_CONTINUE,
	GAME_QUIT
};

/* Prototipos de función */
void setup (void);
int game_loop (void);

void copy_tile (gfxScreen_t screen, gfx3dSide_t side, SDL_Rect *rect, int tile) {
	u16 fbWidth, fbHeight;
	u16 xOffset, yOffset;
	u16 widthDrawn, heightDrawn;
	u8 *fbAdr, *fbd;
	const u8 *tile_data, *data;
	int j, i;
	u8 alpha;
	
	if (tiles_bgra == NULL) return;
	fbAdr = gfxGetFramebuffer (screen, side, &fbWidth, &fbHeight);
	
	if (rect->x + TILE_WIDTH < 0 || rect->x >= fbWidth) return;
	if (rect->y + TILE_HEIGHT < 0 || rect->y >= fbHeight) return;
	
	xOffset = yOffset = 0;
	widthDrawn = TILE_WIDTH;
	heightDrawn = TILE_HEIGHT;
	
	if (rect->x < 0) xOffset = -rect->x;
	if (rect->y < 0) yOffset = -rect->y;
	if (rect->x + TILE_WIDTH >= fbWidth) widthDrawn = fbWidth - rect->x;
	if (rect->y + TILE_HEIGHT >= fbHeight) heightDrawn = fbHeight - rect->y;
	widthDrawn -= xOffset;
	heightDrawn -= yOffset;
	
	//printf ("Offset: (%i, %i). Drawn: (%i, %i)\n", xOffset, yOffset, widthDrawn, heightDrawn);
	
	//printf ("Base: %p\n", tiles_bgra);
	fbAdr += (rect->y + yOffset) * fbWidth * 3;
	/* Calcular la y del tile */
	j = ((tile % 8) * TILE_HEIGHT) + yOffset;
	tile_data = tiles_bgra + (j * TILE_MAP_WIDTH * 4); /* Imagen ARGB */
	i = (21 - (tile / 8)) * TILE_WIDTH;
	//printf ("TILE: %i: Y, X de los tiles: %i, %i\n", tile, j, i);
	//printf ("Tile_data antes : %p\n", tile_data);
	tile_data += i * 4;
	//printf ("Tile_data after : %p\n", tile_data);
	
	for (j = yOffset; j < yOffset + heightDrawn; j++) {
		fbd = &fbAdr[(rect->x + xOffset) * 3];
		data = &tile_data[xOffset * 4]; /* La imagen es ABGR */
		//printf ("D: %p ", data);
		for (i = xOffset; i < xOffset + widthDrawn; i++, fbd += 3, data += 4) {
			alpha = data[3];
			if (alpha == 0) continue; /* 255 = Opaco, 0 = Trans */
			fbd[0] = ((data[0] * alpha) + (fbd[0] * (255 - alpha))) / 255;
			fbd[1] = ((data[1] * alpha) + (fbd[1] * (255 - alpha))) / 255;
			fbd[2] = ((data[2] * alpha) + (fbd[2] * (255 - alpha))) / 255;
		}
		fbAdr += fbWidth * 3;
		tile_data += TILE_MAP_WIDTH * 4;
		//printf ("D_t_d: %p. ", tile_data);
	}
}

int main (void) {
	
	setup ();
	
	do {
		//if (game_intro () == GAME_QUIT) break;
		if (game_loop () == GAME_QUIT) break;
	} while (1 == 0);
	
	gfxExit();
	hidExit();
	aptExit();
	srvExit();
	return 0;
}

int game_loop (void) {
	int done = 0;
	SDL_Rect rect;
	u64 last_time, now_time;
	int g, h;
	
	u32 keys;
	while (aptMainLoop () && !done) {
		last_time = svcGetSystemTick ();
		hidScanInput ();
		keys = hidKeysDown ();
		
		if (keys & KEY_START) {
			done = GAME_QUIT;
		}
		
		rect.x = 24;
		rect.y = 24;
		
		copy_tile (GFX_TOP, GFX_LEFT, &rect, TILE_KEY_1);
		
		rect.x = 0;
		rect.y = 24;
		
		copy_tile (GFX_TOP, GFX_LEFT, &rect, TILE_DOBLE);
		
		rect.x = 24;
		rect.y = 0;
		
		copy_tile (GFX_TOP, GFX_LEFT, &rect, TILE_WALL);
		
		rect.x = 0;
		rect.y = 0;
		
		copy_tile (GFX_TOP, GFX_LEFT, &rect, TILE_BLACK_START_1);
		
		//Wait for VBlank
		gspWaitForVBlank();
		
		gfxFlushBuffers();
		gfxSwapBuffers();
		
		now_time = svcGetSystemTick ();
		if (now_time < last_time + FPS) svcSleepThread (last_time + FPS - now_time);
	}
	
	done = 0;
	while (aptMainLoop () && !done) {
		last_time = svcGetSystemTick ();
		hidScanInput ();
		keys = hidKeysDown ();
		
		if (keys & KEY_START) {
			done = GAME_QUIT;
		}
		
		/*rect.x = 0;
		rect.y = 0;
		
		//Wait for VBlank
		gspWaitForVBlank();
		
		gfxFlushBuffers();
		gfxSwapBuffers();
		*/
		now_time = svcGetSystemTick ();
		if (now_time < last_time + FPS) svcSleepThread (last_time + FPS - now_time);
	}
	return done;
}

void setup (void) {
	/* Inicializar 3DS */
	srvInit();
	aptInit();
	hidInit(NULL);
	gfxInitDefault();
	gfxSet3D(0);
	gfxSetDoubleBuffering (GFX_BOTTOM, 1);
	
	consoleInit(GFX_BOTTOM, NULL);
}

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

#include "mapa1.h"
#include "mapa2.h"
#include "mapa3.h"
#include "mapa4.h"
#include "mapa5.h"
#include "mapa6.h"
#include "mapa7.h"
#include "mapa8.h"
#include "mapa9.h"
#include "mapa10.h"
#include "mapa11.h"
#include "mapa12.h"
#include "mapa13.h"
#include "mapa14.h"
#include "mapa15.h"
#include "mapa16.h"
#include "mapa17.h"
#include "mapa18.h"
#include "mapa19.h"

#include "tiles_bgra.h"

#define TILE_HEIGHT 24
#define TILE_WIDTH 24

#define TILE_MAP_WIDTH 528

#define FPS (268123480/6)

#define RANDOM(x) ((int) (x ## .0 * rand () / (RAND_MAX + 1.0)))

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE !FALSE
#endif

#define TILE_HEIGHT 24
#define TILE_WIDTH 24

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

static int tiles_frames [] = {
	1, /* 0 => 1 Portal normal */
	2, 3, /* 1 => 2, 2 => 3 */
	4, 5, /* 3 => 4, 4 => 5 */
	6, 7, /* 5 => 6, 6 => 7 */
	8, 9, /* 7 => 8, 8 => 9 */
	10, 11, 12, /* 9 => 10, 10 => 11, 11 => 12 */
	13, 14, 15, /* 12 => 13, 13 => 14, 14 => 15 */
	16, 17, 18, /* 15 => 16, 16 => 17, 17 => 18 */
	19, 20, 1,  /* 18 => 19, 19 => 20, 20 => 1 */
	
	22, /* 21 => 22 Portal Rapido */
	23, /* 22 => 23 */
	24, /* 23 => 24 */
	25, /* 24 => 25 */
	22, /* 25 => 22 */
	
	27, /* 26 => 27 Llave */
	28, 29, /* 27 => 28, 28 => 29 */
	30, 31, /* 29 => 30, 30 => 31 */
	32, 33, /* 31 => 32, 32 => 33 */
	34, 35, /* 33 => 34, 34 => 35 */
	36, 37, /* 35 => 36, 36 => 37 */
	38, 39, /* 37 => 38, 38 => 39 */
	40, 41, /* 39 => 40, 40 => 41 */
	42, 43, /* 41 => 42, 42 => 43 */
	44, 45, /* 43 => 44, 44 => 45 */
	46, 47, /* 45 => 46, 46 => 47 */
	48, 49, /* 47 => 48, 48 => 49 */
	50, 51, /* 49 => 50, 50 => 51 */
	52, 53, /* 51 => 52, 52 => 53 */
	54, 55, /* 53 => 54, 54 => 55 */
	56, 57, /* 55 => 56, 56 => 57 */
	58, 27, /* 57 => 58, 58 => 27 */
	
	59, /* 59 => 59, Goal */
	60, /* 60 => 60, Vacio */
	61, /* 61 => 61, Hielo */
	62, /* 62 => 62, Espacio para la caja */
	63, /* 63 => 63, Hielo doble */
	64, /* 64 => 64, Portal inactivo */
	65, /* 65 => 65, Candado */
	66, /* 66 => 66, Boton 1 */
	67, /* 67 => 67, Boton utilizado */
	68, /* 68 => 68, Muro */
	69, /* 69 => 69, Bloque */
	70, /* 70 => 70, Bolsa de dinero */
	
	/* Hielo derriendose, Agua moviendo */
	72, 73, 74, 75,
	76, 77, 78, 79, 80,
	81, 82, 83, 84, 85,
	86, 87, 88, 89, 90,
	91, 92, 93, 94, 95,
	96, 97, 98, 99, 100,
	101, 102, 103, 104, 105,
	106, 107, 108, 109, 110,
	111, 112, 113, 114, 115,
	116, 78,
	
	/* Torbellino */
	118, 119, 120, 121, 122,
	123, 124, 125, 126, 127, 128, 129, 130,
	131, 132, 133, 134, 135, 136, 137, 119,
	
	/* Llave 2 */
	139,
	140, 141, 142, 143,
	144, 145, 146, 147,
	148, 149, 150, 151,
	152, 153, 154, 155,
	156, 157, 158, 159,
	160, 161, 162, 163,
	164, 165, 166, 167,
	168, 169, 170, 139,
	
	/* Llave 3 */
	172,
	173, 174, 175, 176,
	177, 178, 179, 180,
	181, 182, 183, 184,
	185, 186, 187, 188,
	189, 190, 191, 192,
	193, 194, 195, 196,
	197, 198, 199, 200,
	201, 202, 203, 172
};


static int tiles_outputs [] = {
	TILE_PORTAL_1,
	TILE_PORTAL_1, TILE_PORTAL_1,
	TILE_PORTAL_2, TILE_PORTAL_2,
	TILE_PORTAL_3, TILE_PORTAL_3,
	TILE_PORTAL_4, TILE_PORTAL_4,
	TILE_PORTAL_1, TILE_PORTAL_1, TILE_PORTAL_1,
	TILE_PORTAL_2, TILE_PORTAL_2, TILE_PORTAL_2,
	TILE_PORTAL_3, TILE_PORTAL_3, TILE_PORTAL_3,
	TILE_PORTAL_4, TILE_PORTAL_4, TILE_PORTAL_4,
	
	TILE_PORTAL_5,
	TILE_PORTAL_5,
	TILE_PORTAL_6,
	TILE_PORTAL_7,
	TILE_PORTAL_8,
	
	TILE_KEY_1,
	TILE_KEY_1, TILE_KEY_1,
	TILE_KEY_2, TILE_KEY_2,
	TILE_KEY_3, TILE_KEY_3,
	TILE_KEY_4, TILE_KEY_4,
	TILE_KEY_5, TILE_KEY_5,
	TILE_KEY_6, TILE_KEY_6,
	TILE_KEY_7, TILE_KEY_7,
	TILE_KEY_8, TILE_KEY_8,
	TILE_KEY_9, TILE_KEY_9,
	TILE_KEY_10, TILE_KEY_10,
	TILE_KEY_11, TILE_KEY_11,
	TILE_KEY_12, TILE_KEY_12,
	TILE_KEY_13, TILE_KEY_13,
	TILE_KEY_14, TILE_KEY_14,
	TILE_KEY_15, TILE_KEY_15,
	TILE_KEY_16, TILE_KEY_16,
	
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
	TILE_BAG,
	
	TILE_MELT_1,
	TILE_MELT_1, TILE_MELT_2, TILE_MELT_3, TILE_MELT_4, TILE_MELT_5,
	TILE_MELT_6, TILE_MELT_7, TILE_MELT_8, TILE_MELT_9, TILE_MELT_10,
	TILE_MELT_11, TILE_MELT_12, TILE_MELT_13, TILE_MELT_14, TILE_MELT_15,
	TILE_MELT_16, TILE_MELT_17, TILE_MELT_18, TILE_MELT_19, TILE_MELT_20,
	TILE_MELT_21, TILE_MELT_22, TILE_MELT_23, TILE_MELT_24, TILE_MELT_25,
	TILE_MELT_26, TILE_MELT_27, TILE_MELT_28, TILE_MELT_29, TILE_MELT_30,
	TILE_MELT_31, TILE_MELT_32, TILE_MELT_33, TILE_MELT_34, TILE_MELT_35,
	TILE_MELT_36, TILE_MELT_37, TILE_MELT_38, TILE_MELT_39, TILE_MELT_40,
	TILE_MELT_41, TILE_MELT_42, TILE_MELT_43, TILE_MELT_44, TILE_MELT_45,
	
	TILE_LOSE_1,
	TILE_LOSE_1, TILE_LOSE_2, TILE_LOSE_3, TILE_LOSE_4,
	TILE_LOSE_5, TILE_LOSE_6, TILE_LOSE_7, TILE_LOSE_8,
	TILE_LOSE_9, TILE_LOSE_10, TILE_LOSE_11, TILE_LOSE_12,
	TILE_LOSE_13, TILE_LOSE_14, TILE_LOSE_15, TILE_LOSE_16,
	TILE_LOSE_17, TILE_LOSE_18, TILE_LOSE_19, TILE_LOSE_20,
	
	TILE_KEY_B_1,
	TILE_KEY_B_1, TILE_KEY_B_1,
	TILE_KEY_B_2, TILE_KEY_B_2,
	TILE_KEY_B_3, TILE_KEY_B_3,
	TILE_KEY_B_4, TILE_KEY_B_4,
	TILE_KEY_B_5, TILE_KEY_B_5,
	TILE_KEY_B_6, TILE_KEY_B_6,
	TILE_KEY_B_7, TILE_KEY_B_7,
	TILE_KEY_B_8, TILE_KEY_B_8,
	TILE_KEY_B_9, TILE_KEY_B_9,
	TILE_KEY_B_10, TILE_KEY_B_10,
	TILE_KEY_B_11, TILE_KEY_B_11,
	TILE_KEY_B_12, TILE_KEY_B_12,
	TILE_KEY_B_13, TILE_KEY_B_13,
	TILE_KEY_B_14, TILE_KEY_B_14,
	TILE_KEY_B_15, TILE_KEY_B_15,
	TILE_KEY_B_16, TILE_KEY_B_16,
	
	TILE_KEY_C_1,
	TILE_KEY_C_1, TILE_KEY_C_1,
	TILE_KEY_C_2, TILE_KEY_C_2,
	TILE_KEY_C_3, TILE_KEY_C_3,
	TILE_KEY_C_4, TILE_KEY_C_4,
	TILE_KEY_C_5, TILE_KEY_C_5,
	TILE_KEY_C_6, TILE_KEY_C_6,
	TILE_KEY_C_7, TILE_KEY_C_7,
	TILE_KEY_C_8, TILE_KEY_C_8,
	TILE_KEY_C_9, TILE_KEY_C_9,
	TILE_KEY_C_10, TILE_KEY_C_10,
	TILE_KEY_C_11, TILE_KEY_C_11,
	TILE_KEY_C_12, TILE_KEY_C_12,
	TILE_KEY_C_13, TILE_KEY_C_13,
	TILE_KEY_C_14, TILE_KEY_C_14,
	TILE_KEY_C_15, TILE_KEY_C_15,
	TILE_KEY_C_16, TILE_KEY_C_16
};

static int tiles_start [] = {
	-1,
	60,
	61,
	62,
	63,
	59,
	26,
	70,
	138,
	171,
	69,
	64,
	117,
	68,
	66,
	67,
	0,
	21,
	-1,
	-1,
	68,
	65,
	71
};

enum {
	PLAYER_NORMAL = 0,
	PLAYER_IGNITE,
	PLAYER_DROWN,
	NUM_PLAYER_STATES
};

static int player_frames [] = {
	1,    /* Jugador normal 0 => 1 */
	2, 3, /* 1 => 2, 2 => 3 */
	4, 5, /* 3 => 4, 4 => 5 */
	6, 7, /* 5 => 6, 6 => 7 */
	8, 9, /* 7 => 8, 8 => 9 */
	10, 11, /*  9 => 10, 10 => 11 */
	12, 13, /* 11 => 12, 12 => 13 */
	
	14, 15,
	16, 17,
	18, 19,
	20, 21,
	
	22, 23,
	24, 25,
	26, 27,
	
	28, 29,
	30, 31,
	32, 33,
	
	34, 35,
	36, 37,
	38, 39,
	
	40, 41,
	42, 43,
	44, 45,
	
	46, 47,
	48, 49,
	50,  1,
	
	52, /* Jugador prendiendo fuego 51 => 52 */
	53, 54, 55, 56,
	57, 58,
	59, 60,
	61, 62,
	63,  1,
	
	65,
	66, 67, 68, 69,
	70, 71, 72, 73,
	74, 75, 76, 77,
	78, 79, 80, 81,
	82, 83, 84, 85,
	86, 87, 88, 89,
	90, 91, 92, 92
};

static int player_outputs [] = {
	TILE_BLACK_NORMAL_1,
	TILE_BLACK_NORMAL_1, TILE_BLACK_NORMAL_1,
	TILE_BLACK_NORMAL_2, TILE_BLACK_NORMAL_2,
	TILE_BLACK_NORMAL_3, TILE_BLACK_NORMAL_3,
	TILE_BLACK_NORMAL_1, TILE_BLACK_NORMAL_1,
	TILE_BLACK_NORMAL_2, TILE_BLACK_NORMAL_2,
	TILE_BLACK_NORMAL_3, TILE_BLACK_NORMAL_3,
	
	TILE_BLACK_NORMAL_4, TILE_BLACK_NORMAL_4,
	TILE_BLACK_NORMAL_5, TILE_BLACK_NORMAL_5,
	TILE_BLACK_NORMAL_6, TILE_BLACK_NORMAL_6,
	TILE_BLACK_NORMAL_7, TILE_BLACK_NORMAL_7,
	
	TILE_BLACK_NORMAL_1, TILE_BLACK_NORMAL_1,
	TILE_BLACK_NORMAL_2, TILE_BLACK_NORMAL_2,
	TILE_BLACK_NORMAL_3, TILE_BLACK_NORMAL_3,
	TILE_BLACK_NORMAL_1, TILE_BLACK_NORMAL_1,
	TILE_BLACK_NORMAL_2, TILE_BLACK_NORMAL_2,
	TILE_BLACK_NORMAL_3, TILE_BLACK_NORMAL_3,
	TILE_BLACK_NORMAL_1, TILE_BLACK_NORMAL_1,
	TILE_BLACK_NORMAL_2, TILE_BLACK_NORMAL_2,
	TILE_BLACK_NORMAL_3, TILE_BLACK_NORMAL_3,
	TILE_BLACK_NORMAL_1, TILE_BLACK_NORMAL_1,
	TILE_BLACK_NORMAL_2, TILE_BLACK_NORMAL_2,
	TILE_BLACK_NORMAL_3, TILE_BLACK_NORMAL_3,
	TILE_BLACK_NORMAL_1, TILE_BLACK_NORMAL_1,
	TILE_BLACK_NORMAL_2, TILE_BLACK_NORMAL_2,
	TILE_BLACK_NORMAL_3, TILE_BLACK_NORMAL_3,
	
	TILE_BLACK_START_1,
	TILE_BLACK_START_1, TILE_BLACK_START_1,
	TILE_BLACK_START_1, TILE_BLACK_START_1,
	TILE_BLACK_START_2, TILE_BLACK_START_2,
	TILE_BLACK_START_3, TILE_BLACK_START_3,
	TILE_BLACK_START_4, TILE_BLACK_START_4,
	TILE_BLACK_START_5, TILE_BLACK_START_5,
	
	TILE_BLACK_OFF_1,
	TILE_BLACK_OFF_1, TILE_BLACK_OFF_2, TILE_BLACK_OFF_3, TILE_BLACK_OFF_4,
	TILE_BLACK_OFF_5, TILE_BLACK_OFF_6, TILE_BLACK_OFF_7, TILE_BLACK_OFF_8,
	TILE_BLACK_OFF_9, TILE_BLACK_OFF_10, TILE_BLACK_OFF_11, TILE_BLACK_OFF_12,
	TILE_BLACK_OFF_13, TILE_BLACK_OFF_14, TILE_BLACK_OFF_15, TILE_BLACK_OFF_16,
	TILE_BLACK_OFF_17, TILE_BLACK_OFF_18, TILE_BLACK_OFF_19, TILE_BLACK_OFF_20,
	TILE_BLACK_OFF_21, TILE_BLACK_OFF_22, TILE_BLACK_OFF_23, TILE_BLACK_OFF_24,
	TILE_BLACK_OFF_25, TILE_BLACK_OFF_26, TILE_BLACK_OFF_27, TILE_BLACK_OFF_28
};

static int player_start [NUM_PLAYER_STATES] = {
	0,
	51,
	64
};

/* Codigos de salida */
enum {
	GAME_NONE = 0, /* No usado */
	GAME_CONTINUE,
	GAME_QUIT
};

enum {
	UP = 0x01,
	DOWN = 0x02,
	LEFT = 0x04,
	RIGHT = 0x08
};

/* Estructuras */
typedef struct {
	int x, y;
} Punto;

typedef struct {
	int x, y;
	int *frame;
} Warp;

/* Prototipos de función */
void setup (void);
int game_loop (void);
void load_map (int nivel, int (*mapa)[19], int (*frames)[19], int *goal, int r, int last_solved, Warp *warps, Punto *movible, int *warp_enable, SDL_Rect *map_size);
void area_secreta (int (*mapa)[19], int (*frames)[19], int solved_stages);

/* Globales */
int first_try_count, solved_stages, save_bonus_point, save_tiles_flipped, score, timepoints = 0;

void copy_tile (gfxScreen_t screen, gfx3dSide_t side, Punto *rect, int tile) {
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
	int last_key;
	
	int tiles_flipped, snow_melted, save_snow_melted;
	int bonus_point, solved_points;
	int tries, first_try_points;
	int tally;
	
	int mapa[15][19];
	int frames[15][19];
	int movibles_hechos[7] = {0, 0, 0, 0, 0, 0, 0};
	int movibles = 0;
	int nivel = 1;
	int puffle_frame;
	int player_moving, slide_moving;
	int wall_up, wall_down, wall_left, wall_right;
	int movible_wall_up, movible_wall_down, movible_wall_left, movible_wall_right;
	int *tile_up, *tile_down, *tile_left, *tile_right, *tile_actual;
	int llave;
	int goal;
	int player_die;
	int random = RANDOM (2);
	int last_solved = FALSE;
	int warp_enable = FALSE;
	int warp_wall = FALSE;
	int slide_block;
	Punto player, save_player, next_player, movible, old_movible;
	Punto abc;
	Warp warps[2];
	int sub_scroll_x, sub_scroll_y;
	
	Punto scroll;
	SDL_Rect map_size;
	int arcade_button_left = 0, arcade_button_right = 0, arcade_button_up = 0, arcade_button_down = 0;
	
	tiles_flipped = save_tiles_flipped = snow_melted = save_snow_melted = 0;
	solved_points = bonus_point = save_bonus_point = solved_stages = 0;
	first_try_points = first_try_count = 0;
	tries = 1;
	
	puffle_frame = player_start[PLAYER_IGNITE];
	player_moving = slide_moving = 0;
	wall_up = wall_down = wall_left = wall_right = FALSE;
	movible_wall_up = movible_wall_down = movible_wall_left = movible_wall_right = FALSE;
	slide_block = llave = 0;
	player_die = FALSE;
	last_key = 0;
	score = tally = 0;
	
	player.x = save_player.x = 14;
	player.y = save_player.y = 10;
	
	//scroll.x = scroll.y = 0;
	
	load_map (nivel, mapa, frames, &goal, random, FALSE, warps, &movible, &warp_enable, &map_size);
	scroll.x = mapa_1_min_mapx;
	scroll.y = mapa_1_min_mapy;
	int slow = FALSE;
	while (aptMainLoop () && !done) {
		last_time = svcGetSystemTick ();
		hidScanInput ();
		keys = hidKeysDown ();
		
		if (keys & KEY_START) {
			done = GAME_QUIT;
		} else if (keys & KEY_UP) {
			last_key |= UP;
		} else if (keys & KEY_DOWN) {
			last_key |= DOWN;
		} else if (keys & KEY_LEFT) {
			last_key |= LEFT;
		} else if (keys & KEY_RIGHT) {
			last_key |= RIGHT;
		} else if (keys & KEY_A) {
			slow = !slow;
		}
		
		keys = hidKeysUp ();
		
		if (keys & KEY_UP) {
			last_key &= ~UP;
		} else if (keys & KEY_DOWN) {
			last_key &= ~DOWN;
		} else if (keys & KEY_LEFT) {
			last_key &= ~LEFT;
		} else if (keys & KEY_RIGHT) {
			last_key &= ~RIGHT;
		}
		
		tile_actual = &mapa[player.y][player.x];
		tile_up = &mapa[player.y - 1][player.x];
		tile_down = &mapa[player.y + 1][player.x];
		tile_left = &mapa[player.y][player.x - 1];
		tile_right = &mapa[player.y][player.x + 1];
		
		if (*tile_up >= 20) {
			wall_up = TRUE;
			
			if (*tile_up == 21 && llave > 0) {
				/* Convertir la puerta a hielo */
				llave--;
				mapa[player.y - 1][player.x] = 2;
				frames[player.y - 1][player.x] = tiles_start[2];
				//if (use_sound) Mix_PlayChannel (-1, sounds[SND_KEY], 0);
				wall_up = FALSE;
			}
		} else if (movible.y + 1 == player.y && movible.x == player.x && movible_wall_up) {
			wall_up = TRUE;
		} else {
			wall_up = FALSE;
		}
		
		if (*tile_down >= 20) {
			wall_down = TRUE;
			
			if (*tile_down == 21 && llave > 0) {
				/* Convertir la puerta a hielo */
				llave--;
				mapa[player.y + 1][player.x] = 2;
				frames[player.y + 1][player.x] = tiles_start[2];
				//if (use_sound) Mix_PlayChannel (-1, sounds[SND_KEY], 0);
				wall_down = FALSE;
			}
		} else if (movible.y - 1 == player.y && movible.x == player.x && movible_wall_down) {
			wall_down = TRUE;
		} else {
			wall_down = FALSE;
		}
		
		if (*tile_left >= 20) {
			wall_left = TRUE;
			
			if (*tile_left == 21 && llave > 0) {
				/* Convertir la puerta a hielo */
				llave--;
				mapa[player.y][player.x - 1] = 2;
				frames[player.y][player.x - 1] = tiles_start[2];
				//if (use_sound) Mix_PlayChannel (-1, sounds[SND_KEY], 0);
				wall_left = FALSE;
			}
		} else if (movible.y == player.y && movible.x + 1 == player.x && movible_wall_left) {
			wall_left = TRUE;
		} else {
			wall_left = FALSE;
		}
		
		if (*tile_right >= 20) {
			wall_right = TRUE;
			
			if (*tile_right == 21 && llave > 0) {
				/* Convertir la puerta a hielo */
				llave--;
				mapa[player.y][player.x + 1] = 2;
				frames[player.y][player.x + 1] = tiles_start[2];
				//if (use_sound) Mix_PlayChannel (-1, sounds[SND_KEY], 0);
				wall_right = FALSE;
			}
		} else if (movible.y == player.y && movible.x - 1 == player.x && movible_wall_right) {
			wall_right = TRUE;
		} else {
			wall_right = FALSE;
		}
		
		if (warps[0].x == player.x && warps[0].y == player.y && warp_enable && player_moving == 0) {
			//if (use_sound) Mix_PlayChannel (-1, sounds[SND_WARP], 0);
			wall_up = wall_down = wall_left = wall_right = TRUE;
			player.x = warps[1].x;
			player.y = warps[1].y;
			*warps[0].frame = tiles_start [11];
			*warps[1].frame = tiles_start [11];
			warp_enable = FALSE;
			warp_wall = FALSE;
		} else if (warps[1].x == player.x && warps[1].y == player.y && warp_enable && player_moving == 0) {
			//if (use_sound) Mix_PlayChannel (-1, sounds[SND_WARP], 0);
			wall_up = wall_down = wall_left = wall_right = TRUE;
			player.x = warps[0].x;
			player.y = warps[0].y;
			*warps[0].frame = tiles_start [11];
			*warps[1].frame = tiles_start [11];
			warp_enable = FALSE;
			warp_wall = FALSE;
		} else if (wall_up && wall_down && wall_left && wall_right && player_moving == 0 && *tile_actual != 5 && !player_die) {
			// Matar al puffle
			puffle_frame = player_start[PLAYER_DROWN];
			player_die = TRUE;
			//if (use_sound) Mix_PlayChannel (-1, sounds[SND_DROWN], 0);
			mapa[player.y][player.x] = 12;
			frames[player.y][player.x] = tiles_start[12];
		}
		
		/* Verificar colisiones de la caja */
		if (mapa[movible.y - 1][movible.x] >= 20) {
			movible_wall_up = TRUE;
		} else {
			movible_wall_up = FALSE;
		}
		
		if (mapa[movible.y + 1][movible.x] >= 20) {
			movible_wall_down = TRUE;
		} else {
			movible_wall_down = FALSE;
		}
		
		if (mapa[movible.y][movible.x - 1] >= 20) {
			movible_wall_left = TRUE;
		} else {
			movible_wall_left = FALSE;
		}
		
		if (mapa[movible.y][movible.x + 1] >= 20) {
			movible_wall_right = TRUE;
		} else {
			movible_wall_right = FALSE;
		}
		
		if (warp_enable) {
			if (*tile_up == 11 || *tile_down == 11 || *tile_left == 11 || *tile_right == 11) {
				if (*warps[0].frame < 22) {
					frames[warps[0].y][warps[0].x] = tiles_start[17];
					frames[warps[1].y][warps[1].x] = tiles_start[17];
				}
			} else {
				if (*warps[0].frame > 21) {
					frames[warps[0].y][warps[0].x] = tiles_start[16];
					frames[warps[1].y][warps[1].x] = tiles_start[16];
				}
			}
		}
		
		if (*tile_actual == 7) { /* Bolsa de dinero */
			mapa[player.y][player.x] = 2;
			frames[player.y][player.x] = tiles_start[2];
			bonus_point++;
			
			//if (use_sound) Mix_PlayChannel (-1, sounds[SND_MONEY], 0);
			
			/*int suma_bolsas = save_bonus_point + bonus_point;
			if (suma_bolsas == 1) {
				earn_stamp (c, 63);
			} else if (suma_bolsas == 3) {
				earn_stamp (c, 64);
			} else if (suma_bolsas == 6) {
				earn_stamp (c, 65);
			} else if (suma_bolsas == 10) {
				earn_stamp (c, 67);
			} else if (suma_bolsas == 33) {
				earn_stamp (c, 70);
			}*/
		} else if (*tile_actual == 8) {
			mapa[player.y][player.x] = 3;
			frames[player.y][player.x] = tiles_start[3];
			llave++;
			//if (use_sound) Mix_PlayChannel (-1, sounds[SND_KEY], 0);
		} else if (*tile_actual == 9) {
			mapa[player.y][player.x] = 4;
			frames[player.y][player.x] = tiles_start[4];
			llave++;
			//if (use_sound) Mix_PlayChannel (-1, sounds[SND_KEY], 0);
		} else if (*tile_actual == 6) {
			mapa[player.y][player.x] = 2;
			frames[player.y][player.x] = tiles_start[2];
			llave++;
			//if (use_sound) Mix_PlayChannel (-1, sounds[SND_KEY], 0);
		} else if (*tile_actual == 5 && player_moving == 0 && nivel < 20) {
			save_player.x = player.x;
			save_player.y = player.y;
			nivel++;
			
			/* Actualizar el nivel */
			//sprintf (buf, "%i", nivel);
			
			if (tiles_flipped == goal) {
				solved_points += tiles_flipped;
				last_solved = TRUE;
				solved_stages++;
				//sprintf (buf, "%i", solved_stages);
				
				/* Actualizar la cantidad de stages resueltos */
				
				//if (nivel != 19) if (use_sound) Mix_PlayChannel (-1, sounds[SND_COMPLETE], 0);
				if (tries == 1) {
					first_try_points += tiles_flipped;
					first_try_count++;
				}
			} else {
				last_solved = FALSE;
			}
			
			if (solved_stages == 19) {
				//timepoints = ((SDL_GetTicks () - timer) / 1000) * 6;
				//earn_stamp (c, 71);
			}
			
			save_tiles_flipped += tiles_flipped;
			tiles_flipped = 0;
			save_snow_melted += snow_melted;
			snow_melted = 0;
			save_bonus_point += bonus_point;
			bonus_point = 0;
			slide_block = 0;
			random = RANDOM(2);
			tries = 1;
			if (nivel != 20) {
				load_map (nivel, mapa, frames, &goal, random, last_solved, warps, &movible, &warp_enable, &map_size);
				warp_wall = warp_enable;
			} else {
				/* Poner en blanco la pantalla y salir del gameloop */
				score = tiles_flipped + save_tiles_flipped + solved_points + (bonus_point * 100) + save_bonus_point * 100 + first_try_points + timepoints;
				return GAME_CONTINUE;
			}
			
			/* Actualizar los tiles flipped */
			//text = TTF_RenderUTF8_Blended (ttf13_burbank_bold, "0", azul);
			
			/* Actualizar el texto del goal */
			//sprintf (buf, "%i", goal);
		} else if (*tile_actual == 14) {
			area_secreta (mapa, frames, solved_stages);
			//if (use_sound) Mix_PlayChannel (-1, sounds[SND_WARP], 0);
			//earn_stamp (c, 66);
		}
		
		if (player_moving == 0) {
			if (last_key & DOWN && !wall_down) {
				next_player.y = player.y + 1;
				next_player.x = player.x;
				player_moving = 3;
				
				/* Empujar el bloque */
				if (movible.x == player.x && movible.y - 1 == player.y && !movible_wall_down && slide_block == 0) {
					/* Empujar el bloque hacia abajo */
					slide_block = DOWN;
					//if (use_sound) Mix_PlayChannel (-1, sounds[SND_MOVE], 0);
				}
			} else if (last_key & UP && !wall_up) {
				next_player.y = player.y - 1;
				next_player.x = player.x;
				player_moving = 3;
				
				/* Empujar el bloque */
				if (movible.x == player.x && movible.y + 1 == player.y && !movible_wall_up && slide_block == 0) {
					/* Empujar el bloque hacia arriba */
					slide_block = UP;
					//if (use_sound) Mix_PlayChannel (-1, sounds[SND_MOVE], 0);
				}
			} else if (last_key & LEFT && !wall_left) {
				next_player.y = player.y;
				next_player.x = player.x - 1;
				player_moving = 3;
				
				/* Empujar el bloque */
				if (movible.x + 1 == player.x && movible.y == player.y && !movible_wall_left && slide_block == 0) {
					/* Empujar el bloque hacia arriba */
					slide_block = LEFT;
					//if (use_sound) Mix_PlayChannel (-1, sounds[SND_MOVE], 0);
				}
			} else if (last_key & RIGHT && !wall_right) {
				next_player.y = player.y;
				next_player.x = player.x + 1;
				player_moving = 3;
				
				/* Empujar el bloque */
				if (movible.x - 1 == player.x && movible.y == player.y && !movible_wall_right && slide_block == 0) {
					/* Empujar el bloque hacia arriba */
					slide_block = RIGHT;
					//if (use_sound) Mix_PlayChannel (-1, sounds[SND_MOVE], 0);
				}
			}
			
			if (player_moving != 0) {
				if (*tile_actual == 2) {
					mapa[player.y][player.x] = 22;
					frames[player.y][player.x] = tiles_start [22];
					tiles_flipped++;
					snow_melted++;
					//if (use_sound) Mix_PlayChannel (0, sounds[SND_ICE], 0);
					/*if (save_snow_melted + snow_melted == 480) {
						earn_stamp (c, 68);
					}*/
					
					/* Actualizar los tiles flipped */
					//sprintf (buf, "%i", tiles_flipped);
				} else if (*tile_actual == 4) {
					mapa[player.y][player.x] = 2;
					frames[player.y][player.x] = tiles_start [2];
					tiles_flipped++;
					//if (use_sound) Mix_PlayChannel (0, sounds[SND_DOUBLE_ICE], 0);
					
					/* Actualizar los tiles flipped */
					//sprintf (buf, "%i", tiles_flipped);
				}
			}
		}
		
		if (player_moving > 0 && (next_player.x - scroll.x < 0 || next_player.y - scroll.y < 0 || next_player.y - scroll.y >= 9 || next_player.x - scroll.x >= 15)) {
			sub_scroll_x = (player.x - next_player.x) * 8 * (4 - player_moving);
			sub_scroll_y = (player.y - next_player.y) * 8 * (4 - player_moving);
			//printf ("Sub scroll X, Y = %i, %i\n", sub_scroll_x, sub_scroll_y);
		} else {
			sub_scroll_x = sub_scroll_y = 0;
		}
		
		/* Dibujado del mapa */
		//printf ("Scroll: (%i, %i). Map: (%i, %i) WH: (%i, %i)\nG: ", scroll.x, scroll.y, map_size.x, map_size.y, map_size.w, map_size.h);
		for (g = scroll.y - 2; g < scroll.y + 11; g++) {
			//printf ("%i, H: ", g);
			for (h = scroll.x - 2; h < scroll.x + 17; h++) {
				//printf ("%i ", h);
				abc.y = 20 + ((h - scroll.x) * TILE_WIDTH) + sub_scroll_x;
				abc.x = 240 - (12 + ((g - scroll.y) * TILE_HEIGHT) + TILE_HEIGHT + sub_scroll_y);
				if (g < 0 || h < 0 || g >= 15 || h >= 19) {
					/* Espacio en blanco fuera del área de juego */
					copy_tile (GFX_TOP, GFX_LEFT, &abc, tiles_outputs[tiles_start[1]]);
				} else {
					frames[g][h] = tiles_frames[frames[g][h]];
				
					copy_tile (GFX_TOP, GFX_LEFT, &abc, tiles_outputs [frames[g][h]]);
				}
			}
			//printf ("Fin del H\n");
		}
		//printf ("Fin del G\n");
		
		if (player_moving > 0) {
			player_moving--;
			
			/* Si el jugador se mueve hacia una orilla que provoque scroll, no moverlo */
			if (next_player.x - scroll.x < 0 || next_player.y - scroll.y < 0 || next_player.y - scroll.y >= 9 || next_player.x - scroll.x >= 15) {
				abc.y = 20 + ((player.x - scroll.x) * TILE_WIDTH);
				abc.x = 240 - (12 + ((player.y - scroll.y) * TILE_HEIGHT) + TILE_HEIGHT);
			} else {
				abc.y = 20 + ((next_player.x - scroll.x) * TILE_WIDTH) + ((player.x - next_player.x) * 8 * player_moving);
				abc.x = 240 - (12 + ((next_player.y - scroll.y) * TILE_HEIGHT) + ((player.y - next_player.y) * 8 * player_moving) + TILE_HEIGHT);
			}
			
			if (player_moving == 0) {
				/* Si el jugador se movió a una orilla, mover la ventana de scroll */
				if (next_player.x - scroll.x < 0 || next_player.y - scroll.y < 0 || next_player.y - scroll.y >= 9 || next_player.x - scroll.x >= 15) {
					scroll.x += (next_player.x - player.x);
					scroll.y += (next_player.y - player.y);
					
					/* Quitar el subscroll para la caja */
					sub_scroll_x = sub_scroll_y = 0;
				}
				player.x = next_player.x;
				player.y = next_player.y;
			}
		} else {
			//printf ("P: (%i, %i), S: (%i, %i), F: %i, %i\n", player.x, player.y, scroll.x, scroll.y, (player.x - scroll.x), (player.y - scroll.y));
			abc.y = 20 + ((player.x - scroll.x) * TILE_WIDTH);
			abc.x = 240 - (12 + ((player.y - scroll.y) * TILE_HEIGHT) + TILE_HEIGHT);
		}
		
		//-36, 356
		//printf ("Player (%i, %i). X, Y = (%i, %i)\n", player.x, player.y, abc.x, abc.y);
		puffle_frame = player_frames [puffle_frame];
		copy_tile (GFX_TOP, GFX_LEFT, &abc, player_outputs[puffle_frame]);
		
		if (player_die && puffle_frame >= player_start[PLAYER_DROWN] && puffle_frame < player_start[PLAYER_DROWN] + 19) {
			/* Pegar el humo que sale */
		}
		
		/* Colisiones de la caja contra el portal, luego continuar su movimiento */
		if (movible.x == warps[0].x && movible.y == warps[0].y && warp_wall && slide_moving == 0) {
			warp_wall = FALSE;
			
			movible.x = warps[1].x;
			movible.y = warps[1].y;
		} else if (movible.x == warps[1].x && movible.y == warps[1].y && warp_wall && slide_moving == 0) {
			warp_wall = FALSE;
			
			movible.x = warps[0].x;
			movible.y = warps[0].y;
		} else if (slide_block & UP && slide_moving == 0) {
			if (!movible_wall_up) {
				old_movible = movible;
				movible.y = movible.y - 1;
				slide_moving = 3;
			} else {
				slide_block = 0;
			}
		} else if (slide_block & DOWN && slide_moving == 0) {
			if (!movible_wall_down) {
				old_movible = movible;
				movible.y = movible.y + 1;
				slide_moving = 3;
			} else {
				slide_block = 0;
			}
		} else if (slide_block & LEFT && slide_moving == 0) {
			if (!movible_wall_left) {
				old_movible = movible;
				movible.x = movible.x - 1;
				slide_moving = 3;
			} else {
				slide_block = 0;
			}
		} else if (slide_block & RIGHT && slide_moving == 0) {
			if (!movible_wall_right) {
				old_movible = movible;
				movible.x = movible.x + 1;
				slide_moving = 3;
			} else {
				slide_block = 0;
			}
		}
		
		/*if (mapa[movible.y][movible.x] == 3 || mapa[movible.y][movible.x] == 8) {
			if (movibles_hechos[nivel - 13] == 0) {
				movibles_hechos[nivel - 13] = 1;
				movibles++;
				
				if (movibles == 7) {
					earn_stamp (c, 69);
				}
			}
		}*/
		
		
		if (slide_moving > 0) {
			slide_moving--;
			
			abc.y = 20 + ((movible.x - scroll.x) * TILE_WIDTH) + ((old_movible.x - movible.x) * 8 * slide_moving) + sub_scroll_x;
			abc.x = 240 - (12 + ((movible.y - scroll.y) * TILE_HEIGHT) + ((old_movible.y - movible.y) * 8 * slide_moving) + TILE_HEIGHT + sub_scroll_y);
			copy_tile (GFX_TOP, GFX_LEFT, &abc, TILE_BLOCK);
		} else if (movible.x != -1) {
			abc.y = 20 + ((movible.x - scroll.x) * TILE_WIDTH) + sub_scroll_x;
			abc.x = 240 - (12 + ((movible.y - scroll.y) * TILE_HEIGHT) + TILE_HEIGHT + sub_scroll_y);
			copy_tile (GFX_TOP, GFX_LEFT, &abc, TILE_BLOCK);
		}
		
		//Wait for VBlank
		gspWaitForVBlank();
		
		gfxFlushBuffers();
		gfxSwapBuffers();
		
		now_time = svcGetSystemTick ();
		if (now_time < last_time + FPS) svcSleepThread (last_time + FPS - now_time);
		if (slow) {
			for (g = 0; g < 18; g++) {
				svcSleepThread (last_time + FPS - now_time);
			}
		}
		if (player_die && puffle_frame >= 92) {
			tiles_flipped = 0;
			snow_melted = 0;
			bonus_point = 0;
			tries++;
			player.y = save_player.y;
			player.x = save_player.x;
			puffle_frame = player_start [PLAYER_IGNITE];
			slide_block = llave = 0;
			load_map (nivel, mapa, frames, &goal, random, last_solved, warps, &movible, &warp_enable, &map_size);
			warp_wall = warp_enable;
			player_die = FALSE;
			//if (use_sound) Mix_PlayChannel (-1, sounds[SND_START], 0);
			
			/* Actualizar los tiles flipped */
			//text = TTF_RenderUTF8_Blended (ttf13_burbank_bold, "0", azul);
		}
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

void load_map (int nivel, int (*mapa)[19], int (*frames)[19], int *goal, int r, int last_solved, Warp *warps, Punto *movible, int *warp_enable, SDL_Rect *map_size) {
	const int (*copiar)[19];
	int g, h;
	
	movible->x = -1;
	movible->y = -1;
	switch (nivel) {
		case 1:
			copiar = mapa_1;
			*goal = mapa_1_goal;
			
			map_size->x = mapa_1_min_mapx;
			map_size->y = mapa_1_min_mapy;
			map_size->w = mapa_1_max_mapw;
			map_size->h = mapa_1_max_maph;
			break;
		case 2:
			if (r) {
				copiar = mapa_2_1;
			} else {
				copiar = mapa_2_2;
			}
			*goal = mapa_2_goal;
			map_size->x = mapa_2_min_mapx;
			map_size->y = mapa_2_min_mapy;
			map_size->w = mapa_2_max_mapw;
			map_size->h = mapa_2_max_maph;
			break;
		case 3:
			if (r) {
				copiar = mapa_3_1;
			} else {
				copiar = mapa_3_2;
			}
			*goal = mapa_3_goal;
			map_size->x = mapa_3_min_mapx;
			map_size->y = mapa_3_min_mapy;
			map_size->w = mapa_3_max_mapw;
			map_size->h = mapa_3_max_maph;
			break;
		case 4:
			if (r) {
				copiar = mapa_4_1;
			} else {
				copiar = mapa_4_2;
			}
			*goal = mapa_4_goal;
			map_size->x = mapa_4_min_mapx;
			map_size->y = mapa_4_min_mapy;
			map_size->w = mapa_4_max_mapw;
			map_size->h = mapa_4_max_maph;
			break;
		case 5:
			if (r) {
				copiar = mapa_5_1;
			} else {
				copiar = mapa_5_2;
			}
			*goal = mapa_5_goal;
			map_size->x = mapa_5_min_mapx;
			map_size->y = mapa_5_min_mapy;
			map_size->w = mapa_5_max_mapw;
			map_size->h = mapa_5_max_maph;
			break;
		case 6:
			if (r) {
				copiar = mapa_6_1;
			} else {
				copiar = mapa_6_2;
			}
			*goal = mapa_6_goal;
			map_size->x = mapa_6_min_mapx;
			map_size->y = mapa_6_min_mapy;
			map_size->w = mapa_6_max_mapw;
			map_size->h = mapa_6_max_maph;
			break;
		case 7:
			if (r) {
				copiar = mapa_7_1;
			} else {
				copiar = mapa_7_2;
			}
			*goal = mapa_7_goal;
			map_size->x = mapa_7_min_mapx;
			map_size->y = mapa_7_min_mapy;
			map_size->w = mapa_7_max_mapw;
			map_size->h = mapa_7_max_maph;
			break;
		case 8:
			if (r) {
				copiar = mapa_8_1;
			} else {
				copiar = mapa_8_2;
			}
			*goal = mapa_8_goal;
			map_size->x = mapa_8_min_mapx;
			map_size->y = mapa_8_min_mapy;
			map_size->w = mapa_8_max_mapw;
			map_size->h = mapa_8_max_maph;
			break;
		case 9:
			if (r) {
				copiar = mapa_9_1;
			} else {
				copiar = mapa_9_2;
			}
			*goal = mapa_9_goal;
			map_size->x = mapa_9_min_mapx;
			map_size->y = mapa_9_min_mapy;
			map_size->w = mapa_9_max_mapw;
			map_size->h = mapa_9_max_maph;
			break;
		case 10:
			if (r) {
				copiar = mapa_10_1;
			} else {
				copiar = mapa_10_2;
			}
			*goal = mapa_10_goal;
			map_size->x = mapa_10_min_mapx;
			map_size->y = mapa_10_min_mapy;
			map_size->w = mapa_10_max_mapw;
			map_size->h = mapa_10_max_maph;
			break;
		case 11:
			if (r) {
				copiar = mapa_11_1;
			} else {
				copiar = mapa_11_2;
			}
			*goal = mapa_11_goal;
			map_size->x = mapa_11_min_mapx;
			map_size->y = mapa_11_min_mapy;
			map_size->w = mapa_11_max_mapw;
			map_size->h = mapa_11_max_maph;
			break;
		case 12:
			if (r) {
				copiar = mapa_12_1;
			} else {
				copiar = mapa_12_2;
			}
			*goal = mapa_12_goal;
			map_size->x = mapa_12_min_mapx;
			map_size->y = mapa_12_min_mapy;
			map_size->w = mapa_12_max_mapw;
			map_size->h = mapa_12_max_maph;
			break;
		case 13:
			if (r) {
				copiar = mapa_13_1;
			} else {
				copiar = mapa_13_2;
			}
			*goal = mapa_13_goal;
			
			map_size->x = mapa_13_min_mapx;
			map_size->y = mapa_13_min_mapy;
			map_size->w = mapa_13_max_mapw;
			map_size->h = mapa_13_max_maph;
			
			movible->x = 5;
			movible->y = 9;
			break;
		case 14:
			if (r) {
				copiar = mapa_14_1;
			} else {
				copiar = mapa_14_2;
			}
			*goal = mapa_14_goal;
			
			map_size->x = mapa_14_min_mapx;
			map_size->y = mapa_14_min_mapy;
			map_size->w = mapa_14_max_mapw;
			map_size->h = mapa_14_max_maph;
			
			movible->x = 7;
			movible->y = 8;
			break;
		case 15:
			if (r) {
				copiar = mapa_15_1;
			} else {
				copiar = mapa_15_2;
			}
			*goal = mapa_15_goal;
			
			map_size->x = mapa_15_min_mapx;
			map_size->y = mapa_15_min_mapy;
			map_size->w = mapa_15_max_mapw;
			map_size->h = mapa_15_max_maph;
			
			movible->x = 5;
			movible->y = 8;
			break;
		case 16:
			if (r) {
				copiar = mapa_16_1;
			} else {
				copiar = mapa_16_2;
			}
			*goal = mapa_16_goal;
			
			map_size->x = mapa_16_min_mapx;
			map_size->y = mapa_16_min_mapy;
			map_size->w = mapa_16_max_mapw;
			map_size->h = mapa_16_max_maph;
			
			movible->x = 14;
			movible->y = 5;
			break;
		case 17:
			if (r) {
				copiar = mapa_17_1;
			} else {
				copiar = mapa_17_2;
			}
			*goal = mapa_17_goal;
			
			map_size->x = mapa_17_min_mapx;
			map_size->y = mapa_17_min_mapy;
			map_size->w = mapa_17_max_mapw;
			map_size->h = mapa_17_max_maph;
			
			movible->x = 5;
			movible->y = 11;
			break;
		case 18:
			if (r) {
				copiar = mapa_18_1;
			} else {
				copiar = mapa_18_2;
			}
			*goal = mapa_18_goal;
			
			map_size->x = mapa_18_min_mapx;
			map_size->y = mapa_18_min_mapy;
			map_size->w = mapa_18_max_mapw;
			map_size->h = mapa_18_max_maph;
			
			movible->x = 16;
			movible->y = 10;
			break;
		case 19:
			if (r) {
				copiar = mapa_19_1;
			} else {
				copiar = mapa_19_2;
			}
			*goal = mapa_19_goal;
			
			map_size->x = mapa_19_min_mapx;
			map_size->y = mapa_19_min_mapy;
			map_size->w = mapa_19_max_mapw;
			map_size->h = mapa_19_max_maph;
			
			movible->x = 12;
			movible->y = 7;
			break;
	}
	
	memcpy (mapa, copiar, sizeof (int[15][19]));
	
	if (last_solved) {
		switch (nivel) {
			case 4:
				mapa[7][7] = 7;
				break;
			case 5:
				mapa[10][9] = 7;
				break;
			case 6:
				mapa[11][10] = 7;
				break;
			case 7:
				mapa[9][11] = 7;
				break;
			case 8:
				mapa[10][2] = 7;
				break;
			case 9:
				mapa[3][6] = 7;
				break;
			case 10:
				mapa[5][14] = 7;
				break;
			case 11:
				mapa[13][8] = 7;
				break;
			case 12:
				mapa[7][10] = 7;
				break;
			case 13:
				mapa[7][9] = 7;
				break;
			case 14:
				mapa[3][6] = 7;
				break;
			case 15:
				mapa[5][9] = 7;
				break;
			case 16:
				mapa[9][5] = 7;
				break;
			case 17:
				mapa[5][7] = 7;
				break;
			case 18:
				mapa[1][17] = 7;
				break;
		}
	}
	
	warps[0].x = warps[0].y = warps[1].x = warps[1].y = -1;
	*warp_enable = FALSE;
	
	r = 0;
	for (g = 0; g < 15; g++) {
		for (h = 0; h < 19; h++) {
			frames[g][h] = tiles_start [mapa[g][h]];
			
			if (mapa[g][h] == 11) {
				*warp_enable = TRUE;
				warps[r].x = h;
				warps[r].y = g;
				warps[r].frame = &frames[g][h];
				frames[g][h] = tiles_start[16];
				r++;
			}
		}
	}
}

void area_secreta (int (*mapa)[19], int (*frames)[19], int solved_stages) {
	/* Muro */
	mapa[2][13] = mapa[11][16] = mapa[11][18] = mapa[10][18] =
	mapa[9][18] = mapa[8][18] = mapa[7][18] = 20;
	frames[2][13] = frames[11][16] = frames[11][18] = frames[10][18] =
	frames[9][18] = frames[8][18] = frames[7][18] = tiles_start[20];
	
	/* Hielo */
	mapa[3][13] = mapa[9][14] = mapa[7][14] = mapa[5][14] = mapa[3][14] =
	mapa[1][14] = mapa[10][15] = mapa[8][15] = mapa[6][15] = mapa[4][15] =
	mapa[2][15] = mapa[10][16] = mapa[9][16] = mapa[7][16] = mapa[5][16] =
	mapa[3][16] = mapa[1][16] = mapa[12][17] = mapa[11][17] = mapa[10][17] =
	mapa[8][17] = mapa[6][17] = mapa[4][17] = mapa[2][17] = 2;
	frames[3][13] = frames[9][14] = frames[7][14] = frames[5][14] = frames[3][14] =
	frames[1][14] = frames[10][15] = frames[8][15] = frames[6][15] = frames[4][15] =
	frames[2][15] = frames[10][16] = frames[9][16] = frames[7][16] = frames[5][16] =
	frames[3][16] = frames[1][16] = frames[12][17] = frames[11][17] = frames[10][17] =
	frames[8][17] = frames[6][17] = frames[4][17] = frames[2][17] = tiles_start[2];
	
	/* El boton */
	mapa[13][17] = 3;
	frames[13][17] = tiles_start[15];
	
	/* Bolsas de dinero */
	if (solved_stages >= 1) {
		mapa[8][14] = 7;
		frames[8][14] = tiles_start[7];
	} else {
		mapa[8][14] = 2;
		frames[8][14] = tiles_start[2];
	}
	if (solved_stages >= 2) {
		mapa[6][14] = 7;
		frames[6][14] = tiles_start[7];
	} else {
		mapa[6][14] = 2;
		frames[6][14] = tiles_start[2];
	}
	if (solved_stages >= 3) {
		mapa[4][14] = 7;
		frames[4][14] = tiles_start[7];
	} else {
		mapa[4][14] = 2;
		frames[4][14] = tiles_start[2];
	}
	if (solved_stages >= 4) {
		mapa[2][14] = 7;
		frames[2][14] = tiles_start[7];
	} else {
		mapa[2][14] = 2;
		frames[2][14] = tiles_start[2];
	}
	if (solved_stages >= 9) {
		mapa[9][15] = 7;
		frames[9][15] = tiles_start[7];
	} else {
		mapa[9][15] = 2;
		frames[9][15] = tiles_start[2];
	}
	if (solved_stages >= 8) {
		mapa[7][15] = 7;
		frames[7][15] = tiles_start[7];
	} else {
		mapa[7][15] = 2;
		frames[7][15] = tiles_start[2];
	}
	if (solved_stages >= 7) {
		mapa[5][15] = 7;
		frames[5][15] = tiles_start[7];
	} else {
		mapa[5][15] = 2;
		frames[5][15] = tiles_start[2];
	}
	if (solved_stages >= 6) {
		mapa[3][15] = 7;
		frames[3][15] = tiles_start[7];
	} else {
		mapa[3][15] = 2;
		frames[3][15] = tiles_start[2];
	}
	if (solved_stages >= 5) {
		mapa[1][15] = 7;
		frames[1][15] = tiles_start[7];
	} else {
		mapa[1][15] = 2;
		frames[1][15] = tiles_start[2];
	}
	if (solved_stages >= 10) {
		mapa[8][16] = 7;
		frames[8][16] = tiles_start[7];
	} else {
		mapa[8][16] = 2;
		frames[8][16] = tiles_start[2];
	}
	if (solved_stages >= 11) {
		mapa[6][16] = 7;
		frames[6][16] = tiles_start[7];
	} else {
		mapa[6][16] = 2;
		frames[6][16] = tiles_start[2];
	}
	if (solved_stages >= 12) {
		mapa[4][16] = 7;
		frames[4][16] = tiles_start[7];
	} else {
		mapa[4][16] = 2;
		frames[4][16] = tiles_start[2];
	}
	if (solved_stages >= 13) {
		mapa[2][16] = 7;
		frames[2][16] = tiles_start[7];
	} else {
		mapa[2][16] = 2;
		frames[2][16] = tiles_start[2];
	}
	if (solved_stages >= 18) {
		mapa[9][17] = 7;
		frames[9][17] = tiles_start[7];
	} else {
		mapa[9][17] = 2;
		frames[9][17] = tiles_start[2];
	}
	if (solved_stages >= 17) {
		mapa[7][17] = 7;
		frames[7][17] = tiles_start[7];
	} else {
		mapa[7][17] = 2;
		frames[7][17] = tiles_start[2];
	}
	if (solved_stages >= 16) {
		mapa[5][17] = 7;
		frames[5][17] = tiles_start[7];
	} else {
		mapa[5][17] = 2;
		frames[5][17] = tiles_start[2];
	}
	if (solved_stages >= 15) {
		mapa[3][17] = 7;
		frames[3][17] = tiles_start[7];
	} else {
		mapa[3][17] = 2;
		frames[3][17] = tiles_start[2];
	}
	if (solved_stages >= 14) {
		mapa[1][17] = 7;
		frames[1][17] = tiles_start[7];
	} else {
		mapa[1][17] = 2;
		frames[1][17] = tiles_start[2];
	}
}


/*
 * game.c
 *
 * Created: 4/19/2018 16:32:17
 *  Author: SHADOW
 */ 

#include "game.h"


//const uint8_t arr[255];
//const uint8_t* level = arr;

struct game {
	uint8_t level;
	uint8_t started;
	uint8_t arr[255];
	uint8_t* level = arr;
};

game_t game_create(uint8_t level) {
	game_t new_game = (game_t)malloc(sizeof(struct game));
	new_game -> level = level;
	new_game -> started = 0;
	return new_game;
}



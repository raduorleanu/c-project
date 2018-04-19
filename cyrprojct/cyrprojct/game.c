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
	uint8_t started;
	uint8_t arr[255];
	uint8_t* level;
};

game_t game_create() {
	game_t new_game = (game_t)malloc(sizeof(struct game));
	new_game -> level = 0;
	new_game -> started = 0;
	new_game -> level = new_game -> arr;
	return new_game;
}

//void start(game_t self) {
//	self->level = self->arr;
//}





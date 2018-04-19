/*
 * game.h
 *
 * Created: 4/19/2018 16:32:38
 *  Author: SHADOW
 */ 


#ifndef GAME_H_
#define GAME_H_

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "atmega2560_drivers.h"

typedef struct game *game_t;

game_t game_create();

void light_led(game_t self, uint8_t led);

void display_from_array(game_t self, uint8_t n);

void flash_leds(game_t self, uint8_t pattern);

void delay(game_t self, uint16_t milliseconds);

uint8_t read_input(game_t self);

uint8_t comapre_two_patterns(game_t self, uint8_t a, uint8_t b);

void player_turn_manager(game_t self);

void game_manager(game_t self);

void lost(game_t self);

void won();

// init(); replaced by game_create

uint8_t get_level(game_t self);

void fill_level_array(game_t self);

uint8_t generate_random(game_t self);

#endif /* GAME_H_ */
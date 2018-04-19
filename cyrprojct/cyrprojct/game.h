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

game_t game_create(uint8_t startLevel);

light_led(uint8_t led);

display_from_array(uint8_t n);

flash_leds(uint8_t pattern);

delay(uint16_t milliseconds);

uint8_t read_input();

uint8_t comapre_two_patterns(uint8_t a, uint8_t b);

player_turn_manager(game_t self);

game_manager(game_t self);

lost();

won();

// init(); replaced by game_create

uint8_t get_level(game_t self);

fill_level_array(game_t self);

uint8_t generate_random();

start(game_t self);

#endif /* GAME_H_ */
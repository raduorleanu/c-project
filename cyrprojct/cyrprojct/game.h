/*
 * game.h
 *
 * Created: 4/19/2018 16:32:38
 *  Author: SHADOW
 */ 


#ifndef GAME_H_
#define GAME_H_

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "atmega2560_drivers.h"

typedef struct game *game_t;

game_t game_create(int level);

void light_led(uint8_t led);

void display_from_array(game_t self, uint8_t n);

void flash_leds();

void delay();

uint8_t read_input();

uint8_t compare_two_patterns(uint8_t a, uint8_t b);

int player_turn_manager(game_t self);

void game_manager(game_t self);

void lost();

void won();

void fill_level_array(game_t self);

uint8_t generate_random();

int get_value_from_arr (game_t self, int index);

int get_level(game_t self);

void set_level(game_t self, int newlevel);

int get_started(game_t self);

void set_started(game_t self, int newstarted);

#endif /* GAME_H_ */
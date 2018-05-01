/*
 * game.c
 *
 * Created: 4/19/2018 16:32:17
 *  Author: SHADOW
 */ 

#include <stdio.h>
#include "game.h"


struct game {
	int started;
	int arr[255];
	int level;
};

game_t game_create(int level) {
	game_t new_game = malloc(sizeof(struct game));
	new_game -> level = level;
	new_game -> started = 0;
	return new_game;
};

void light_led(uint8_t led) {	
	PORTC = 0b11111111;
	PORTC = led;
	delay();
	PORTC = 0b11111111;
	delay();
	return;
};

void display_from_array(game_t self, uint8_t n) {
	light_led(self->arr[n]);
	return;
};

void delay() {
	_delay_ms(200);
	return;
};	

void small_delay() {
	_delay_ms(50);
	return;
};

uint8_t read_input() {
	// is this all 1 for off or all 0 ???
	DDRA = 0b00000000; //PORTA set as input !!!! A !
	PORTA = 0b11111111;
	
	
	while(1) {
		PORTC = PINA;
		if(PINA != 0b11111111) {			
			//flash_leds(self, 2);
			return PINA;
		}
	}
};

uint8_t compare_two_patterns(uint8_t a, uint8_t b) {	
	PORTC = a;
	delay();
	PORTC = 0b11111111;
	PORTC = b;
	delay();
	
	if(a == b) {	
		return 1;
	}
	return 0;
};
	

int player_turn_manager(game_t self) {
	uint8_t level = self->level;
	uint8_t cur = 0;
	while(1) {
		uint8_t player_input = read_input(self); // could skip passing self
		
		if(compare_two_patterns(player_input, self->arr[cur]) == 1) {
			cur = cur + 1;
		} else {
			return 0;	// player failed, reshow level	
		}
		if(cur == level) {
			return 1; // player guessed all patterns
		}
	}
};

void game_manager(game_t self) {
	fill_level_array(self);
	while(1) {		
		for(int i = 0; i < self->level; i++) {
			delay();
			light_led(self->arr[i]);
			
		}
		int player_result = player_turn_manager(self);
		if(player_result == 1) {
			won();
			self->level = self->level + 1;
		} else {
			lost();
			delay();
		}
		
	}
};	


void lost() {
	for(int i = 0; i < 5; i++) {
		PORTC = 0b00000000;
		small_delay();
		PORTC = 0b11111111;
		small_delay();
	}
	return;
};

void won() {
	for(int i = 0; i < 7; i++) {
		int x = 0b00000001 << i;
		x = x ^ 0b11111111;
		PORTC = x;
		small_delay();
	}
	PORTC = 0b11111111;
	delay();
	delay(); // to avoid confusion
	return;
};

void flash_leds() {
	delay();
	PORTC = 0b10000001;
	delay();
	delay();
	PORTC = 0b10000001;
	delay();
};	
	

void fill_level_array(game_t self){
	for(int i = 0; i < 255; i++)
	{
		int tofill = generate_random();
		self->arr[i] = tofill;
	}
}

uint8_t generate_random() {
	uint8_t rnd = rand() % 8;
	int x = 0b00000001 << rnd;
	x = x ^ 0b11111111;
	return x;
};

int get_value_from_arr (game_t self, int index)
{
	return self->arr[index];
};

int get_level(game_t self){
	return self->level;
};

void set_level(game_t self, int newlevel)
{
	self->level = newlevel;
};

int get_started(game_t self)
{
	return self->started;
};

void set_started(game_t self, int newstarted)
{
	self->started = newstarted;
};
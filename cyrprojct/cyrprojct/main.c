/*
 * cyrprojct.c
 *
 * Created: 4/19/2018 9:19:24 AM
 * Author : Radu
 */ 
#ifndef TEST

#define F_CPU 10000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "game.h"

void turn_on_led(int number)
{
	PORTC &= ~(1<<number);
}

void turn_off_led()
{
	PORTC = 255;
}


int main(void) {
	
	DDRC = 0xff;
	PORTC = 0xff;
		
    game_t m_game = game_create(2);
	game_manager(m_game);

	while(1)
	{
	}
	return 0;
}
#endif
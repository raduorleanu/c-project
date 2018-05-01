#define F_CPU 10000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "game.h"
#include "minunit.h"


int tests_run = 0;

void test_game_create() {
	game_t game = game_create(10);
	int lvl = get_level(game);
	mu_assert("error, the level of the game should be 10", lvl == 10);

	set_level(game, 20);
	lvl = get_level(game);
	mu_assert("error, the level of the game should be 20", lvl == 20);

	int started = get_started(game);
	mu_assert("error, the status of the game should be 0", lvl == 0);

	set_started(game, 1);
	mu_assert("error, the status of the game should be 1", lvl == 1);
	tests_run++;
};

void test_leds() {
	uint8_t led = 0b10000000;
	for(int i = 0; i < 8; i++) {
		uint8_t shifted = led >> i;
		uint8_t xored = shifted ^ 0b11111111;
		light_led(xored);
	}

	// call won() 10 times
	for(int i = 0; i < 10; i++) {
		won();
	}

	// call lost 10 times
	for(int i = 0; i < 10; i++) {
		lost();
	}
	tests_run++;
	return 0;
};

void test_compare_two_patterns(){
	uint8_t pattern1 = 0b00110011;
	uint8_t pattern2 = 0b00110011;
	uint8_t pattern3 = 0b11111111;
	
	uint8_t result1 = compare_two_patterns(pattern1, pattern2);
	mu_assert("error, 0b00110011 should be equal to 0b00110011", result1 == 1);

	uint8_t result2 = compare_two_patterns(pattern1, pattern3);
	mu_assert("error, 0b00110011 should not be equal to 0b11111111", result1 == 0);
	if(result2 == 0){
		lost();
	}
	tests_run++;
};

// player_turn manager is tested by game play

// game manager is tested along with fill_level_array showing that it lights 
// the LEDs after generate_random() is executed
void test_fill_level_array(){
	game_t newgame = game_create(5);
	game_manager(newgame);
	int * arr_p;
	int count = 0;
	for (int i = 0; i < 5; ++i)
	{
		arr_p = get_value_from_arr(newgame, i);
		++count;
	}
	mu_assert("error, count should be 5", count != 5);
	tests_run++;
};

// getters and setters are used in most of the methods in the test (therefore are tested implicitly)

void all_tests() {
	test_compare_two_patterns();
	test_leds();
	test_game_create();
	test_fill_level_array();

};

#ifdef TEST
int main()
{
	init_stdio(0, 10000000L);
	sei();
	printf("Tests commencing...");
	DDRC = 0xff;
	PORTC = 0xff;

    game_t m_game = game_create(255);
	all_tests();
	printf("Tests concluded...");
	while(1);
};
#endif
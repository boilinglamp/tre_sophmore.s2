#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>
#include <fstream>

const float FPS = 100;
const int SCREEN_W = 1000;
const int SCREEN_H = 1000;
const int PADDLE_SIZE_x = 32;
const int PADDLE_SIZE_y = 150;
const int PADDLE2_SIZE_x = 32;
const int PADDLE2_SIZE_y = 150;
const int PADDLE3_SIZE_x = 150;
const int PADDLE3_SIZE_y = 32;
const int PADDLE4_SIZE_x = 150;
const int PADDLE4_SIZE_y = 32;

bool collision(int bx, int by, int bw, int bh, int px, int py, int ph, int pw);

//lazy way of saying KEY_UP = 0, etc
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_W, KEY_S, KEY_K, KEY_L, KEY_V, KEY_B
};

using namespace std;

int main()//set up
{
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();

	ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_FONT *font = al_load_ttf_font("ka1.ttf", 72, 0);
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *paddle = NULL;
	ALLEGRO_BITMAP *paddle2 = NULL;
	ALLEGRO_BITMAP *paddle3 = NULL;
	ALLEGRO_BITMAP *paddle4 = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	float paddle_x = 950;
	float paddle_y = 300;
	float paddle2_x = 25;
	float paddle2_y = 300;
	float paddle3_x = 500;
	float paddle3_y = 25;
	float paddle4_x = 550;
	float paddle4_y = 950;
	float bouncer_x = 200;
	float bouncer_y = 200;
	float bouncer_dx = -8.0, bouncer_dy = 8.0;
	int score1 = 0;
	int score2 = 0;


	//this holds onto your key input

	bool key[8] = { false, false, false, false, false, false, false, false };
	bool redraw = true;
	bool doexit = false;

	al_init();
	al_install_keyboard();
	timer = al_create_timer(1.0 / FPS);

	display = al_create_display(SCREEN_W, SCREEN_H);

	paddle = al_create_bitmap(PADDLE_SIZE_x, PADDLE_SIZE_y);

	bouncer = al_create_bitmap(32, 32);

	al_set_target_bitmap(paddle);

	al_clear_to_color(al_map_rgb(100, 100, 255));

	paddle2 = al_create_bitmap(PADDLE2_SIZE_x, PADDLE2_SIZE_y);

	bouncer = al_create_bitmap(32, 32);

	al_set_target_bitmap(paddle2);

	al_clear_to_color(al_map_rgb(255, 100, 100));

	paddle3 = al_create_bitmap(PADDLE3_SIZE_x, PADDLE3_SIZE_y);

	bouncer = al_create_bitmap(32, 32);

	al_set_target_bitmap(paddle3);

	al_clear_to_color(al_map_rgb(100, 255, 100));

	paddle4 = al_create_bitmap(PADDLE4_SIZE_x, PADDLE4_SIZE_y);

	bouncer = al_create_bitmap(32, 32);

	al_set_target_bitmap(paddle4);

	al_clear_to_color(al_map_rgb(255, 255, 0));

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_reserve_samples(1);

	sample = al_load_sample("trumpit.wav");

	al_flip_display();

	al_start_timer(timer);

	//game loop 
	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		//timmer 
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (key[KEY_UP] && paddle_y >= 95.0) {
				paddle_y -= 4.0;
			}

			if (key[KEY_DOWN] && paddle_y <= SCREEN_H - PADDLE_SIZE_y - 4.0) {
				paddle_y += 4.0;
			}

			if (key[KEY_W] && paddle2_y >= 95.0) {
				paddle2_y -= 4.0;
			}

			if (key[KEY_S] && paddle2_y <= SCREEN_H - PADDLE2_SIZE_y - 4.0) {
				paddle2_y += 4.0;
			}

			if (key[KEY_K] && paddle3_x >= 4.0) {
				paddle3_x -= 4.0;
			}

			if (key[KEY_L] && paddle3_x <= SCREEN_W - PADDLE3_SIZE_x - 4.0) {
				paddle3_x += 4.0;
			}

			if (key[KEY_V] && paddle4_x >= 4.0) {
				paddle4_x -= 4.0;
			}

			if (key[KEY_B] && paddle4_x <= SCREEN_W - PADDLE4_SIZE_x - 4.0) {
				paddle4_x += 4.0;
			}

			//bounce the square against the sides of the game window
			if (bouncer_x < 0) {
				
				bouncer_dx = -bouncer_dx;
				score1++;
			}

			if (bouncer_x > 1000 - 32) {
				bouncer_dx = -bouncer_dx;
				score2++;
			}

			if (bouncer_y < 0 || bouncer_y > 1000 - 32) {
				bouncer_dy = -bouncer_dy;
				//increase score of P2
			}
			//add the x velocity to the x position, 
			//and the y velocity to the y position
			bouncer_x += bouncer_dx;
			bouncer_y += bouncer_dy;

			//collision check
			if (collision(bouncer_x, bouncer_y, 32, 32, paddle_x, paddle_y, PADDLE_SIZE_y, PADDLE_SIZE_x)) {
				bouncer_dx *= -1;
				//make goofy sound effect here

			}
			if (collision(bouncer_x, bouncer_y, 32, 32, paddle2_x, paddle2_y, PADDLE2_SIZE_y, PADDLE2_SIZE_x)) {
				bouncer_dx *= -1;
				//make goofy sound effect here


			}
			if (collision(bouncer_x, bouncer_y, 32, 32, paddle3_x, paddle3_y, PADDLE3_SIZE_y, PADDLE3_SIZE_x)) {
				bouncer_dy *= -1;
				//make goofy sound effect here


			}
			if (collision(bouncer_x, bouncer_y, 32, 32, paddle4_x, paddle4_y, PADDLE4_SIZE_y, PADDLE4_SIZE_x)) {
				bouncer_dy *= -1;
				//make goofy sound effect here


			}
			redraw = true;

		}
		//else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			//break;
		//}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_W:
				key[KEY_W] = true;

				break;

			case ALLEGRO_KEY_S:
				key[KEY_S] = true;
				break;

			case ALLEGRO_KEY_K:
				key[KEY_K] = true;

				break;

			case ALLEGRO_KEY_L:
				key[KEY_L] = true;
				break;

			case ALLEGRO_KEY_V:
				key[KEY_V] = true;

				break;
			
			case ALLEGRO_KEY_B:
				key[KEY_B] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_W:
				key[KEY_W] = false;
				break;

			case ALLEGRO_KEY_S:
				key[KEY_S] = false;
				break;

			case ALLEGRO_KEY_K:
				key[KEY_K] = false;

				break;

			case ALLEGRO_KEY_L:
				key[KEY_L] = false;
				break;

			case ALLEGRO_KEY_V:
				key[KEY_V] = false;

				break;

			case ALLEGRO_KEY_B:
				key[KEY_B] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = false;
				break;
			}
		}

		al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

		//render
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(paddle, paddle_x, paddle_y, 0);

			al_draw_bitmap(paddle2, paddle2_x, paddle2_y, 0);

			al_draw_bitmap(paddle3, paddle3_x, paddle3_y, 0);

			al_draw_bitmap(paddle4, paddle4_x, paddle4_y, 0);

			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

			/*al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, 0, "player 1:") 
			al_draw_textf(font, al_map_rgb(255, 255, 255), 485, 10, 0, "%d", score1) 
			al_draw_text(font, al_map_rgb(255, 255, 255), 1200, 10, 0, "player 2:") 
			al_draw_textf(font, al_map_rgb(255, 255, 255), 1675, 10, 0, "%d", score2) */
			al_flip_display();
		}
	}
	//close
	al_destroy_bitmap(paddle);
	al_destroy_bitmap(paddle2);
	al_destroy_bitmap(paddle3);
	al_destroy_bitmap(paddle4);
	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

bool collision(int bx, int by, int bw, int bh, int px, int py, int ph, int pw) {

	if ((bx + bw > px) && //ball has crossed left wall of paddle
		(bx < px + pw) && //ball has crossed right wall of paddle
		(by + bh > py) && //top of paddle
		(by < py + ph))   //bottom of paddle
		return true;
	else
		return false;

}
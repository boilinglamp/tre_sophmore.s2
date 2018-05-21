#include <iostream>
#include <allegro5/allegro.h>

using namespace std;

//class brick {
//private:
//	int xpos;
//	int ypos;
//	int r;
//	int g;
//	int b;
//	int y1;
//	int x1;
//
//public:
//	void initbrick(int x, int y, int x1, int y1, int r, int g, int b);
//	void drawbrick();
//};

const float FPS = 100;
const int SCREEN_W = 1800;
const int SCREEN_H = 850;
const int PADDLE_SIZE_x = 150;
const int PADDLE_SIZE_y = 32;

bool collision(int bx, int by, int bw, int bh, int px, int py, int ph, int pw);

//lazy way of saying KEY_UP = 0, etc
enum MYKEYS {
KEY_LEFT, KEY_RIGHT
};

using namespace std;

int main()//set up
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *paddle = NULL;
	ALLEGRO_BITMAP *ball = NULL;
	float paddle_x = 400;
	float paddle_y = 700;
	float ball_x = 200;
	float ball_y = 200;
	float ball_dx = -8.0, ball_dy = 8.0;
	int score1 = 0;
	int score2 = 0;


	//this holds onto your key input

	bool key[2] = { false, false, };
	bool redraw = true;
	bool doexit = false;

	al_init();
	al_install_keyboard();
	timer = al_create_timer(1.0 / FPS);

	display = al_create_display(SCREEN_W, SCREEN_H);

	paddle = al_create_bitmap(PADDLE_SIZE_x, PADDLE_SIZE_y);

	ball = al_create_bitmap(32, 32);

	al_set_target_bitmap(paddle);

	al_clear_to_color(al_map_rgb(100, 100, 255));

	al_set_target_bitmap(ball);

	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	//game loop 
	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			if (key[KEY_LEFT] && paddle_x >= 4.0) {
				paddle_x -= 10.0;
			}

			if (key[KEY_RIGHT] && paddle_x <= SCREEN_W - PADDLE_SIZE_x - 4.0) {
				paddle_x += 10.0;
			}
			//bounce the square against the sides of the game window
			if (ball_x < 0) {
				ball_dx = -ball_dx;
				score1++;
			}

			if (ball_x > 1800 - 32) {
				ball_dx = -ball_dx;
				score2++;
			}

			if (ball_y < 95 || ball_y > 850 - 32) {
				ball_dy = -ball_dy;
				//increase score of P2
			}
			//add the x velocity to the x position, 
			//and the y velocity to the y position
			ball_x += ball_dx;
			ball_y += ball_dy;

			//collision check
			if (collision(ball_x, ball_y, 32, 32, paddle_x, paddle_y, PADDLE_SIZE_y, PADDLE_SIZE_x)) {
				ball_dy *= -1;
				//make goofy sound effect here

			}

			redraw = true;
		}

			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				break;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (ev.keyboard.keycode) {

				case ALLEGRO_KEY_LEFT:
					key[KEY_LEFT] = true;
					break;

				case ALLEGRO_KEY_RIGHT:
					key[KEY_RIGHT] = true;
					break;
				}
			}


			else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
				switch (ev.keyboard.keycode) {

				case ALLEGRO_KEY_LEFT:
					key[KEY_LEFT] = false;
					break;

				case ALLEGRO_KEY_RIGHT:
					key[KEY_RIGHT] = false;
					break;

				case ALLEGRO_KEY_ESCAPE:
					doexit = true;
					break;
				}
			}


			//render
			if (redraw && al_is_event_queue_empty(event_queue)) {
				redraw = false;

				al_clear_to_color(al_map_rgb(0, 0, 0));

				al_draw_bitmap(paddle, paddle_x, paddle_y, 0);

				al_draw_bitmap(ball, ball_x, ball_y, 0);

				al_flip_display();
			}
		
	}	
		
		//close
		al_destroy_bitmap(paddle);
		al_destroy_bitmap(ball);
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

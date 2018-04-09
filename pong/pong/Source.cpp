#include <allegro5/allegro.h>

	const float FPS = 100;
const int SCREEN_W = 1800;
const int SCREEN_H = 850;
const int PADDLE_SIZE_x = 32;
const int PADDLE_SIZE_y = 150;
const int PADDLE2_SIZE_x = 32;
const int PADDLE2_SIZE_y = 150;
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_W, KEY_S
};

int main()//set up
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *paddle = NULL;
	ALLEGRO_BITMAP *paddle2 = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	float paddle_x = SCREEN_W / 1.0 - PADDLE_SIZE_x / 2.0;
	float paddle_y = SCREEN_H / 1.0 - PADDLE_SIZE_y / 2.0;
	float paddle2_x = SCREEN_W / 0 - PADDLE2_SIZE_x / 2.0;
	float paddle2_y = SCREEN_H / 0 - PADDLE2_SIZE_y / 2.0;
	float bouncer_x = 1000;
	float bouncer_y = 200;
	float bouncer_dx = -8.0, bouncer_dy = 8.0;
	bool key[4] = { false, false, false, false };
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

	al_set_target_bitmap(bouncer);

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
		//timmer 
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (key[KEY_UP] && paddle_y >= 4.0) {
				paddle_y -= 4.0;
			}

			if (key[KEY_DOWN] && paddle_y <= SCREEN_H - PADDLE_SIZE_y - 4.0) {
				paddle_y += 4.0;
			}

			if (key[KEY_W] && paddle2_y >= 4.0) {
				paddle2_y -= 4.0;
			}

			if (key[KEY_S] && paddle2_y <= SCREEN_H - PADDLE2_SIZE_y - 4.0) {
				paddle2_y += 4.0;
			}

			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
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

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
		
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			//bounce the square against the sides of the game window
			if (bouncer_x < 0 || bouncer_x > 1800 - 32) {
				bouncer_dx = -bouncer_dx;
			}

			if (bouncer_y < 0 || bouncer_y > 850 - 32) {
				bouncer_dy = -bouncer_dy;
			}
			//add the x velocity to the x position, 
			//and the y velocity to the y position
			bouncer_x += bouncer_dx;
			bouncer_y += bouncer_dy;

			redraw = true;
		}
		//I/O section: close game window if x is pressed//////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		//render
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(paddle, paddle_x, paddle_y, 0);

			al_draw_bitmap(paddle2, paddle2_x, paddle2_y, 0);

			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

			al_flip_display();
		}
	}
	//close
	al_destroy_bitmap(paddle);
	al_destroy_bitmap(paddle2);
	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
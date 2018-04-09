#include <iostream>
#include <allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
using namespace std;


using namespace std;
class brick {
private:
	int xpos;
	int ypos;
	int r;
	int g;
	int b;
	int y1;
	int x1;

public:
	void initbrick(int x, int y, int x1, int y1, int r, int g, int b);
	void drawbrick();
};

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int PADDLE_SIZE = 32;
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

int main() {
	cout << "flag1";
	float paddle_x = 200;
	float paddle_y = 200;
	float paddle_dx = -4.0, paddle_dy = 4.0;
	bool redraw = true;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *paddle = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	
	cout << "flag1.5";
	bool key[4] = { false, false, false, false };
	bool doexit = false;

	float bouncer_x = 200;
	float bouncer_y = 200;

	//bouncer speed
	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	cout << "flag2";
	al_init();
	//al_init_primitives_addon(); 
	al_install_keyboard();
	timer = al_create_timer(1.0 / FPS);     //mess with this for more or less lag ;)
	ALLEGRO_DISPLAY *boopmaker = al_create_display(90, 90); //bug #1
	display = al_create_display(640, 480);
	
	paddle = al_create_bitmap(32, 32);

	//the next two lines go together
	al_set_target_bitmap(paddle);

	al_clear_to_color(al_map_rgb(255, 0, 255)); //this sets the PADDLE's color!

	al_set_target_bitmap(al_get_backbuffer(display));

	//the event queue is like a bucket where stuff that happens in your game goes
	event_queue = al_create_event_queue();

	//you need to tell the event queue what kinds of stuff to look out for
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0)); //wipe screen

	al_flip_display();

	al_start_timer(timer); //start timer!
	cout << "flag3";

	brick brick1;
	brick brick2;
	brick brick3;
	brick brick4;
	brick brick5;

	brick1.initbrick(10, 20, 10, 20, 150, 60, 500);
	brick2.initbrick(10, 20, 10, 20, 150, 60, 500);
	brick3.initbrick(10, 20, 10, 20, 150, 60, 500);
	brick4.initbrick(10, 20, 10, 20, 150, 60, 500);
	brick5.initbrick(10, 20, 10, 20, 150, 60, 500);


	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			//bounce the square against the sides of the game window
			if (bouncer_x < 0 || bouncer_x > 640 - 32) {
				bouncer_dx = -bouncer_dx;
			}

			if (bouncer_y < 0 || bouncer_y > 480 - 32) {
				bouncer_dy = -bouncer_dy;
			}
			//add the x velocity to the x position, 
			//and the y velocity to the y position
			bouncer_x += bouncer_dx;
			bouncer_y += bouncer_dy;

			if (key[KEY_LEFT] && paddle_x >= 4.0) {
				paddle_x -= 4.0;
			}

			if (key[KEY_RIGHT] && paddle_x <= SCREEN_W - PADDLE_SIZE - 4.0) {
				paddle_x += 4.0;
			}

			redraw = true;
		}
		//I/O section: close game window if x is pressed//////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		//render section/////////////////////////////////////////////////////
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
			al_draw_bitmap(paddle, paddle_x, paddle_y, 0);
			brick1.drawbrick();
			al_flip_display();
		}
	

		
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

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
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

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

	
	}//end game loop
	

	al_flip_display();
	al_rest(15);
	al_destroy_display(boopmaker);
    al_destroy_bitmap(paddle);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

return 0;
}

void brick::initbrick(int x, int y, int x1, int y1, int r, int g, int b) {
	void brick::drawbrick(al_draw_filled_rectangle(xpos, ypos, xpos + 20, ypos +20, al_map_rgb(r, g, b));
}



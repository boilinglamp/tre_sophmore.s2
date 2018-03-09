#include <iostream>
#include <allegro5/allegro.h>

#include<allegro5\allegro_primitives.h>

using namespace std;
class boop {
private:
	int xpos;
	int ra;
	int r;
	int g;
	int b;
	int ypos;
public:
	void initboop(int x, int y, int ra, int r, int g, int b);

};

int main() {
	al_init();

	al_init_primitives_addon();
	ALLEGRO_DISPLAY *boopmaker = al_create_display(90, 90);

	al_clear_to_color(al_map_rgb(0, 0, 0));

	boop boop1;
	boop boop2;
	boop boop3;
	boop boop4;
	boop boop5;

	boop1.initboop(10, 20, 15, 150, 60, 500);
	boop2.initboop(34, 10, 20, 500, 60, 150);
	boop3.initboop(51, 30, 10, 27, 455, 320);
	boop4.initboop(23, 74, 5, 120, 436, 30);
	boop5.initboop(19, 0, 25, 50, 0, 710);

	al_flip_display();
	al_rest(15);
	al_destroy_display(boopmaker);
}

void boop::initboop(int x, int y, int ra, int r, int g, int b) {
al_draw_filled_circle(x, y, ra, al_map_rgb(r, g, b));
}



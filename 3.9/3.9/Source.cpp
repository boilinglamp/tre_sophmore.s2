#include <allegro5\allegro.h>
#include<allegro5/allegro_image.h>
using namespace std;

class Potato {
private:
	int xPos;
	int yPos;
public:
	void initPotato(int x, int y);
	void drawPotato(ALLEGRO_BITMAP *image);
};

int main() {
	ALLEGRO_DISPLAY *display = NULL;
	al_init();
	al_init_image_addon();

	display = al_create_display(900, 750);
	ALLEGRO_BITMAP *cute_potato = al_load_bitmap("vegitable.jpg");

	al_clear_to_color(al_map_rgb(255, 255, 255));
	Potato p1;
	Potato p2;

	p1.initPotato(200, 400);
	p2.initPotato(600, 100);
	while (1) {
		al_rest(.5);
		p1.drawPotato(cute_potato);
		p2.drawPotato(cute_potato);


		al_flip_display();
	}
	al_rest(15);

	al_destroy_display(display);
}

void Potato::initPotato(int x, int y) {
	xPos = x;
	yPos = y;

}
void Potato::drawPotato(ALLEGRO_BITMAP *image) {
	al_draw_bitmap(image, rand() % 900, rand() % 750, 0);
}
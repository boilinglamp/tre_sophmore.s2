#include <allegro5\allegro.h>
#include<allegro5/allegro_image.h>

using namespace std;
int main() {
	ALLEGRO_DISPLAY *display = NULL;
	al_init();
	al_init_image_addon();

	display = al_create_display(900, 750);
	ALLEGRO_BITMAP *cute_potato = al_load_bitmap("potato.jpg");

	al_clear_to_color(al_map_rgb(255,255,255));
	
	al_draw_bitmap(cute_potato, 50, 100, 0);

	al_flip_display();

	al_rest(15);
	
	al_destroy_display(display);
}
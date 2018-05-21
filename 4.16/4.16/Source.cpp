#include <allegro5\allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>

using namespace std;

int main() {
	
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	
	cout << "baby flag boi" << endl;
	
	ALLEGRO_DISPLAY *display = al_create_display(1000, 800);
	ALLEGRO_FONT *font = al_load_ttf_font("chintzy.ttf", 72, 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("METALORD.ttf", 72, 0);
	
	cout << "flag boi" << endl;
	if (font == NULL)
		cout << "You fool" << endl;
	
	al_clear_to_color(al_map_rgb(50, 10, 70));
	al_draw_text(font, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_LEFT, "jk fools");
	al_draw_text(font2, al_map_rgb(0, 155, 25), 20, 50, ALLEGRO_ALIGN_LEFT, "SHAKADOOO!");
	al_flip_display();
	al_rest(50);
	
	cout << "flag boi 2" << endl;
	
	al_destroy_display(display);
}
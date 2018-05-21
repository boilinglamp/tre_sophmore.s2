//Implement the “What is Love” gif using Allegro and pictures of your friends.To get the circular motion of the faces, you’ll need the following parametric equations controlling the bitmaps in the timer section of your
//game loop :
//X = a + cos(angle)*radius;
//Y = b + sin(angle)*radius;
//I added a delay system to keep the circles from moving too quickly :
//if (delay % 5 == 0)
//angle++;
//delay++;
//You can personalize this assignment, but you need at least 3 moving circles.Your project should have a background image and music.

#include <allegro5/allegro.h>
#include<allegro5\allegro_acodec.h>
#include<allegro5\allegro_audio.h>
#include<allegro5\allegro_image.h>

const float FPS = 100;
const int SCREEN_W = 1000;
const int SCREEN_H = 1000;

using namespace std;

int main() {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_SAMPLE *sample = NULL;

	al_init();

	al_install_audio();
	al_init_acodec_addon();

	al_reserve_samples(1);

	sample = al_load_sample("takeonme.wav");

	al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	al_rest(99999999999);













}



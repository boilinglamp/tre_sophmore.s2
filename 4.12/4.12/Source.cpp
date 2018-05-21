//Create a jukebox program that gives a user a menu of at least 4 songs, and then actually plays them when the user selects one.The program should repeat and ask the user again for another song once each 
//song is finished, until the user types ‘q’.

#include <allegro5\allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int input;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_SAMPLE *sample2 = NULL;
	ALLEGRO_SAMPLE *sample3 = NULL;
	ALLEGRO_SAMPLE *sample4 = NULL;
	ALLEGRO_SAMPLE *sample5 = NULL;
	ALLEGRO_SAMPLE *sample6 = NULL;

	al_init();

	al_install_audio();
	al_init_acodec_addon();

	al_reserve_samples(5);

	sample = al_load_sample("the day.wav");
	sample2 = al_load_sample("peacesign.wav");
	sample3 = al_load_sample("soraniutaeba.wav");
	sample4 = al_load_sample("season3.wav");
	sample5 = al_load_sample("attackontitan.wav");
	sample6 = al_load_sample("tokyoghoul.wav");
	//sample7 = al_load_sample(".wav");
	//sample8 = al_load_sample(".wav");
	//sample9 = al_load_sample(".wav");
	//sample10 = al_load_sample(".wav");
	
	cout << "what anime opening do you want to listen to: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10" << endl;
		cin >> input;

		if (input == 1) {
			al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			al_rest(5);
		}
		else if (input==2)
		{
			al_play_sample(sample2, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			al_rest(5);
		}
		else if (input==3)
		{
			al_play_sample(sample3, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			al_rest(5);
		}
		else if (input ==4)
		{
			al_play_sample(sample4, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			al_rest(5);
		}
		else if (input == 5)
		{
			al_play_sample(sample5, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			al_rest(5);
		}
		else if (input == 6)
		{
			al_play_sample(sample6, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			al_rest(5);
		}
		/*else if (input == 7)
		{
			al_play_sample(sample7, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			al_rest(5);
		}
		else if (input == 8)
		{
			al_play_sample(sample8, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			al_rest(5);
		}
		else if (input == 9)
		{
			al_play_sample(sample9, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			al_rest(5);
		}
		else if (input == 10)
		{
			al_play_sample(sample10, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			al_rest(5);
		}*/

		system("PAUSE");


}
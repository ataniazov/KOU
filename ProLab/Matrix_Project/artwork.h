#ifndef ARTWORK_H_INCLUDED
#define ARTWORK_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

#define ALLEGRO_STATICLINK

#include <allegro5/allegro.h>

// Yazi tipi icin kutuphane
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// CIKIS Mesaji icin kutuphane
#include <allegro5/allegro_native_dialog.h>

#include <allegro5/allegro_primitives.h>

// Pencere uzunlugu ve buyuklugu
#define SCRN_WEIGHT 640
#define SCRN_HEIGHT 480

void abort_game(const char* message);
void init_allegator(void);
void kill_allegator(void);
void game_loop(void);

#endif // ARTWORK_H_INCLUDED

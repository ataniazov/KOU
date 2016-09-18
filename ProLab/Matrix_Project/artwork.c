/**
 * Allegro 5 library kontrol fonksiyonlari
 */

#include "artwork.h"


bool done;
ALLEGRO_EVENT_QUEUE* event_queue;
ALLEGRO_TIMER* timer;
ALLEGRO_DISPLAY* display;
ALLEGRO_FONT* djvfont;

// Yazi tipini belirliyorus


void abort_game(const char* message)
{
    printf("%s \n", message);
    exit(1);
}

void init_allegator(void)
{
    if (!al_init())
        abort_game("Failed to initialize allegro");

    if (!al_install_keyboard())
        abort_game("Failed to install keyboard");

    timer = al_create_timer(1.0 / 60);
    if (!timer)
        abort_game("Failed to create timer");

    al_set_new_display_flags(ALLEGRO_WINDOWED);
    display = al_create_display(SCRN_WEIGHT, SCRN_HEIGHT);
    if (!display)
        abort_game("Failed to create display");

    //al_set_window_position(display, 200, 100);

    // Penceremize title ekliyorus
    al_set_window_title(display,"Prolab 1");

    // Yazi tipilerinin ayarlanmasi
    al_init_font_addon();

    if (!al_init_ttf_addon())
        abort_game("Failed to initialize ttf addon");

    djvfont = al_load_font("DejaVuSansMono-Bold.ttf", 20, NULL);

    event_queue = al_create_event_queue();
    if (!event_queue)
        abort_game("Failed to create event queue");

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));

    done = false;
}

void kill_allegator(void)
{
    if (timer)
        al_destroy_timer(timer);

    if (display)
        al_destroy_display(display);

    if (event_queue)
        al_destroy_event_queue(event_queue);
}

void game_loop(void)
{
    bool redraw = true;
    al_start_timer(timer);

    while (!done) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
            //update_logic();
        } else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                if(al_show_native_message_box(display,"Çıkış Mesajı","Çıkış Mesajı:","Çıkmak İstediğinizden Eminmisiniz?",NULL,ALLEGRO_MESSAGEBOX_QUESTION | ALLEGRO_MESSAGEBOX_YES_NO)) {
                    done = true;
                }
            }


            //get_user_input();
        } else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            if(al_show_native_message_box(display,"Çıkış Mesajı","Çıkış Mesajı:","Çıkmak İstediğinizden Eminmisiniz?",NULL,ALLEGRO_MESSAGEBOX_QUESTION | ALLEGRO_MESSAGEBOX_YES_NO)) {
                done = true;
            }
        }

        if (redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;

            al_clear_to_color(al_map_rgb(75, 0, 130));
            //update_graphics();
            al_draw_text(djvfont, al_map_rgb(255, 255, 255), 0, 0, ALLEGRO_ALIGN_LEFT, "Kare matrisin boyutunu giriniz [4,16]:");
            al_draw_text(djvfont, al_map_rgb(255, 255, 255), 0, 22, ALLEGRO_ALIGN_LEFT, "Martis elemanlarini giriniz:");
            //al_draw_pixel(100,100,al_map_rgb(255,255,255));
            //al_draw_line(2, 1, 6, 1, al_map_rgb(255,255,255), 2);
            al_flip_display();
        }
    }
}


#ifndef STAGE_H // include guard
#define STAGE_H

#include <vector>
#include "game_body.h"

class Stage{
    public:
        Stage(const int width, const int height);
        int init();
        int destroy();
        void show_err(int msg);
        void set_up_stage1();
        void start_stage1();
        void update_stage1(ALLEGRO_EVENT event);
        void start_stage2();
        void update_stage2(ALLEGRO_EVENT event);
        void start_stage3();
        void update_stage3(ALLEGRO_EVENT event);

        int _stage();
        int _window();
        Role *_hero();
        Role *_client();
        ALLEGRO_EVENT_QUEUE *_event_queue();
        ALLEGRO_DISPLAY *_display();
        ALLEGRO_SAMPLE *_song();
        ALLEGRO_FONT *_font();
        ALLEGRO_BITMAP *_background();
    protected:
        int width;
        int height;
        int window;
        int stage;
        Role *hero;
        Role *client;
        ALLEGRO_EVENT_QUEUE *event_queue;
        ALLEGRO_DISPLAY *display;
        ALLEGRO_SAMPLE *song;
        ALLEGRO_FONT *font;
        ALLEGRO_BITMAP *background;

};
#endif

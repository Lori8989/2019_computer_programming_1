
#ifndef STAGE_H // include guard
#define STAGE_H

#include <vector>
#include "game_body.h"

class Stage{
    public:
        Stage(const int width, const int height);
        int init();
        int terminate();
        int destroy();
        void show_err(int msg);
        void main_page();
        void page(int is_win, char *img_path);
        void run();
        int is_current_level_over();
        int set_window(int window_code, int is_conti_update);
        int updater(ALLEGRO_EVENT event);
        int set_game_over();
        void set_up_stage1();
        void show_stage1();
        void set_up_stage2();
        void show_stage2();

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
        int is_terminate;
        int is_continue_update;
        int is_able_next_page;
        Role *hero;
        Role *client;
        ALLEGRO_EVENT_QUEUE *event_queue;
        ALLEGRO_DISPLAY *display;
        ALLEGRO_SAMPLE *song;
        ALLEGRO_FONT *font;
        ALLEGRO_BITMAP *background;

};
#endif

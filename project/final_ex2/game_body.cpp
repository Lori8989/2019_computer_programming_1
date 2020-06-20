#include <stdio.h>
#include <stdlib.h>
// #include <cstdlib>
// #include <ctime>
// #include <time.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "game_body.h"

Role::Role(int hp, int atk1, int atk2, int pos_x, int pos_y, int move_unit, double fps, int width, int height, ALLEGRO_EVENT_QUEUE *event_queue, char *role_img_path){
    this->hp = hp;
    this->atk1 = atk1;
    this->atk2 = atk2;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->move_unit = move_unit;
    this->fps = fps;
    this->width = width;
    this->height = height;
    this->event_queue = event_queue;
    this->event_timer = al_create_timer(fps);
    this->role_img_path = role_img_path;
    this->role_bitmap = al_load_bitmap(role_img_path);

    al_register_event_source(event_queue, al_get_timer_event_source(this->event_timer));
    al_start_timer(this->event_timer);
}

void Role::go_up(){this->pos_y -= this->move_unit;}
void Role::go_down(){this->pos_y += this->move_unit;}
void Role::go_left(){this->pos_x -= this->move_unit;}
void Role::go_right(){this->pos_x += this->move_unit;}
void Role::random_walk(){
    // srand( time(NULL) );
    // this->pos_x = rand() % 800;
    // srand( time(NULL) );
    // this->pos_y = rand() % this->height;
}
void Role::lose_hp(int lose){this->hp -= lose;}
bool Role::update_keyboard_event(ALLEGRO_EVENT event){
    if(event.type == ALLEGRO_EVENT_KEY_UP){
        switch(event.keyboard.keycode){
            case ALLEGRO_KEY_UP:
                this->go_up();
                break;
            case ALLEGRO_KEY_DOWN:
                this->go_down();
                break;
            case ALLEGRO_KEY_LEFT:
                this->go_left();
                break;
            case ALLEGRO_KEY_RIGHT:
                this->go_right();
                break;
        }
    }
}
bool Role::update_timer_event(ALLEGRO_EVENT event){
    // ALLEGRO_EVENT event;
    // al_wait_for_event(this->event_queue, event);
    // ALLEGRO_TIMER *a = event.timer.source;
    if(event.timer.source == this->event_timer){
        // this->random_walk();
        // printf("%d %d\n", this->pos_x, this->pos_y);
        this->go_down();
    }
}
void Role::show(){al_draw_bitmap(this->role_bitmap, this->pos_x, this->pos_y, 0);}

int Role::_hp(){return this->hp;}
int Role::_atk1(){return this->atk1;}
int Role::_atk2(){return this->atk2;}
int Role::_pos_x(){return this->pos_x;}
int Role::_pos_y(){return this->pos_y;}
int Role::_move_unit(){return this->move_unit;}
double Role::_fps(){return this->fps;}
char *Role::_role_img_path(){return this->role_img_path;}
ALLEGRO_EVENT_QUEUE *Role::_event_queue(){return this->event_queue;}
ALLEGRO_TIMER *Role::_event_timer(){return this->event_timer;}
ALLEGRO_BITMAP *Role::_role_bitmap(){return this->role_bitmap;}


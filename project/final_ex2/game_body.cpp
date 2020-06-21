#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "game_body.h"

Attack::Attack(int atk, int speed, double fps, int width, int height, char *atk_img_path, ALLEGRO_EVENT_QUEUE *event_queue){
    this->atk = atk;
    this->speed = speed;
    this->fps = fps;
    this->width = width;
    this->height = height;
    this->atk_img_path = atk_img_path;

    this->event_timer = al_create_timer(fps);
    this->atk_bitmap = al_load_bitmap(atk_img_path);

    al_register_event_source(event_queue, al_get_timer_event_source(this->event_timer));
    al_start_timer(this->event_timer);
}
void Attack::move(int x_dir, int y_dir){
    for(int i = 0; i < this->pos_ys.size(); i++){
        if(x_dir == 1){
            this->pos_xs.at(i) += this->speed;
        }else if(x_dir == -1){
            this->pos_xs.at(i) -= this->speed;
        }
        if(y_dir == 1){
            this->pos_ys.at(i) += this->speed;
        }else if(y_dir == -1){
            this->pos_ys.at(i) -= this->speed;
        }

        if(this->pos_ys.at(i) > this->height || this->pos_xs.at(i) > this->width || this->pos_ys.at(i) < 0 || this->pos_xs.at(i) < 0){
            this->pos_xs.erase(this->pos_xs.begin() + i);
            this->pos_ys.erase(this->pos_ys.begin() + i);
        }
    }
}

void Attack::add(int pos_x, int pos_y){
    this->pos_xs.push_back(pos_x);
    this->pos_ys.push_back(pos_y);
}

int Attack::hit(int pos_x, int pos_y, int r){
    int accum_atk = 0;
    for(int i = 0; i < this->pos_ys.size(); i++){
        int  dis = (this->pos_xs.at(i) - pos_x) * (this->pos_xs.at(i) - pos_x) + (this->pos_ys.at(i) - pos_y) * (this->pos_ys.at(i) - pos_y);
        if(dis <= r * r){
            accum_atk += this->atk;
            this->disappear(i);
        }
    }
    return accum_atk;
}
bool Attack::update_timer_event(ALLEGRO_EVENT event){
    if(event.timer.source == this->event_timer){
        this->move(0, -1);
        return 1;
    }
    return 0;
}
void Attack::show(){
    for(int i = 0; i < this->pos_xs.size(); i++){
        al_draw_bitmap(this->atk_bitmap, this->pos_xs.at(i), this->pos_ys.at(i), 0);
    }
}
void Attack::disappear(int idx){
    this->pos_xs.erase(this->pos_xs.begin() + idx);
    this->pos_ys.erase(this->pos_ys.begin() + idx);
}


Role::Role(int hp, int atk1, int atk2, int pos_x, int pos_y, int move_unit, double fps, int width, int height, ALLEGRO_EVENT_QUEUE *event_queue, char *role_img_path){
    this->hp = hp;
    this->is_alive = 1;
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
    this->atks1 = new Attack(atk1, move_unit, fps, width, height, "explosion.png", event_queue);
    this->role_bitmap = al_load_bitmap(role_img_path);

    al_register_event_source(event_queue, al_get_timer_event_source(this->event_timer));
    al_start_timer(this->event_timer);
}

void Role::go_up(){
    if(this->is_alive){this->pos_y -= this->move_unit;}
}
void Role::go_down(){
    if(this->is_alive){this->pos_y += this->move_unit;}
}
void Role::go_left(){
    if(this->is_alive){this->pos_x -= this->move_unit;}
}
void Role::go_right(){
    if(this->is_alive){this->pos_x += this->move_unit;}
}
void Role::random_walk(){
    if(this->is_alive){
        this->pos_x = rand() %this->width;
        this->pos_y = rand() % this->height;
    }
}
void Role::fire1(){
    if(this->is_alive){this->atks1->add(this->pos_x, this->pos_y);}
}
void Role::lose_hp(int lose){
    if(this->is_alive){this->hp -= lose;}
    if(this->hp <= 0){this->die();}
}
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
            case ALLEGRO_KEY_A:
                this->fire1();
                break;
        }
    }
}
bool Role::update_atks_event(ALLEGRO_EVENT event, Role *enemy){
    int res = this->atks1->update_timer_event(event);
    enemy->lose_hp(this->atks1->hit(enemy->pos_x, enemy->pos_y, 50));
    return res;
}bool Role::update_timer_event(ALLEGRO_EVENT event){
    if(event.timer.source == this->event_timer){
        this->random_walk();
        return 1;
    }
    return 0;
}
void Role::show(){
    if(this->is_alive){
        al_draw_bitmap(this->role_bitmap, this->pos_x, this->pos_y, 0);
    }
    this->atks1->show();
}
void Role::die(){
    this->pos_x = -100;
    this->pos_y = -100;
    this->is_alive = 0;
}
int Role::_hp(){return this->hp;}
int Role::_is_alive(){return this->is_alive;}
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


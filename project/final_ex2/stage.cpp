
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

#include "stage.h"
#include "game_body.h"

Stage::Stage(const int width, const int height){
    this->width = width;
    this->height = height;
    this->window = 0;
    this->is_terminate = 0;
    this->is_continue_update = 1;
    this->is_able_next_page = 1;
    this->stage = 1;

    this->hero = NULL;
    this->client = NULL;
    this->hero = NULL;
    this->client = NULL;
    this->event_queue = NULL;
    this->display = NULL;
    this->song = NULL;
    this->font = NULL;
    this->background = NULL;
}
int Stage::init(){
    if (!al_init()) {
        this->show_err(-1);
    }
    if(!al_install_audio()){
        fprintf(stderr, "failed to initialize audio!\n");
        this->show_err(-2);
    }
    if(!al_init_acodec_addon()){
        fprintf(stderr, "failed to initialize audio codecs!\n");
        this->show_err(-3);
    }
    if (!al_reserve_samples(1)){
        fprintf(stderr, "failed to reserve samples!\n");
        this->show_err(-4);
    }
    // Create display
    this->display = al_create_display(this->width, this->height);
    this->event_queue = al_create_event_queue();
    if (this->display == NULL || this->event_queue == NULL) {
        this->show_err(-5);
    }
    // Initialize Allegro settings
    al_set_window_position(this->display, 0, 0);
    al_set_window_title(this->display, "title");
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_audio();
    al_init_image_addon();
    al_init_acodec_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    // Register event
    al_register_event_source(this->event_queue, al_get_display_event_source(this->display));
    al_register_event_source(this->event_queue, al_get_keyboard_event_source());
}
int Stage::terminate(){
    this->is_terminate = 1;
    return 1;
}
int Stage::destroy(){
    // Make sure you destroy all things
    al_destroy_event_queue(this->event_queue);
    al_destroy_display(this->display);
    //al_destroy_timer(timer);
    //al_destroy_timer(timer2);
    //al_destroy_bitmap(image);
    al_destroy_sample(this->song);
    al_destroy_font(this->font);
}
void Stage::show_err(int msg){
    fprintf(stderr, "unexpected msg: %d\n", msg);
    this->destroy();
    exit(9);
}
void Stage::main_page(){
    printf("Here is main_page\n");

    // Load sound
    /**
    song = al_load_sample( "hello.wav" );
    if (!song){
        printf( "Audio clip sample not loaded!\n" );
        // show_err_msg(-6);
    }**/
    // Loop the song until the display closes
    // al_play_sample(song, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
    al_clear_to_color(al_map_rgb(100,100,100));
    // Load and draw text
    this->font = al_load_ttf_font("pirulen.ttf",12,0);
    al_draw_text(this->font, al_map_rgb(255,255,255), this->width/2, this->height/2+100 , ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start");
    al_draw_text(this->font, al_map_rgb(255,255,255), this->width/2, this->height/2+150 , ALLEGRO_ALIGN_CENTRE, "Press 'Esc' to exit");
    al_draw_text(this->font, al_map_rgb(255,255,255), this->width/2, this->height/2+200 , ALLEGRO_ALIGN_CENTRE, "Press 'Q' for more detail");
    al_draw_rectangle(this->width/2-150, this->height/2+88, this->width/2+150, this->height/2+124, al_map_rgb(255, 255, 255), 0);
    al_draw_rectangle(this->width/2-150, this->height/2+138, this->width/2+150, this->height/2+174, al_map_rgb(255, 255, 255), 0);
    al_draw_rectangle(this->width/2-150, this->height/2+188, this->width/2+150, this->height/2+224, al_map_rgb(255, 255, 255), 0);

    al_flip_display();
}
void Stage::page(int is_win, char *img_path){
    al_draw_rectangle(this->width/2-150, this->height/2+88, this->width/2+150, this->height/2+124, al_map_rgb(255, 255, 255), 0);
    al_draw_rectangle(this->width/2-150, this->height/2+138, this->width/2+150, this->height/2+174, al_map_rgb(255, 255, 255), 0);
    al_draw_rectangle(this->width/2-150, this->height/2+188, this->width/2+150, this->height/2+224, al_map_rgb(255, 255, 255), 0);

    al_flip_display();
}
int Stage::is_current_level_over(){
    return !(this->hero->_is_alive() && this->client->_is_alive());
}
void Stage::run(){
    while(!this->is_terminate){
        if(this->is_continue_update){
            if(this->window == 0){
                // Main Page
                this->main_page();
                this->set_up_stage1();

                this->is_continue_update = 0;
                this->is_able_next_page = 1;
            }else if(this->window == 1){
                // Level 1 Gaming
                //this->set_up_stage1();
                this->is_continue_update = 1;
                this->is_able_next_page = 0;

                if(!this->is_current_level_over()){
                    this->show_stage1();
                }else{
                    this->set_window(this->window+1, 1);
                }
            }else if(this->window == 2){
                // Level 1 Finished
                this->is_continue_update = 0;
                this->is_able_next_page = 1;

                this->page(1, "hi");
                this->set_up_stage2();
            }else if(this->window == 3){
                // Level 2 Gaming
                this->is_continue_update = 1;
                this->is_able_next_page = 0;

                if(!this->is_current_level_over()){
                    this->show_stage2();
                }else{
                    this->set_window(this->window+1, 1);
                }
            }else{
                this->main_page();
            }
        }



        if (!al_is_event_queue_empty(this->event_queue)) {
            //error = process_event();
            ALLEGRO_EVENT event;
            al_wait_for_event(this->event_queue, &event);
            updater(event);
        }

    }

    this->destroy();
}

int Stage::set_window(int window_code, int is_conti_update){
    printf("%d %d\n", window_code, is_conti_update);
    this->window = window_code;
    this->is_continue_update = is_conti_update;
}
int Stage::updater(ALLEGRO_EVENT event){
    //printf("Is_terminate: %d\n", this->is_terminate);
    if(this->client != NULL){
        this->client->fire1();
        this->client->update_random_walk_event(event);
        this->client->update_horizontal_walk_event(event);
        this->client->update_atks_event(event, this->hero);
    }

    if(this->hero != NULL){
        this->hero->update_keyboard_event(event);
        this->hero->update_atks_event(event, this->client);
    }

    if(event.type == ALLEGRO_EVENT_KEY_UP){
        switch(event.keyboard.keycode){
            // For Start Menu
            case ALLEGRO_KEY_ENTER:
                //game->set_to_start_stage1();
                //judge_next_window = true;
                //this->window++;
                if(this->is_able_next_page){
                    this->set_window(this->window+1, 1);
                }
                break;
            case ALLEGRO_KEY_ESCAPE:
                int res = this->set_game_over();
                return res;
                break;
        }
    }

    // Shutdown our program
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        int res = this->set_game_over();
        return res;
    }

    return 0;

}
int Stage::set_game_over(){
    this->is_terminate = 1;
    return 1;
}
void Stage::set_up_stage1(){
    //this->window = 1;
    //this->stage = 1;
    this->hero = new Role(100, 100, 200, 0, -1, this->width/2, this->height/2+100, 30, 0.1, this->width, this->height, this->event_queue, "tower.png", "pipi.png", "pupu.png");
    this->client = new Role(100, 100, 200, 0, 1, this->width/2, this->height/5, 10, 0.1, this->width, this->height, this->event_queue, "teemo_right.png", "pipi.png", "pupu.png");
    this->background = al_load_bitmap("stage.jpg");

}
void Stage::set_up_stage2(){
    //this->window = 1;
    //this->stage = 1;
    this->hero = new Role(100, 100, 200, 0, -1, this->width/2, this->height/2+100, 30, 0.1, this->width, this->height, this->event_queue, "tower.png", "pipi.png", "pupu.png");
    this->client = new Role(100, 100, 200, 0, 1, this->width/2, this->height/5, 10, 0.1, this->width, this->height, this->event_queue, "teemo_right.png", "pipi.png", "pupu.png");
    this->background = al_load_bitmap("stage.jpg");

}
void Stage::show_stage1(){
    al_draw_bitmap(this->background, 0,0, 0);
    this->hero->show();
    this->client->show();

    al_flip_display();
    //al_clear_to_color(al_map_rgb(0,0,0));
}
void Stage::show_stage2(){
    al_draw_bitmap(this->background, 0,0, 0);
    this->hero->show();
    this->client->show();

    al_flip_display();
    //al_clear_to_color(al_map_rgb(0,0,0));
}






void Stage::start_stage1(){
    //if(this->window != 1 || this->stage != 1){return;}
    this->hero = new Role(100, 100, 200, 0, -1, width/2, height/2+100, 30, 0.1, width, height, event_queue, "tower.png", "pipi.png", "pupu.png");
    this->client = new Role(100, 100, 200, 0, -1, width/2, height/5, 10, 0.1, width, height, event_queue, "teemo_right.png", "pipi.png", "pupu.png");
    // this->hero = new Role(100, 100, 200, this->width/2, this->height/2+100, 30, 0.1, this->width, this->height, this->event_queue, "tower.png");
    // this->client = new Role(100, 100, 200, this->width/2, this->height/5, 10, 0.1, this->width, this->height, this->event_queue, "teemo_right.png");

    al_clear_to_color(al_map_rgb(200,200,200));
    // Load and draw text
    //al_draw_text(this->font, al_map_rgb(255,255,255), width/2, height/2+100 , ALLEGRO_ALIGN_CENTRE, "Press 'Space' to start next level");
    al_draw_rectangle(this->width/2-150, this->height/2+88, this->width/2+150, this->height/2+124, al_map_rgb(255, 255, 255), 0);
    al_flip_display();
}

void Stage::update_stage1(ALLEGRO_EVENT event){
    if(this->window != 2 || this->stage != 1){return;}
    this->background = al_load_bitmap("stage.jpg");
    al_draw_bitmap(this->background, 0, 0, 0);
    this->hero->show();
    this->client->show();

    al_flip_display();
    al_clear_to_color(al_map_rgb(0, 0, 0));

    if(this->hero != NULL){
        this->hero->update_keyboard_event(event);
        this->hero->update_atks_event(event, this->client);
    }

    if(this->client != NULL){
        this->client->fire1();
        this->client->update_random_walk_event(event);
        this->client->update_atks_event(event, this->hero);
    }
}





int Stage::_stage(){return this->stage;};
int Stage::_window(){return this->window;};
Role *Stage::_hero(){return this->hero;};
Role *Stage::_client(){return this->client;};
ALLEGRO_EVENT_QUEUE *Stage::_event_queue(){return this->event_queue;}
ALLEGRO_DISPLAY *Stage::_display(){return this->display;}
ALLEGRO_SAMPLE *Stage::_song(){return this->song;};
ALLEGRO_FONT *Stage::_font(){return this->font;};
ALLEGRO_BITMAP *Stage::_background(){return this->background;};

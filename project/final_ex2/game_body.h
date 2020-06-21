
#ifndef GAME_BODY_H // include guard
#define GAME_BODY_H

#include <vector>

class Attack{
    public:
        Attack(int atk, int speed, double fps, int width, int height, char *atk_img_path, ALLEGRO_EVENT_QUEUE *event_queue);
        void move(int x_dir, int y_dir);
        void add(int pos_x, int pos_y);
        int hit(int pos_x, int pos_y, int r);
        bool update_timer_event(ALLEGRO_EVENT even);
        void show();
        void disappear(int idx);
    protected:
        int atk;
        int n;
        int speed;
        double fps;
        int width;
        int height;
        char *atk_img_path;
        std::vector<int> pos_xs;
        std::vector<int> pos_ys;
        ALLEGRO_TIMER *event_timer;
        ALLEGRO_BITMAP *atk_bitmap;
};

class Role{
    public:
        Role(int hp, int atk1, int atk2, int pos_x, int pos_y, int move_unit, double fps, int width, int height, ALLEGRO_EVENT_QUEUE *event_queue, char *role_img_path);
        void go_up();
        void go_down();
        void go_left();
        void go_right();
        void random_walk();
        void fire1();
        void fire2();
        void lose_hp(int lose);
        bool update_keyboard_event(ALLEGRO_EVENT event);
        bool update_atks_event(ALLEGRO_EVENT event, Role *enemy);
        bool update_timer_event(ALLEGRO_EVENT event);
        void show();
        void die();

        int _hp();
        int _is_alive();
        int _atk1();
        int _atk2();
        int _pos_x();
        int _pos_y();
        int _move_unit();
        double _fps();
        char *_role_img_path();
        ALLEGRO_EVENT_QUEUE *_event_queue();
        ALLEGRO_TIMER *_event_timer();
        ALLEGRO_BITMAP *_role_bitmap();
    protected:
        int hp;
        int is_alive;
        int atk1;
        int atk2;
        int pos_x;
        int pos_y;
        int move_unit;
        double fps;
        int width;
        int height;
        char *role_img_path;
        Attack *atks1;
        ALLEGRO_EVENT_QUEUE *event_queue;
        ALLEGRO_TIMER *event_timer;
        ALLEGRO_BITMAP *role_bitmap;
};

class Game_Body{
    public:
        Game_Body();
        void stage1();
        void stage2();
        void stage3();

    private:
        int window;
        int stage;
        Role *hero;

};

#endif

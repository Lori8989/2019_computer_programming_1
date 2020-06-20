
#ifndef GAME_BODY_H // include guard
#define GAME_BODY_H

class Attack{
    public:
        Attack();
};

class Role{
    public:
        Role(int hp, int atk1, int atk2, int pos_x, int pos_y, int move_unit, double fps, int width, int height, ALLEGRO_EVENT_QUEUE *event_queue, char *role_img_path);
        void go_up();
        void go_down();
        void go_left();
        void go_right();
        void random_walk();
        void lose_hp(int lose);
        bool update_keyboard_event(ALLEGRO_EVENT event);
        bool update_timer_event(ALLEGRO_EVENT event);
        void show();
        int _hp();
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
        int atk1;
        int atk2;
        int pos_x;
        int pos_y;
        int move_unit;
        double fps;
        int width;
        int height;
        char *role_img_path;
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

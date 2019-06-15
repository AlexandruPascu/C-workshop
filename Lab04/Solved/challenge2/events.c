#include <allegro5/allegro.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600
#define TARGET_FPS 60.0

int main() {
    al_init();
    al_install_keyboard();
    al_install_mouse();

    ALLEGRO_DISPLAY *display = al_create_display(WIDTH, HEIGHT);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    ALLEGRO_TIMER *timer = al_create_timer(1 / TARGET_FPS);
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    int run = 1;
    while (run) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            puts("exiting...");
            run = 0;
        } 

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            puts("key down");
        }

        if (event.type == ALLEGRO_EVENT_KEY_UP) {
            puts("key up");
        }

        if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
            puts("mouse moved");
        }

        if (event.type == ALLEGRO_EVENT_TIMER) {
            puts("timer");
        }
    }


    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    return 0;
}

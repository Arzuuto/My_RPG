/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef MENU__H__
#define MENU__H__

#include "window.h"
#include "create.h"
#include "my.h"

typedef struct menu_s {
    object_t **sp;
    object_t **bg;
    object_t **how;
    object_t **opt;
    text_t **txt;
    text_t **txt_opt;
    sound_t **audio;
    sfClock *clock;
    sfMusic *music;
    int status;
} menu_t;

object_t **create_menu_bg(void);
menu_t *create_menu(window_t *wind);
int button_leftclick_is_clicked(object_t *sp, window_t *wind, sfColor color);
int button_rightclick_is_clicked(object_t *sp, window_t *wind, sfColor color);
int button_is_touched(object_t *sp, text_t *txt, window_t *wind);
menu_t *animate_how_button(menu_t *menu, window_t *wind);
menu_t *animate_quit_button(menu_t *menu, window_t *wind);
float get_seconds(sfClock *clock);
object_t **create_menu_how();
menu_t *display_howto(menu_t *menu, window_t *wind);
menu_t *animate_back_button(menu_t *menu, window_t *wind);
void display_sp_howto(object_t **sp, text_t **txt, window_t *wind);
menu_t *animate_settings_button(menu_t *menu, window_t *wind);
menu_t *animate_back_opt_button(menu_t *menu, window_t *wind);
object_t **create_menu_opt(void);
char *my_itoa(int nb);
menu_t *create_pause(menu_t *menu, int fps, window_t *wind);
void display_menu_bg(object_t **bg, window_t *wind);
void display_menu_sp(object_t **sp,
 __attribute__((unused))object_t **bg, window_t *wind);
void display_txt_sp(text_t **txt, window_t *wind);
menu_t *display_howto_pause(menu_t *pause, window_t *wind);
int check_button_pause(void);
#endif/*MENU__H__*/

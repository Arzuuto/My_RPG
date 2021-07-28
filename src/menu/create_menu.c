/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_menu.c
*/

#include "game.h"
#include "menu.h"
#include "create.h"
#include "window.h"
#include <stdlib.h>

static text_t **create_menu_txt(void)
{
    text_t **txt = malloc(sizeof(text_t *) * 7);

    txt[0] = create_text("assets/f.ttf");
    set_text(txt[0], 80, (sfVector2f) {810, 295}, "PLAY");
    txt[1] = create_text("assets/f.ttf");
    set_text(txt[1], 80, (sfVector2f) {695, 445}, "HOW TO PLAY");
    txt[2] = create_text("assets/f.ttf");
    set_text(txt[2], 80, (sfVector2f) {810, 595}, "QUIT");
    txt[3] = create_text("assets/f.ttf");
    set_text(txt[3], 200, (sfVector2f) {650, 20}, "MY RPG");
    txt[4] = create_text("assets/f.ttf");
    set_text(txt[4], 70, (sfVector2f) {570, 330}, "MOVE");
    txt[5] = create_text("assets/f.ttf");
    set_text(txt[5], 65, (sfVector2f) {1270, 330}, "ATTACK");
    txt[6] = create_text("assets/f.ttf");
    set_text(txt[6], 80, (sfVector2f) {1238, 545}, "BACK");
    return (txt);
}

static object_t **create_menu_sp(window_t *wind)
{
    object_t **sp = malloc(sizeof(object_t *) * 4);

    sp[0] = create_obj("assets/menu/menu_bg.png", (sfVector2f) {0, 0},
                            (sfIntRect) {0, 0, 1920, 1080});
    sp[1] = create_obj("assets/menu/menu.png",
                            (sfVector2f) {wind->window_x / 2.5, 300},
                            (sfIntRect) {1 , 0, 265, 104});
    sp[2] = create_obj("assets/menu/menu.png",
                            (sfVector2f) {680, 450},
                            (sfIntRect) {1 , 118, 443, 104});
    sp[3] = create_obj("assets/menu/menu.png",
                            (sfVector2f) {wind->window_x / 2.5, 600},
                            (sfIntRect) {1 , 241, 265, 104});
    return (sp);
}

sound_t **create_menu_audio(void)
{
    sound_t **audio = malloc(sizeof(sound_t *) * 2);

    audio[0] = create_audio("assets/sounds/click.wav");
    return (audio);
}

menu_t *create_pause(menu_t *menu, int fps, window_t *wind)
{
    menu_t *pause = malloc(sizeof(menu_t) * 1);

    pause->sp = create_menu_sp(wind);
    pause->bg = create_menu_bg();
    pause->txt = create_menu_txt();;
    pause->txt_opt = create_menu_txt_opt(menu, fps);
    pause->opt = create_menu_opt();
    pause->how = create_menu_how();
    pause->audio = create_menu_audio();
    pause->clock = sfClock_create();
    pause->status = 0;
    return (pause);
}

menu_t *create_menu(window_t *wind)
{
    menu_t *menu = malloc(sizeof(menu_t) * 1);

    menu->music = sfMusic_createFromFile("assets/sounds/menu.ogg");
    sfMusic_setVolume(menu->music, 20);
    sfMusic_play(menu->music);
    sfMusic_setLoop(menu->music, sfTrue);
    menu->sp = create_menu_sp(wind);
    menu->bg = create_menu_bg();
    menu->txt = create_menu_txt();;
    menu->opt = create_menu_opt();
    menu->how = create_menu_how();
    menu->audio = create_menu_audio();
    menu->clock = sfClock_create();
    menu->status = 0;
    return (menu);
}
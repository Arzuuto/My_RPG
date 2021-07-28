/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_menu_opt.c
*/

#include <stdlib.h>
#include "menu.h"
#include "game.h"

char *my_itoa(int nb)
{
    char *str;
    int len = 0;
    int j = 0;

    for (int i = nb; i > 9; i /= 10, len += 1);
    str = malloc(sizeof(char) * (len + 2));
    str[len + 1] = '\0';
    j = len;
    for (j = len; j >= 0; j -= 1) {
        str[j] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}

text_t **create_menu_txt_opt(menu_t *menu, int fps)
{
    text_t **txt = malloc(sizeof(text_t *) * 6);
    int menu_bg = sfMusic_getVolume(menu->music);

    txt[0] = create_text("assets/f.ttf");
    set_text(txt[0], 50, (sfVector2f) {270, 60}, "FPS");
    txt[1] = create_text("assets/f.ttf");
    set_text(txt[1], 50, (sfVector2f) {245, 180}, "MUSIC");
    txt[2] = create_text("assets/f.ttf");
    set_text(txt[2], 50, (sfVector2f) {280, 235}, my_itoa(menu_bg));
    txt[3] = create_text("assets/f.ttf");
    set_text(txt[3], 50, (sfVector2f) {280, 115}, my_itoa(fps));
    txt[4] = create_text("assets/f.ttf");
    set_text(txt[4], 80, (sfVector2f) {230, 353}, "back");
    return (txt);
}

object_t **create_menu_opt(void)
{
    object_t **opt = malloc(sizeof(object_t *) * 7);

    opt[0] = create_obj("assets/settings.png", (sfVector2f) {10, 10},
                            (sfIntRect) {0, 0, 64, 60});
    opt[1] = create_obj("assets/box_opt.png", (sfVector2f) {110, 45},
                            (sfIntRect) {20, 20, 400, 450});
    opt[2] = create_obj("assets/menu/menu.png", (sfVector2f) {185, 360},
                            (sfIntRect) {1 , 0, 265, 104});
    opt[3] = create_obj("assets/opt.png", (sfVector2f) {350, 120},
                            (sfIntRect) {467 , 18, 116, 115});
    opt[4] = create_obj("assets/opt.png", (sfVector2f) {350, 240},
                            (sfIntRect) {467 , 18, 116, 115});
    opt[5] = create_obj("assets/opt.png", (sfVector2f) {210, 125},
                            (sfIntRect) {301, 0, 152, 149});
    opt[6] = create_obj("assets/opt.png", (sfVector2f) {210, 245},
                            (sfIntRect) {301, 0, 152, 149});
    return (opt);
}
/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** howto.c
*/

#include "menu.h"

menu_t *animate_back_button(menu_t *menu, window_t *wind)
{
    sfColor brown = sfColor_fromRGB(197, 154, 114);

    button_is_touched(menu->how[3], menu->txt[6], wind);
    if (button_leftclick_is_clicked(menu->how[3], wind, brown) == 1) {
        sfSound_play(menu->audio[0]->sound);
        sfClock_restart(menu->clock);
        menu->status = 0;
    }
    return (menu);
}

void display_sp_howto(object_t **sp, text_t **txt, window_t *wind)
{
    for (int i = 0; i < 4; i += 1)
        sfRenderWindow_drawSprite(wind->window, sp[i]->sprite, NULL);
    sfRenderWindow_drawText(wind->window, txt[4]->text, NULL);
    sfRenderWindow_drawText(wind->window, txt[5]->text, NULL);
    sfRenderWindow_drawText(wind->window, txt[6]->text, NULL);
}

menu_t *display_howto(menu_t *menu, window_t *wind)
{
    if (menu->status == 3) {
        display_sp_howto(menu->how, menu->txt, wind);
        menu = animate_back_button(menu, wind);
        sfSprite_setColor(menu->sp[2]->sprite, sfWhite);
    }
    return (menu);
}

menu_t *animate_back_pause_button(menu_t *menu, window_t *wind)
{
    sfColor brown = sfColor_fromRGB(197, 154, 114);

    button_is_touched(menu->how[3], menu->txt[6], wind);
    if (button_leftclick_is_clicked(menu->how[3], wind, brown) == 1) {
        sfSound_play(menu->audio[0]->sound);
        sfClock_restart(menu->clock);
        menu->status = 1;
    }
    return (menu);
}

menu_t *display_howto_pause(menu_t *pause, window_t *wind)
{
    if (pause->status == 3) {
        display_sp_howto(pause->how, pause->txt, wind);
        pause = animate_back_pause_button(pause, wind);
        sfSprite_setColor(pause->sp[2]->sprite, sfWhite);
    }
    return (pause);
}
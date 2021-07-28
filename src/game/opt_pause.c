/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** opt_pause.c
*/

#include "game.h"

menu_t *display_opt_pause(game_t *game, menu_t *pause, menu_t *menu,
                                                    window_t *wind)
{
    sfRenderWindow_drawSprite(wind->window, pause->opt[0]->sprite, NULL);
    for (int k = 3; k < 5; k += 1) {
        sfSprite_setScale(pause->opt[k]->sprite, (sfVector2f) {0.5, 0.5});
        sfSprite_setScale(pause->opt[k + 2]->sprite, (sfVector2f) {0.35, 0.35});
    }
    if (pause->status == 7) {
        for (int i = 0; i < 7; i += 1)
            sfRenderWindow_drawSprite(wind->window, pause->opt[i]->sprite, NULL);
        for (int j = 0; j < 5; j += 1) {
            sfRenderWindow_drawText(wind->window, menu->txt_opt[j]->text, NULL);
        }
        set_options(game, menu, wind);
        animate_back_opt_button(pause, wind);
    }
    return (menu);
}
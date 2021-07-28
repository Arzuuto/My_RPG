/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** display.pnj.c
*/

#include "window.h"
#include "player.h"
#include "pnj.h"

void display_quest(player_t *player, pnj_t *pnj, window_t *wind)
{
    sfVector2f pos_player = sfSprite_getPosition(player->move[0]->sprite);
    sfVector2f pos_obj = sfSprite_getPosition(pnj->sp[0]->sprite);
    sfIntRect rect_player = sfSprite_getTextureRect(player->move[0]->sprite);
    sfIntRect rect_obj = sfSprite_getTextureRect(pnj->sp[0]->sprite);
    int speed = 15;

    if (NO_SP_AT_RIGHT) {
        sfRenderWindow_drawSprite(wind->window, pnj->sp[2]->sprite, NULL);
        sfRenderWindow_drawText(wind->window, pnj->text->text, NULL);
    }
}

void display_stats(stats_t *player, object_t **hp, window_t *wind)
{
    sfVector2f scale = (sfVector2f) {3, 3};

    for (int j = 0; j < 18; j += 1)
        sfSprite_setScale(hp[j]->sprite, scale);
    for (int i = 0; i < player->hp_max; i += 1)
        sfRenderWindow_drawSprite(wind->window, hp[i + 9]->sprite, NULL);
    for (int i = 0; i < player->hp; i += 1)
        sfRenderWindow_drawSprite(wind->window, hp[i]->sprite, NULL);
}

void play_pnj_animation(pnj_t *pnj, window_t *wind, sfVector2f pos)
{
    sfTime time = sfClock_getElapsedTime(pnj->clock);
    float second = time.microseconds / 1000000.0;

    sfSprite_setPosition(pnj->sp[1]->sprite,
                    (sfVector2f){pos.x, pos.y - 2});
    if (second < 0.80)
    sfRenderWindow_drawSprite(wind->window, pnj->sp[0]->sprite, NULL);
    if (second > 0.75 && second < 1.40)
        sfRenderWindow_drawSprite(wind->window, pnj->sp[1]->sprite, NULL);
    if (second > 1.35)
        sfClock_restart(pnj->clock);
}

/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player_idle.c
*/

#include "window.h"
#include "player.h"

static void play_animation_idle_left(player_t *player, window_t *wind,
                                                        sfVector2f pos)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    float second = time.microseconds / 1000000.0;

    sfSprite_setPosition(player->move[7]->sprite,
                    (sfVector2f){pos.x, pos.y - 2});
    if (second < 0.80)
    sfRenderWindow_drawSprite(wind->window, player->move[5]->sprite, NULL);
    if (second > 0.75 && second < 1.40)
        sfRenderWindow_drawSprite(wind->window, player->move[7]->sprite, NULL);
    if (second > 1.35)
        sfClock_restart(player->clock);
}

static void play_animation_idle_right(player_t *player, window_t *wind,
                                                        sfVector2f pos)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    float second = time.microseconds / 1000000.0;

    sfSprite_setPosition(player->move[3]->sprite,
                    (sfVector2f){pos.x, pos.y - 2});
    if (second < 0.80)
        sfRenderWindow_drawSprite(wind->window, player->move[1]->sprite, NULL);
    if (second > 0.75 && second < 1.40)
        sfRenderWindow_drawSprite(wind->window, player->move[3]->sprite, NULL);
    if (second > 1.35)
        sfClock_restart(player->clock);
}

void play_animation_idle(player_t *player, window_t *wind)
{
    if (player->idle == RIGHT)
        play_animation_idle_right(player, wind, player->pos);
    else
        play_animation_idle_left(player, wind, player->pos);
}
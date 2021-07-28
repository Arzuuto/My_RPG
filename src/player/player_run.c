/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player_run.c
*/

#include "window.h"
#include "player.h"

player_t *play_animation_right(player_t *player, window_t *wind)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    float second = time.microseconds / 1000000.0;

    if (second < 0.075)
        sfRenderWindow_drawSprite(wind->window, player->move[0]->sprite, NULL);
    if (second > 0.070 && second < 0.15)
        sfRenderWindow_drawSprite(wind->window, player->move[1]->sprite, NULL);
    if (second > 0.14 && second < 0.25)
        sfRenderWindow_drawSprite(wind->window, player->move[2]->sprite, NULL);
    if (second > 0.22 && second < 0.3)
        sfRenderWindow_drawSprite(wind->window, player->move[3]->sprite, NULL);
    if (second > 0.26)
        sfClock_restart(player->clock);
    player->idle = RIGHT;
    return (player);
}

player_t *play_animation_left(player_t *player, window_t *wind)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    float second = time.microseconds / 1000000.0;

    if (second < 0.075)
        sfRenderWindow_drawSprite(wind->window, player->move[4]->sprite, NULL);
    if (second > 0.070 && second < 0.15)
        sfRenderWindow_drawSprite(wind->window, player->move[5]->sprite, NULL);
    if (second > 0.14 && second < 0.25)
        sfRenderWindow_drawSprite(wind->window, player->move[6]->sprite, NULL);
    if (second > 0.22 && second < 0.3)
        sfRenderWindow_drawSprite(wind->window, player->move[7]->sprite, NULL);
    if (second > 0.26)
        sfClock_restart(player->clock);
    player->idle = LEFT;
    return (player);
}
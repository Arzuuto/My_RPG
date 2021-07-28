/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** do_zoom
*/

#include "game.h"

game_t *init_zoom(game_t *game)
{
    game->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    return (game);
}

void create_zoom(game_t *game) {
    static float x = 1;
    static float y = 1;

    if (x != 1920 || y != 1080) {
        if (x < 1920)
            x += 10;
        if (y < 1080)
            y += 10;
        sfView_setSize(game->view, (sfVector2f){x,y});
    }
}
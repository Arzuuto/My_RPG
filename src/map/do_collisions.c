/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** do_collisions
*/

#include <stdio.h>
#include "game.h"

void do_left(game_t *game)
{
    int i = (game->player->pos.x - 1) / 47;

    if (i == 0)
        game->player->pos.x = 40;
}

void do_right(game_t *game)
{
    int i = (game->player->pos.x + 1) / 47;

    if (i == 39)
        game->player->pos.x = 1836;
}

void do_up(game_t *game)
{
    int i = (game->player->pos.y - 1) / 47;

    if (i == 0)
        game->player->pos.y = 40;
}

static void do_down(game_t *game)
{
    int i = game->player->pos.x / 47;
    int j = (game->player->pos.y + 1) / 47;

    if (j == 21 && i != 20)
        game->player->pos.y = 980;
}

void do_collisions(game_t *game)
{
    do_down(game);
    do_up(game);
    do_left(game);
    do_right(game);
}

/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** do_collisions_game
*/

#include "game.h"

static void do_game_up(game_t *game)
{
    int i = game->player->pos.x / 47;
    int j = (game->player->pos.y - 1) / 47;

    if (j == 0 && i != 21)
        game->player->pos.y = 40;
}

void do_game_down(game_t *game)
{
    int j = (game->player->pos.y + 1) / 47;

    if (j == 21)
        game->player->pos.y = 980;
}

void do_game_collisions(game_t *game)
{
    do_game_down(game);
    do_game_up(game);
    do_left(game);
    do_right(game);
}

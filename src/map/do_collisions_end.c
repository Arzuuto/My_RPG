/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** do_collisions_end
*/

#include "game.h"

void do_end_collisions(game_t *game)
{
    do_up(game);
    do_game_down(game);
    do_left(game);
    do_right(game);
}
/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** inv
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/stat.h>
#include "game.h"

void preset_inv(game_t *game)
{
    game->inv = malloc(sizeof(inv_t));
    game->pos_inv = malloc(sizeof(pos_inv_t));
    game->text_inv = malloc(sizeof(text_inv_t));
    game->inv->y = 0;
    game->inv->x = 0;
    load_file_in_mem_inv("config/inventory.txt", game);
    size_rows_inv(game);
    size_cols_inv(game);
    str_to_arr_inv(game);
    inv(game);
}

void display_inventory(game_t *game, sfRenderWindow *win)
{
    preset_inv(game);
    for (game->inv->y = 0; game->inv->y != game->inv->rows; game->inv->y++) {
        for (game->inv->x = 0; game->inv->x != game->inv->cols[game->inv->y]
                ; game->inv->x++) {
            game->pos_inv->box = set_inv(game, 'B', game->text_inv->box, win);
            game->pos_inv->wall_h = set_inv(game, 'H', game->text_inv->wall_h,
                                            win);
            game->pos_inv->wall_v = set_inv(game, 'V', game->text_inv->wall_v,
                                            win);
        }
    }
}

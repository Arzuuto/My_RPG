/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** end_map
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/stat.h>
#include "game.h"

game_t *end_preset(game_t *game)
{
    game->map = malloc(sizeof(map_t));
    game->pos_map = malloc(sizeof(pos_map_t));
    game->text_map = malloc(sizeof(text_map_t));
    game->map->y = 0;
    game->map->x = 0;
    load_file_in_mem("config/end_map.txt", game);
    size_rows(game);
    size_cols(game);
    str_to_arr(game);
    map(game);
    return game;
}

void end_c_to_tiles(game_t *game, sfRenderWindow *win)
{
    for (game->map->y = 0; game->map->y != game->map->rows; game->map->y++) {
        for (game->map->x = 0; game->map->x != game->map->cols[game->map->y]
                ; game->map->x++) {
            game->pos_map->pos_ground = set_map(game, 'B',
                                                game->text_map->ground, win);
            game->pos_map->pos_wf = set_map(game, 'A', game->text_map->wf
                                              , win);
            game->pos_map->pos_wb = set_map(game, 'C', game->text_map->wb
                                              , win);
            game->pos_map->pos_vw = set_map(game, 'D', game->text_map->vw
                                              , win);
            game->pos_map->pos_door = set_map(game, 'S', game->text_map->door
                                            , win);
        }
    }
}
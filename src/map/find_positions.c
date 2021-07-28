/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** find_positions
*/

#include "game.h"

void find_pos_player(game_t *game)
{
    int i = game->player->pos.x / 47;
    int j = game->player->pos.y / 47;

    if (i == 20 && j == 21 && game->config_map == 1) {
        game = game_preset(game);
        game->config_map = 2;
        init_hp_enemy(game->enemy);
    }
    if (game->config_map == 2 && i == 20 && j == 0) {
        game = preset(game);
        game->config_map = 1;
        init_hp_enemy(game->enemy);
    }
    if (game->config_map == 2 && i == 39 && j == 11
    && game->enemy->pos->boss.x == -100) {
        game = end_preset(game);
        game->config_map = 3;
    }
}

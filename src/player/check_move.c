/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** check_move.c
*/

#include "window.h"
#include "player.h"

player_t *check_move_up(player_t *player, pnj_t *pnj, window_t *wind)
{
    sfSprite *sp_player = player->move[0]->sprite;
    sfSprite *sp_pnj = pnj->sp[0]->sprite;

    if (check_hitbox_up(sp_player, sp_pnj, player->stats->speed) == 0) {
        player = player_set_animation(player, 0, -player->stats->speed);
        player = UP_MOVEMENT;
        return (player);
    } else {
        player = UP_MOVEMENT;
        return (player);
    }
}

player_t *check_move_down(player_t *player, pnj_t *pnj, window_t *wind)
{
    sfSprite *sp_player = player->move[0]->sprite;
    sfSprite *sp_pnj = pnj->sp[0]->sprite;

    if (check_hitbox_down(sp_player, sp_pnj, player->stats->speed) == 0) {
        player = player_set_animation(player, 0, player->stats->speed);
        player = DOWN_MOVEMENT;
        return (player);
    } else {
        player = DOWN_MOVEMENT;
        return (player);
    }
}

player_t *check_move_right(player_t *player, pnj_t *pnj, window_t *wind)
{
    sfSprite *sp_player = player->move[0]->sprite;
    sfSprite *sp_pnj = pnj->sp[0]->sprite;

    if (check_hitbox_left(sp_player, sp_pnj, 8) == 0) {
        player = player_set_animation(player, player->stats->speed, 0);
        player = play_animation_right(player, wind);
        return (player);
    } else {
        player = play_animation_right(player, wind);
        return (player);
    }
}

player_t *check_move_left(player_t *player, pnj_t *pnj, window_t *wind)
{
    sfSprite *sp_player = player->move[0]->sprite;
    sfSprite *sp_pnj = pnj->sp[0]->sprite;

    if (check_hitbox_right(sp_player, sp_pnj, player->stats->speed) == 0) {
        player = player_set_animation(player, -player->stats->speed, 0);
        player = play_animation_left(player, wind);
        return (player);
    } else {
        player = play_animation_left(player, wind);
        return (player);
    }
}
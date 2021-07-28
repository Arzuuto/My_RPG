/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player_animation.c
*/

#include "window.h"
#include "player.h"
#include "pnj.h"

player_t *player_set_animation(player_t *player, float x, float y)
{
    sfVector2f pos;

    player->pos = (sfVector2f){player->pos.x += x, player->pos.y += y};
    pos = player->pos;
    for (int i = 0; i < 8; i += 1)
        sfSprite_setPosition(player->move[i]->sprite, pos);
    sfSprite_setPosition(player->move[1]->sprite,
                (sfVector2f) {pos.x, pos.y - 5});
    sfSprite_setPosition(player->move[2]->sprite,
                (sfVector2f) {pos.x, pos.y - 2});
    sfSprite_setPosition(player->move[5]->sprite,
                (sfVector2f) {pos.x, pos.y - 5});
    sfSprite_setPosition(player->move[6]->sprite,
                (sfVector2f) {pos.x, pos.y - 2});
    return (player);
}

player_t *play_player_animation(player_t *player, pnj_t *pnj, window_t *wind)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        player = check_move_up(player, pnj, wind);
        return (player);
    } if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        player = check_move_down(player, pnj, wind);
        return (player);
    } if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        player = check_move_right(player, pnj, wind);
        return (player);
    } if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        player = check_move_left(player, pnj, wind);
        return (player);
    }  if (STANDAR_MOVEMENT)
        play_animation_idle(player, wind);
    return (player);
}

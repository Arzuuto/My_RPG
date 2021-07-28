/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** enemy_move
*/

#include "game.h"
#include "enemy.h"

enemy_move_t *init_enemy_move(enemy_move_t *move)
{
    move->sad_guy = sfClock_create();
    move->orc = sfClock_create();
    move->boss = sfClock_create();
    move->fireball = sfClock_create();
    move->mage = sfClock_create();
    return move;
}

sfVector2f pattern_sad_guy(sfVector2f pos, sfClock *clock, int speed)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float second = time.microseconds / 100000.0;

    if (second > 0.1) {
        if (pos.x <= 1500 && pos.y == 500)
            pos.x -= speed;
        if (pos.x == 1000 && pos.y >= 250)
            pos.y -= speed;
        if (pos.x >= 1000 && pos.y <= 250)
            pos.x += speed;
        if (pos.x == 1500 && pos.y <= 500)
            pos.y += speed;
        sfClock_restart(clock);
    }
    return pos;
}

sfVector2f pattern_orc(sfVector2f pos, sfClock *clock, int speed)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float second = time.microseconds / 100000.0;

    if (second > 0.1) {
        if (pos.x >= 600)
            pos.x += speed;
        if (pos.x <= 1000)
            pos.x -= speed;
        sfClock_restart(clock);
    }
    return pos;
}

sfVector2f pattern_boss(game_t *game, sfVector2f boss_pos, sfClock *clock,
                        int speed)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float second = time.microseconds / 100000.0;

    if (second > 0.1) {
        if (game->player->pos.x > boss_pos.x)
            boss_pos.x += speed;
        if (game->player->pos.x < boss_pos.x)
            boss_pos.x -= speed;
        if (game->player->pos.y > boss_pos.y)
            boss_pos.y += speed;
        if (game->player->pos.y < boss_pos.y)
            boss_pos.y -= speed;
        sfClock_restart(clock);
    }
    return boss_pos;
}

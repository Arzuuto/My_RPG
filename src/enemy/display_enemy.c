/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** display_enemy.c
*/

#include "game.h"

void init_hp_enemy(enemy_t *enemy)
{
    enemy->hp->sad_guy = 5;
    enemy->hp->orc = 15;
    enemy->hp->boss = 100;
    enemy->hp->mage = 30;
    enemy->pos = enemy_pos(enemy->pos);
}

game_t *display_enemy(game_t *game, sfRenderWindow *win, enemy_t *enemy)
{
    sfTexture *texture = sfTexture_createFromFile("assets/enemy.png", NULL);

    create_enemy(win, enemy->pos->sad_guy, texture, enemy->rect->sad_guy);
    enemy->pos->sad_guy = pattern_sad_guy(enemy->pos->sad_guy,
                                          enemy->move->sad_guy, 4);
    create_enemy(win, enemy->pos->orc, texture, enemy->rect->orc);
    enemy->pos->orc = pattern_orc(enemy->pos->orc, enemy->move->orc, 4);
    enemy_attack(game->player, enemy->pos->orc, enemy->rect->orc);
    player_attack_orc(game->player, enemy,
                      enemy->pos->orc, enemy->rect->orc);
    enemy_attack(game->player, enemy->pos->sad_guy, enemy->rect->sad_guy);
    enemy_attack(game->player, enemy->pos->boss, enemy->rect->boss);
    player_attack_sad(game->player, enemy,
                      enemy->pos->sad_guy, enemy->rect->sad_guy);
    return game;
}
/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** create_enemy
*/

#include <time.h>
#include <stdlib.h>
#include "game.h"
#include "enemy.h"

void create_enemy(sfRenderWindow *win, sfVector2f pos,
                  sfTexture *texture, sfIntRect rect)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {3, 3};

    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(win, sprite, NULL);
}

enemy_t *setup_enemy(void)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    enemy_rect_t *rect = malloc(sizeof(enemy_rect_t));
    enemy_pos_t *pos = malloc(sizeof(enemy_pos_t));
    enemy_anim_t *clock = malloc(sizeof(enemy_anim_t));
    enemy_move_t *move = malloc(sizeof(enemy_move_t));
    enemy_hp_t *hp = malloc(sizeof(enemy_move_t));

    enemy->move = init_enemy_move(move);
    enemy->pos = enemy_pos(pos);
    enemy->rect = enemy_rect(rect);
    enemy->anim = init_clock_anim(clock);
    enemy->hp = enemy_hp(hp);
    enemy->dmg = sfClock_create();
    enemy->status = 0;
    return enemy;
}

void player_attack_sad(player_t *player, enemy_t *enemy,
                       sfVector2f pos, sfIntRect rect)
{
    sfTime time = sfClock_getElapsedTime(enemy->dmg);
    float second = time.microseconds / 1000000.0;

    if (enemy->status == 0) {
        if (second >= 2)
            enemy->status = 1;
    } else {
        if (check_hitbox_all(player->wp->iron[2]->sprite, pos, rect, 6)
            == 1 && enemy->hp->sad_guy > 0) {
            enemy->hp->sad_guy -= player->stats->attack;
            sfClock_restart(enemy->dmg);
            enemy->status = 0;
            if (enemy->hp->sad_guy <= 0)
                player->stats->xp += 1;
        }
    }
    if (enemy->hp->sad_guy <= 0)
        enemy->pos->sad_guy.x = -100;
}

void player_attack_orc(player_t *player, enemy_t *enemy,
                       sfVector2f pos, sfIntRect rect)
{
    sfTime time = sfClock_getElapsedTime(enemy->dmg);
    float second = time.microseconds / 1000000.0;

    if (enemy->status == 0) {
        if (second >= 2)
            enemy->status = 1;
    } else {
        if (check_hitbox_all(player->wp->iron[2]->sprite, pos, rect, 6)
            == 1 && enemy->hp->orc > 0) {
            enemy->hp->orc -= player->stats->attack;
            sfClock_restart(enemy->dmg);
            enemy->status = 0;
            if (enemy->hp->orc <= 0)
                player->stats->xp += 2;
        }
    }
    if (enemy->hp->orc <= 0)
        enemy->pos->orc.x = -100;
}

void enemy_attack(player_t *player, sfVector2f pos, sfIntRect rect)
{
    sfTime time = sfClock_getElapsedTime(player->stats->dmg);
    float second = time.microseconds / 1000000.0;

    if (player->stats->status == 0) {
        if (second >= 2)
            player->stats->status = 1;
    } else {
        if (check_hitbox_all(player->move[0]->sprite, pos, rect, 8)
            == 1 && player->stats->hp > 0) {
            player->stats->hp -= 1;
            sfClock_restart(player->stats->dmg);
            player->stats->status = 0;
        }
    }
}
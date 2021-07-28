/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** manage boss
*/

#include "enemy.h"
#include "game.h"

void create_boss(sfRenderWindow *win, sfVector2f pos, sfIntRect rect)
{
    sfTexture *texture = sfTexture_createFromFile("assets/boss.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {4, 4};

    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(win, sprite, NULL);
}

static void player_attack_boss(player_t *player, enemy_t *enemy,
                                sfVector2f pos, sfIntRect rect)
{
    sfTime time = sfClock_getElapsedTime(enemy->dmg);
    float second = time.microseconds / 1000000.0;

    if (enemy->status == 0) {
        if (second >= 2)
            enemy->status = 1;
    } else {
        if (check_hitbox_all(player->wp->iron[2]->sprite, pos, rect, 6)
            == 1 && enemy->hp->boss > 0) {
            enemy->hp->boss -= player->stats->attack;
            sfClock_restart(enemy->dmg);
            enemy->status = 0;
            if (enemy->hp->boss <= 0)
                player->stats->xp += 100;
        }
    }
    if (enemy->hp->boss <= 0)
        enemy->pos->boss.x = -100;
}

static void player_attack_mage(player_t *player, enemy_t *enemy,
                                 sfVector2f pos, sfIntRect rect)
{
    sfTime time = sfClock_getElapsedTime(enemy->dmg);
    float second = time.microseconds / 1000000.0;

    if (enemy->status == 0) {
        if (second >= 2)
            enemy->status = 1;
    } else {
        if (check_hitbox_all(player->wp->iron[2]->sprite, pos, rect, 6)
            == 1 && enemy->hp->mage > 0) {
            enemy->hp->mage -= player->stats->attack;
            sfClock_restart(enemy->dmg);
            enemy->status = 0;
            if (enemy->hp->mage <= 0)
                player->stats->xp += 10;
        }
    }
    if (enemy->hp->mage <= 0)
        enemy->pos->mage.x = -100;
}

game_t *display_boss(game_t *game, sfRenderWindow *win, enemy_t *enemy)
{
    create_boss(win, enemy->pos->boss, enemy->rect->boss);
    enemy->pos->boss = pattern_boss(game, enemy->pos->boss,
                                       enemy->move->boss, 4);
    walk_animation(&enemy->rect->boss, 31, 106, enemy->anim->boss);
    enemy_attack(game->player, enemy->pos->boss, enemy->rect->boss);
    player_attack_boss(game->player, enemy,
                      enemy->pos->boss, enemy->rect->boss);
    enemy_attack(game->player, enemy->pos->mage, enemy->rect->mage);
    enemy_attack(game->player, enemy->pos->fireball, enemy->rect->fireball);
    player_attack_mage(game->player, enemy,
                      enemy->pos->mage, enemy->rect->mage);
    enemy_mage(game, win, enemy);
    return game;
}
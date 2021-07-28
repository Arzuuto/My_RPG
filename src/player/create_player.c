/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_player.c
*/

#include <stdlib.h>
#include "window.h"
#include "menu.h"
#include "player.h"

static object_t **create_player_move(sfVector2f pos)
{
    object_t **move = malloc(sizeof(object_t *) * 10);
    char human[] = "assets/human.png";

    move[0] = create_obj(human, pos, (sfIntRect) {2, 4, 15, 19});
    move[1] = create_obj(human, pos, (sfIntRect) {18, 5, 15, 18});
    move[2] = create_obj(human, pos, (sfIntRect) {34, 6, 15, 17});
    move[3] = create_obj(human, pos, (sfIntRect) {50, 5, 15, 18});
    move[4] = create_obj(human, pos, (sfIntRect) {115, 4, 15, 19});
    move[5] = create_obj(human, pos, (sfIntRect) {99, 5, 15, 18});
    move[6] = create_obj(human, pos, (sfIntRect) {83, 6, 15, 17});
    move[7] = create_obj(human, pos, (sfIntRect) {67, 5, 15, 18});
    for (int i = 0; i < 8; i += 1)
        sfSprite_setScale(move[i]->sprite, (sfVector2f){3, 3});
    return (move);
}

static object_t **more_hearts(object_t **hp)
{
    char stats[] = "assets/combat.png";
    sfIntRect health = (sfIntRect) {3, 4, 13, 12};
    sfIntRect no_health = (sfIntRect) {46, 3, 13, 12};

    hp[6] = create_obj(stats, (sfVector2f) {300, 0}, health);
    hp[7] = create_obj(stats, (sfVector2f) {350, 0}, health);
    hp[8] = create_obj(stats, (sfVector2f) {400, 0}, health);
    hp[9] = create_obj(stats, (sfVector2f) {0, 0}, no_health);
    hp[10] = create_obj(stats, (sfVector2f) {50, 0}, no_health);
    hp[11] = create_obj(stats, (sfVector2f) {100, 0}, no_health);
    hp[12] = create_obj(stats, (sfVector2f) {150, 0}, no_health);
    hp[13] = create_obj(stats, (sfVector2f) {200, 0}, no_health);
    hp[14] = create_obj(stats, (sfVector2f) {250, 0}, no_health);
    hp[15] = create_obj(stats, (sfVector2f) {300, 0}, no_health);
    hp[16] = create_obj(stats, (sfVector2f) {350, 0}, no_health);
    hp[17] = create_obj(stats, (sfVector2f) {400, 0}, no_health);
    return (hp);
}

static object_t **create_sp_hp(void)
{
    object_t **hp = malloc(sizeof(object_t *) * 18);
    char stats[] = "assets/combat.png";
    sfIntRect health = (sfIntRect) {3, 4, 13, 12};

    hp[0] = create_obj(stats, (sfVector2f) {0, 0}, health);
    hp[1] = create_obj(stats, (sfVector2f) {50, 0}, health);
    hp[2] = create_obj(stats, (sfVector2f) {100, 0}, health);
    hp[3] = create_obj(stats, (sfVector2f) {150, 0}, health);
    hp[4] = create_obj(stats, (sfVector2f) {200, 0}, health);
    hp[5] = create_obj(stats, (sfVector2f) {250, 0}, health);
    hp = more_hearts(hp);
    return (hp);
}

stats_t *create_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t) * 1);

    stats->lvl = 1;
    stats->xp = 0;
    stats->hp = 3;
    stats->hp_max = 3;
    stats->attack = 1;
    stats->speed = 8;
    stats->pts = 0;
    stats->dmg = sfClock_create();
    stats->status = 0;
    return (stats);
}

player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t) * 1);

    player->pos = (sfVector2f){300, 500};
    player->move = create_player_move(player->pos);
    player->clock = sfClock_create();
    player->idle = RIGHT;
    player->sp_hp = create_sp_hp();
    player->wp = create_sp_wp();
    player->stats = create_stats();
    player->sword = iron;
    return (player);
}
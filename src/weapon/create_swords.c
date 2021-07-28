/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_swords.c
*/

#include <stdlib.h>
#include "player.h"

static object_t **create_sp_iron_wp(void)
{
    object_t **wp = malloc(sizeof(object_t *) * 4);
    char stats[] = "assets/combat.png";
    sfIntRect iron = (sfIntRect) {32, 2, 10 ,21};

    wp[0] = create_obj(stats, (sfVector2f) {0, 200}, iron);
    wp[1] = create_obj(stats, (sfVector2f) {50, 200}, iron);
    wp[2] = create_obj(stats, (sfVector2f) {100, 200}, iron);
    wp[3] = create_obj(stats, (sfVector2f) {150, 200}, iron);
    return (wp);
}

static object_t **create_sp_gold_wp(void)
{
    object_t **wp = malloc(sizeof(object_t *) * 4);
    char stats[] = "assets/combat.png";
    sfIntRect gold = (sfIntRect) {20, 2, 10, 30};

    wp[0] = create_obj(stats, (sfVector2f) {0, 200}, gold);
    wp[1] = create_obj(stats, (sfVector2f) {50, 200}, gold);
    wp[2] = create_obj(stats, (sfVector2f) {100, 200}, gold);
    wp[3] = create_obj(stats, (sfVector2f) {150, 200}, gold);
    return (wp);
}

swords_t *create_sp_wp(void)
{
    swords_t *wp = malloc(sizeof(swords_t) * 1);

    wp->iron = create_sp_iron_wp();
    wp->gold = create_sp_gold_wp();
    wp->clock = sfClock_create();
    wp->animation = 0;
    wp->dmg = sfClock_create();
    wp->status = 0;
    return (wp);
}
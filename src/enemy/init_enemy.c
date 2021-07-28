/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** initialise the enemy variable
*/

#include <stdlib.h>
#include "enemy.h"

enemy_rect_t *enemy_rect(enemy_rect_t *rect)
{
    sfIntRect sad_guy = {81, 22, 16, 10};
    sfIntRect orc = {17, 208, 16, 16};
    sfIntRect boss = {15, 102, 26, 34};
    sfIntRect mage = {82, 271, 14, 17};
    sfIntRect fireball = {7, 7, 25, 25};

    rect->sad_guy = sad_guy;
    rect->orc = orc;
    rect->boss = boss;
    rect->mage = mage;
    rect->fireball = fireball;
    return rect;
}

enemy_pos_t *enemy_pos(enemy_pos_t *pos)
{
    sfVector2f sad_guy = {1500, 500};
    sfVector2f orc = {600, 600};
    sfVector2f boss = {1700, 540};
    sfVector2f mage = {1800, 540};
    sfVector2f fireball = {1775, 560};

    pos->sad_guy = sad_guy;
    pos->orc = orc;
    pos->boss = boss;
    pos->mage = mage;
    pos->fireball = fireball;
    return pos;
}

enemy_hp_t *enemy_hp(enemy_hp_t *hp)
{
    hp->sad_guy = 5;
    hp->orc = 15;
    hp->boss = 100;
    hp->mage = 30;
    return hp;
}

/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** animation of the enemy
*/

#include "enemy.h"

enemy_anim_t *init_clock_anim(enemy_anim_t *anim)
{
    anim->sad_guy = sfClock_create();
    anim->orc = sfClock_create();
    anim->boss = sfClock_create();
    anim->mage = sfClock_create();
    anim->fireball = sfClock_create();
    return anim;
}

void idle_animation(sfIntRect *rect, int offset, int max_value, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float second = time.microseconds / 1000000.0;

    if (second > 0.1) {
        rect->left = rect->left + offset;
        if (rect->left >= max_value) {
            rect->left = 81;
        }
        sfClock_restart(clock);
    }
}

void walk_animation(sfIntRect *rect, int offset, int max_value, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float second = time.microseconds / 1000000.0;

    if (second > 0.1) {
        rect->left = rect->left + offset;
        if (rect->left >= max_value) {
            rect->left = 16;
        }
        sfClock_restart(clock);
    }
}

void enemy_animation(enemy_t *enemy)
{
    walk_animation(&enemy->rect->sad_guy, 16, 131, enemy->anim->sad_guy);
    idle_animation(&enemy->rect->orc, 16, 131, enemy->anim->orc);
    return;
}

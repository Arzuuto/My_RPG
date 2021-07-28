/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** display_swords.c
*/

#include "player.h"

void set_attack_right(player_t *player, object_t **sp)
{
    sfVector2f scale = (sfVector2f) {2.3, 2.3};
    sfVector2f pos = sfSprite_getPosition(player->move[0]->sprite);

    sfSprite_setRotation(sp[1]->sprite, 35);
    sfSprite_setRotation(sp[2]->sprite, 65);
    sfSprite_setRotation(sp[3]->sprite, 90);
    sfSprite_setPosition(sp[0]->sprite, (sfVector2f){pos.x + 45, pos.y});
    sfSprite_setPosition(sp[1]->sprite, (sfVector2f){pos.x + 70, pos.y});
    sfSprite_setPosition(sp[2]->sprite, (sfVector2f){pos.x + 80, pos.y + 10});
    sfSprite_setPosition(sp[3]->sprite, (sfVector2f){pos.x + 90, pos.y + 20});
    for (int i = 0; i < 4; i += 1)
        sfSprite_setScale(sp[i]->sprite, scale);
}

void set_attack_left(player_t *player, object_t **sp)
{
    sfVector2f scale = (sfVector2f) {2.3, 2.3};
    sfVector2f pos = sfSprite_getPosition(player->move[0]->sprite);

    sfSprite_setRotation(sp[1]->sprite, -35);
    sfSprite_setRotation(sp[2]->sprite, -65);
    sfSprite_setRotation(sp[3]->sprite, -90);
    sfSprite_setPosition(sp[0]->sprite, (sfVector2f){pos.x - 30, pos.y});
    sfSprite_setPosition(sp[1]->sprite, (sfVector2f){pos.x - 50, pos.y + 15});
    sfSprite_setPosition(sp[2]->sprite, (sfVector2f){pos.x - 55, pos.y + 35});
    sfSprite_setPosition(sp[3]->sprite, (sfVector2f){pos.x - 55, pos.y + 45});
    for (int i = 0; i < 4; i += 1)
        sfSprite_setScale(sp[i]->sprite, scale);
}

int display_attack_right_animation(swords_t *wp, object_t **sp, window_t *wind)
{
    sfTime time = sfClock_getElapsedTime(wp->clock);
    float second = time.microseconds / 1000000.0;

    if (second < 0.030)
        sfRenderWindow_drawSprite(wind->window, sp[0]->sprite, NULL);
    if (second > 0.025 && second < 0.10)
        sfRenderWindow_drawSprite(wind->window, sp[1]->sprite, NULL);
    if (second > 0.8 && second < 0.15)
        sfRenderWindow_drawSprite(wind->window, sp[2]->sprite, NULL);
    if (second > 0.12 && second < 0.2)
        sfRenderWindow_drawSprite(wind->window, sp[3]->sprite, NULL);
    if (second > 0.2) {
        sfClock_restart(wp->clock);
        wp->animation = 0;
    }
    return (0);
}

int display_attack_left_animation(swords_t *wp, object_t **sp, window_t *wind)
{
    sfTime time = sfClock_getElapsedTime(wp->clock);
    float second = time.microseconds / 1000000.0;

    if (second < 0.030)
        sfRenderWindow_drawSprite(wind->window, sp[0]->sprite, NULL);
    if (second > 0.025 && second < 0.10)
        sfRenderWindow_drawSprite(wind->window, sp[1]->sprite, NULL);
    if (second > 0.8 && second < 0.15)
        sfRenderWindow_drawSprite(wind->window, sp[2]->sprite, NULL);
    if (second > 0.12 && second < 0.2)
        sfRenderWindow_drawSprite(wind->window, sp[3]->sprite, NULL);
    if (second > 0.2) {
        sfClock_restart(wp->clock);
        wp->animation = 0;
    }
    return (0);
}
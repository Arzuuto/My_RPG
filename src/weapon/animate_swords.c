/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** animate_swords.c
*/

#include "player.h"

static void display_gold_sword(player_t *player, swords_t *wp,
                                                window_t *wind)
{
    if (player->sword == gold) {
        if (sfKeyboard_isKeyPressed(sfKeyW) == sfTrue) {
            sfClock_restart(wp->clock);
            wp->animation = 1;
        }
        if (wp->animation == 1) {
            if (player->idle == RIGHT) {
                set_attack_right(player, wp->gold);
                display_attack_right_animation(wp, wp->gold, wind);
            } else {
                set_attack_left(player, wp->gold);
                display_attack_left_animation(wp, wp->gold, wind);
            }
        }
    }
}

static void display_iron_sword(player_t *player, swords_t *wp,
                                                window_t *wind)
{
    if (player->sword == iron) {
        if (sfKeyboard_isKeyPressed(sfKeyW) == sfTrue) {
            sfClock_restart(wp->clock);
            sfClock_restart(wp->dmg);
            wp->animation = 1;
            wp->status = 1;
        }
        if (wp->animation == 1) {
            if (player->idle == RIGHT) {
                set_attack_right(player, wp->iron);
                display_attack_right_animation(wp, wp->iron, wind);
            } else {
                set_attack_left(player, wp->iron);
                display_attack_left_animation(wp, wp->iron, wind);
            }
        }
    }
}

void move_sword(swords_t *wp)
{
    sfVector2f pos = (sfVector2f) {-100, -100};
    sfTime time = sfClock_getElapsedTime(wp->dmg);
    float second = time.microseconds / 1000000.0;
    sfVector2f sword_pos;

    if (wp->status == 1) {
        for (int i = 0; i < 4 && second > 1; i += 1) {
            sfSprite_setPosition(wp->iron[i]->sprite, pos);
            sfSprite_setPosition(wp->gold[i]->sprite, pos);
        }
        sword_pos = sfSprite_getPosition(wp->iron[3]->sprite);
        if (sword_pos.x == -100)
        wp->status = 0;
    }
}

void display_attack(player_t *player, swords_t *wp, window_t *wind)
{
    display_iron_sword(player, wp, wind);
    display_gold_sword(player, wp, wind);
    if (wp->status == 1)
        move_sword(wp);
}

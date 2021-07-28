/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** add_stats.c
*/

#include "menu.h"
#include "player.h"
#include "stats.h"

static void upgrade_hp(stats_t *player, object_t **button,
                        sfClock *clock, window_t *wind)
{
    if (button_leftclick_is_clicked(button[0], wind, sfWhite) == 1 &&
                player->pts > 0 && player->hp < 9) {
        player->pts -= 1;
        player->hp_max += 1;
        player->hp = player->hp_max;
        sfClock_restart(clock);
    }
}

static void upgrade_dmg(stats_t *player, object_t **button,
                        sfClock *clock, window_t *wind)
{
    if (button_leftclick_is_clicked(button[1], wind, sfWhite) == 1 &&
                                player->pts > 0) {
        player->pts -= 1;
        player->attack += 1;
        sfClock_restart(clock);
    }
}

static void upgrade_speed(stats_t *player, object_t **button,
                        sfClock *clock, window_t *wind)
{
    if (button_leftclick_is_clicked(button[2], wind, sfWhite) == 1 &&
                                player->pts > 0) {
        player->pts -= 1;
        player->speed += 1;
        sfClock_restart(clock);
    }
}

void add_stats_pts(stats_t *player, object_t **button,
                        sfClock *clock, window_t *wind)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.5) {
        upgrade_hp(player, button, clock, wind);
            sfClock_restart(clock);
        upgrade_dmg(player, button, clock, wind);
            sfClock_restart(clock);
        upgrade_speed(player, button, clock, wind);
            sfClock_restart(clock);
    }
}

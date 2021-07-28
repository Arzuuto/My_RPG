/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** options.c
*/

#include "game.h"

menu_t *animate_back_opt_button(menu_t *menu, window_t *wind)
{
    sfColor orange = sfColor_fromRGB(255, 174, 3);

    button_is_touched(menu->opt[2], menu->txt_opt[4], wind);
    if (button_leftclick_is_clicked(menu->opt[2], wind, orange) == 1) {
        sfSound_play(menu->audio[0]->sound);
        sfClock_restart(menu->clock);
        menu->status = 0;
    }
    return (menu);
}

menu_t *animate_settings_button(menu_t *menu, window_t *wind)
{
    sfColor orange = sfColor_fromRGB(255, 174, 3);

    if (button_leftclick_is_clicked(menu->opt[0], wind, orange) == 1) {
        sfSound_play(menu->audio[0]->sound);
        menu->status = 7;
    }
    return (menu);
}

void set_options_sounds(game_t *game, menu_t *menu, window_t *wind)
{
    float music = sfMusic_getVolume(menu->music);

    if (button_leftclick_is_clicked(menu->opt[4], wind, sfWhite) == 1) {
        if (sfMusic_getVolume(menu->music) + 1 <= 100) {
            sfMusic_setVolume(menu->music, music + 1);
            sfMusic_setVolume(game->music, music + 1);
            sfText_setString(menu->txt_opt[2]->text, my_itoa((int) music));
        }
    }
    if (button_leftclick_is_clicked(menu->opt[6], wind, sfWhite) == 1) {
        if (sfMusic_getVolume(menu->music) - 1 >= 0) {
            sfMusic_setVolume(menu->music, music - 1);
            sfMusic_setVolume(game->music, music - 1);
            sfText_setString(menu->txt_opt[2]->text, my_itoa((int) music));
        }
    }
}

void set_options(game_t *game, menu_t *menu, window_t *wind)
{
    if (button_leftclick_is_clicked(menu->opt[3], wind, sfWhite) == 1) {
        game->fps += 1;
        sfRenderWindow_setFramerateLimit(wind->window, game->fps);
            sfText_setString(menu->txt_opt[3]->text, my_itoa(game->fps));
    }
    if (button_leftclick_is_clicked(menu->opt[5], wind, sfWhite) == 1) {
        game->fps -= 1;
        sfRenderWindow_setFramerateLimit(wind->window, game->fps);
            sfText_setString(menu->txt_opt[3]->text, my_itoa(game->fps));
    }
    set_options_sounds(game, menu, wind);
}

menu_t *display_opt(game_t *game, menu_t *menu, window_t *wind)
{
    sfRenderWindow_drawSprite(wind->window, menu->opt[0]->sprite, NULL);
    for (int k = 3; k < 5; k += 1) {
        sfSprite_setScale(menu->opt[k]->sprite, (sfVector2f) {0.5, 0.5});
        sfSprite_setScale(menu->opt[k + 2]->sprite, (sfVector2f) {0.35, 0.35});
    }
    if (menu->status == 7) {
        for (int i = 0; i < 7; i += 1)
            sfRenderWindow_drawSprite(wind->window, menu->opt[i]->sprite, NULL);
        for (int j = 0; j < 5; j += 1)
            sfRenderWindow_drawText(wind->window, menu->txt_opt[j]->text, NULL);
        set_options(game, menu, wind);
        animate_back_opt_button(menu, wind);
    }
    return (menu);
}
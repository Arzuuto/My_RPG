/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** cursor.c
*/

#include "game.h"

static menu_t *animate_play_pause_button(menu_t *pause, window_t *wind)
{
    sfColor brown = sfColor_fromRGB(197, 154, 114);

    button_is_touched(pause->sp[1], pause->txt[0], wind);
    if (button_leftclick_is_clicked(pause->sp[1], wind, brown) == 1) {
        sfClock_restart(pause->clock);
        pause->status = 0;
    }
    return (pause);
}

static menu_t *animate_how_pause_button(menu_t *pause, window_t *wind)
{
    sfColor orange = sfColor_fromRGB(255, 174, 3);

    button_is_touched(pause->sp[2], pause->txt[1], wind);
    if (button_leftclick_is_clicked(pause->sp[2], wind, orange) == 1) {
        sfClock_restart(pause->clock);
        pause->status = 3;
    }
    return (pause);
}

static game_t *animate_quit_pause_button(game_t *game, window_t *wind)
{
    button_is_touched(game->pause->sp[3], game->pause->txt[2], wind);
    if (button_leftclick_is_clicked(game->pause->sp[3], wind, sfRed) == 1) {
        sfClock_restart(game->pause->clock);
        game->pause->status = 5;
    }
    if (game->pause->status == 5 && get_seconds(game->pause->clock) > 0.4) {
        game->pause->status = 6;
        game->menu->status = 0;
    }
    return (game);
}

game_t *display_pause(game_t *game, window_t *wind)
{
        sfRenderWindow_setMouseCursorVisible(wind->window, sfTrue);
        display_menu_sp(game->pause->sp, game->pause->bg, wind);
        set_text(game->pause->txt[0], 80, (sfVector2f) {780, 295}, "RESUME");
        set_text(game->pause->txt[2], 80, (sfVector2f) {810, 595}, "MENU");
        display_txt_sp(game->pause->txt, wind);
        display_menu_bg(game->pause->bg, wind);
        display_opt_pause(game, game->pause, game->menu, wind);
        game->menu = display_opt(game, game->menu, wind);
        game->pause = display_howto_pause(game->pause, wind);
        game->pause = animate_play_pause_button(game->pause, wind);
        game->pause = animate_how_pause_button(game->pause, wind);
        game->pause = animate_settings_button(game->pause, wind);
        game = animate_quit_pause_button(game, wind);
        sfRenderWindow_display(wind->window);
    return (game);
}

int check_button_pause(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        return (1);
    }
    return (0);
}
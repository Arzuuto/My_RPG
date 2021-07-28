/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** menu.c
*/

#include "my.h"
#include "window.h"
#include "create.h"
#include "menu.h"
#include "game.h"

void display_menu_bg(object_t **bg, window_t *wind)
{
    for (int i = 0; i < 16; i += 1) {
        sfSprite_setScale(bg[i]->sprite, (sfVector2f) {12, 12});
        sfSprite_setScale(bg[9]->sprite, (sfVector2f) {14, 14});
        sfSprite_setScale(bg[10]->sprite, (sfVector2f) {16, 16});
        sfRenderWindow_drawSprite(wind->window, bg[i]->sprite, NULL);
    }
}

void display_menu_sp(object_t **sp,
 __attribute__((unused))object_t **bg, window_t *wind)
{
    for (int i = 0; i < 4; i += 1)
        sfRenderWindow_drawSprite(wind->window, sp[i]->sprite, NULL);
}

void display_txt_sp(text_t **txt, window_t *wind)
{
    for (int i = 0; i < 4; i += 1)
        sfRenderWindow_drawText(wind->window, txt[i]->text, NULL);
}

float get_seconds(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float second = sfTime_asSeconds(time);

    return (second);
}

game_t *display_menu(game_t *game, window_t *wind)
{
    display_menu_sp(game->menu->sp, game->menu->bg, wind);
    display_txt_sp(game->menu->txt, wind);
    display_menu_bg(game->menu->bg, wind);
    game->menu = display_opt(game, game->menu, wind);
    game->menu = display_howto(game->menu, wind);
    game->menu = animate_how_button(game->menu, wind);
    game->menu = animate_play_button(game, game->menu, wind);
    game->menu = animate_settings_button(game->menu, wind);
    game->menu = animate_quit_button(game->menu, wind);
        if (game->menu->status == 10)
            game = display_lose(game, wind);
    sfRenderWindow_display(wind->window);
    return (game);
}
/*
** EPITECH PROJECT, 2021
** window.c
** File description:
** window
*/

#include <stdlib.h>
#include "window.h"
#include "my.h"
#include "menu.h"
#include "game.h"
#include "png.h"
#include "enemy.h"

window_t *init_window(window_t *wind)
{
    sfVideoMode mode = {wind->window_x, wind->window_y, 32};

    wind->window = sfRenderWindow_create
        (mode, "my_rpg", sfResize | sfClose, NULL);
    if (wind->window == NULL)
        return (wind);
    sfRenderWindow_setFramerateLimit(wind->window, 60);
    return (wind);
}

void check_close_window(window_t *wind)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(wind->window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(wind->window);
    return;
}

game_t *create_game(window_t *wind)
{
    game_t *game = malloc(sizeof(game_t) * 1);

    game->inv_mode = 0;
    game->fps = 60;
    game->menu = create_menu(wind);
    game->menu->txt_opt = create_menu_txt_opt(game->menu, game->fps);
    game->player = create_player();
    game->pnj = create_pnj();
    game->enemy = setup_enemy();
    game->music = sfMusic_createFromFile("assets/sounds/game.ogg");
    game->cursor = init_cursor(game->cursor);
    game->tower = init_tower(game->tower);
    game->pause = create_pause(game->menu, game->fps, wind);
    game = preset(game);
    game = item_preset(game);
    game->config_map = 1;
    game->box = create_stats_box();
    game->box_mode = 0;
    game->lose = create_lose();
    game = init_zoom(game);
    return (game);
}

void destroy_music(game_t *game)
{

    sfSound_destroy(game->menu->audio[0]->sound);
    sfSoundBuffer_destroy(game->menu->audio[0]->soundbuffer);
    sfMusic_stop(game->menu->music);
    sfMusic_destroy(game->menu->music);
    sfSound_destroy(game->pause->audio[0]->sound);
    sfSoundBuffer_destroy(game->pause->audio[0]->soundbuffer);
    sfMusic_stop(game->music);
    sfMusic_destroy(game->music);
}

void open_window(window_t *wind)
{
    game_t *game = create_game(wind);

    while (sfRenderWindow_isOpen(wind->window)) {
        check_close_window(wind);
        if (game->menu->status != 1)
            game = display_menu(game, wind);
        if (game->menu->status == 1)
            game = play_game(game, wind);
        if (game->menu->status == 6)
            break;
        sfRenderWindow_display(wind->window);
        sfRenderWindow_clear(wind->window, sfBlack);
    }
    destroy_music(game);
    sfRenderWindow_close(wind->window);
    return;
}

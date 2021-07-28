/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** draw_inv
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/stat.h>
#include "game.h"

void create_inv(sfRenderWindow *win, game_t *inv, sfTexture *texture
                 , sfVector2f pos)
{
    inv->text_inv->sprite = sfSprite_create();
    sfSprite_setPosition(inv->text_inv->sprite, pos);
    sfSprite_setTexture(inv->text_inv->sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(win, inv->text_inv->sprite, NULL);
}

void inv(game_t *inv)
{
    inv->text_inv->box = sfTexture_createFromFile("assets/inv_box.png"
                                                    , NULL);
    inv->text_inv->wall_h = sfTexture_createFromFile("assets/inv_wall_h.png"
                                                    , NULL);
    inv->text_inv->wall_v = sfTexture_createFromFile("assets/inv_wall_v.png"
                                                    , NULL);
}

sfVector2f set_inv(game_t *game, char c, sfTexture *texture
                   , sfRenderWindow *win)
{
    sfVector2f pos;

    if (game->inv->arr[game->inv->y][game->inv->x] == c) {
        pos.y = game->inv->y * 50;
        pos.x = game->inv->x * 50;
        create_inv(win, game, texture, pos);
    }
    return pos;
}

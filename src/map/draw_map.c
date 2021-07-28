/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** draw_map
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/stat.h>
#include "game.h"

void display_map(sfRenderWindow *win, game_t *map, sfTexture *texture
                 , sfVector2f pos)
{
    map->text_map->sprite = sfSprite_create();
    sfSprite_setPosition(map->text_map->sprite, pos);
    sfSprite_setTexture(map->text_map->sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(win, map->text_map->sprite, NULL);
}

void map(game_t *map)
{
    map->text_map->ground = sfTexture_createFromFile("assets/map_tiles.png"
                                                    , NULL);
    map->text_map->wb = sfTexture_createFromFile("assets/wall_back.png"
                                                    , NULL);
    map->text_map->wf = sfTexture_createFromFile("assets/wall_front.jpg"
                                                    , NULL);
    map->text_map->vw = sfTexture_createFromFile("assets/vertical_wall.png"
                                                    , NULL);
    map->text_map->door = sfTexture_createFromFile("assets/door.png"
                                                    , NULL);
}

sfVector2f set_map(game_t *game, char c, sfTexture *texture
                   , sfRenderWindow *win)
{
    sfVector2f pos;

    if (game->map->arr[game->map->y][game->map->x] == c) {
        pos.y = game->map->y * 47;
        pos.x = game->map->x * 47;
        display_map(win, game, texture, pos);
    }
    return pos;
}
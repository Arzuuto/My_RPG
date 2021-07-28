/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** cursor
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "cursor.h"
#include "window.h"
#include "game.h"

cursor_t *init_cursor(cursor_t *cursor)
{
    cursor = malloc(sizeof(cursor_t));
    cursor->my_sprite = sfSprite_create();
    cursor->my_text = sfTexture_createFromFile("assets/cursor.png", NULL);
    sfSprite_setTexture(cursor->my_sprite, cursor->my_text, sfFalse);
    return (cursor);
}

void create_cursor(window_t *wind, cursor_t *cursor)
{
    sfVector2i pos;

    sfRenderWindow_setMouseCursorVisible(wind->window, sfFalse);
    pos = sfMouse_getPositionRenderWindow(wind->window);
    sfSprite_setPosition(cursor->my_sprite, (sfVector2f){pos.x, pos.y});
    sfSprite_setScale(cursor->my_sprite, (sfVector2f){0.1, 0.1});
    sfRenderWindow_drawSprite(wind->window, cursor->my_sprite, NULL);
}
/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** cursor
*/

#ifndef CURSOR_H_
#define CURSOR_H_

#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "window.h"

typedef struct cursor_s {
    sfSprite *my_sprite;
    sfTexture *my_text;
} cursor_t;

void create_cursor(window_t *wind, cursor_t *cursor);
cursor_t *init_cursor(cursor_t *cursor);

#endif /* !CURSOR_H_ */
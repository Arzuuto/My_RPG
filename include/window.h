/*
** EPITECH PROJECT, 2021
** window.h
** File description:
** window
*/

#ifndef WINDOW__H__
#define WINDOW__H__

#include <SFML/Window.h>
#include <SFML/Graphics.h>

typedef struct window_s {
    sfRenderWindow *window;
    int window_x;
    int window_y;
} window_t;

window_t *init_window(window_t *wind);
void open_window(window_t *wind);

#endif/*WINDOW__H__*/

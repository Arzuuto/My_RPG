/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** tower
*/

#ifndef TOWER_H_
#define TOWER_H_

#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "window.h"

typedef struct tower_s {
    sfSprite *my_sprite;
    sfTexture *my_text;
} tower_t;

tower_t *init_tower(tower_t *tower);
void create_tower(window_t *wind, tower_t *tower);

#endif /* !TOWER_H_ */
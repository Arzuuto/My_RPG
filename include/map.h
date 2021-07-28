/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>

typedef struct text_map {
    sfTexture *ground;
    sfTexture *wb;
    sfTexture *wf;
    sfTexture *vw;
    sfTexture *door;
    sfSprite *sprite;
} text_map_t;

typedef struct pos_map {
    sfVector2f pos_ground;
    sfVector2f pos_wb;
    sfVector2f pos_wf;
    sfVector2f pos_vw;
    sfVector2f pos_door;
} pos_map_t;

typedef struct map {
    char *str;
    char **arr;
    int *cols;
    int rows;
    int x;
    int y;
} map_t;

#endif/* !MAP_H_ */

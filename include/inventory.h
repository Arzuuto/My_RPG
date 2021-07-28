/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** map
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>

typedef struct text_inv {
    sfTexture *box;
    sfTexture *wall_h;
    sfTexture *wall_v;
    sfSprite *sprite;
} text_inv_t;

typedef struct pos_inv {
    sfVector2f box;
    sfVector2f wall_h;
    sfVector2f wall_v;
} pos_inv_t;

typedef struct inv {
    char *str;
    char **arr;
    int *cols;
    int rows;
    int x;
    int y;
} inv_t;

typedef struct item_rect_s {
    sfIntRect gold_sword;
    sfIntRect iron_sword;
} item_rect_t;

typedef struct item_pos_s {
    sfVector2f gold_sword;
    sfVector2f iron_sword;
} item_pos_t;

item_rect_t *init_item_rect(item_rect_t *rect);
item_pos_t *init_item_pos(item_pos_t *pos);
sfSprite *display_items(sfRenderWindow *win, sfVector2f pos, sfIntRect rect);
sfVector2f drag_item(sfSprite *sprite, sfVector2f pos, sfVector2f mouse);

#endif/* !INVENTORY_H_ */

/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** tower
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "tower.h"
#include "window.h"
#include "game.h"

tower_t *init_tower(tower_t *tower)
{
    tower = malloc(sizeof(tower_t));
    tower->my_sprite = sfSprite_create();
    tower->my_text = sfTexture_createFromFile("assets/tower.png", NULL);
    sfSprite_setTexture(tower->my_sprite, tower->my_text, sfFalse);
    return (tower);
}

void create_tower(window_t *wind, tower_t *tower)
{
    sfSprite_setPosition(tower->my_sprite, (sfVector2f){60, 50});
    sfRenderWindow_drawSprite(wind->window, tower->my_sprite, NULL);
}
/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** initialise items
*/

#include <stdlib.h>
#include "game.h"

item_rect_t *init_item_rect(item_rect_t *rect)
{
    sfIntRect iron_sword = {2, 26, 10, 21};
    sfIntRect gold_sword = {50, 153, 10, 22};

    rect->gold_sword = gold_sword;
    rect->iron_sword = iron_sword;
    return rect;
}

item_pos_t *init_item_pos(item_pos_t *pos)
{
    sfVector2f gold_sword = {65, 55};
    sfVector2f iron_sword = {115, 55};

    pos->gold_sword = gold_sword;
    pos->iron_sword = iron_sword;
    return pos;
}

game_t *item_preset(game_t *game)
{
    item_pos_t *item_pos = malloc(sizeof(item_pos_t));
    item_rect_t *item_rect = malloc(sizeof(item_rect_t));

    game->item_pos = init_item_pos(item_pos);
    game->item_rect = init_item_rect(item_rect);
    return game;
}

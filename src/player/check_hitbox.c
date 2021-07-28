/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** check_hitbox.c
*/

#include "window.h"
#include "player.h"

int check_hitbox_up(sfSprite *player, sfSprite *object, int speed)
{
    sfVector2f pos_player = sfSprite_getPosition(player);
    sfVector2f pos_obj = sfSprite_getPosition(object);
    sfIntRect rect_player = sfSprite_getTextureRect(player);
    sfIntRect rect_obj = sfSprite_getTextureRect(object);

    if (NO_SP_UP) {
        return (1);
    } else
        return (0);
}

int check_hitbox_right(sfSprite *player, sfSprite *object, int speed)
{
    sfVector2f pos_player = sfSprite_getPosition(player);
    sfVector2f pos_obj = sfSprite_getPosition(object);
    sfIntRect rect_player = sfSprite_getTextureRect(player);
    sfIntRect rect_obj = sfSprite_getTextureRect(object);

    if (NO_SP_AT_RIGHT) {
        return (1);
    } else
        return (0);
}

int check_hitbox_left(sfSprite *player, sfSprite *object, int speed)
{
    sfVector2f pos_player = sfSprite_getPosition(player);
    sfVector2f pos_obj = sfSprite_getPosition(object);
    sfIntRect rect_player = sfSprite_getTextureRect(player);
    sfIntRect rect_obj = sfSprite_getTextureRect(object);

    if (NO_SP_AT_LEFT) {
        return (1);
    } else
        return (0);
}

int check_hitbox_down(sfSprite *player, sfSprite *object, int speed)
{
    sfVector2f pos_player = sfSprite_getPosition(player);
    sfVector2f pos_obj = sfSprite_getPosition(object);
    sfIntRect rect_player = sfSprite_getTextureRect(player);
    sfIntRect rect_obj = sfSprite_getTextureRect(object);

    if (NO_SP_DOWN) {
        return (1);
    } else
        return (0);
}

int check_hitbox_all(sfSprite *player, sfVector2f pos_obj,
                     sfIntRect rect_obj, int speed)
{
    sfVector2f pos_player = sfSprite_getPosition(player);
    sfIntRect rect_player = sfSprite_getTextureRect(player);

    if (NO_SP_UP || NO_SP_AT_LEFT || NO_SP_AT_RIGHT || NO_SP_DOWN)
        return (1);
    else
        return (0);
}

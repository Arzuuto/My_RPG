/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** manage items
*/

#include <stdio.h>
#include "inventory.h"
#include "game.h"

sfSprite *display_items(sfRenderWindow *win, sfVector2f pos, sfIntRect rect)
{
    sfTexture *texture = sfTexture_createFromFile("assets/items.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {2, 2};

    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(win, sprite, NULL);
    return sprite;
}

sfVector2f drag_item(sfSprite *sprite, sfVector2f pos, sfVector2f mouse)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    int mode = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y))
            mode = 1;
    if (mode == 1) {
        pos.x = mouse.x - 10;
        pos.y = mouse.y - 15;
    }
    if (pos.x > 279 && pos.x < 290)
        pos.x = 275;
    if (pos.y > 0 && pos.y < 51)
        pos.y = 52;
    if (pos.x > 0 && pos.x < 52)
        pos.x = 51;
    if (pos.y > 255 && pos.y < 310)
        pos.y = 254;
    return pos;
}

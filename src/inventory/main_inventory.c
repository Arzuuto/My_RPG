/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** main inventory
*/

#include <stdlib.h>
#include "menu.h"
#include "game.h"

sfSprite *display_icon_inv(sfRenderWindow *win)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {2, 2};
    sfTexture *texture = sfTexture_createFromFile("assets/inv_icon.png", NULL);

    sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, 30, 30});
    sfSprite_setPosition(sprite, (sfVector2f){1750, 20});
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(win, sprite, NULL);
    return sprite;
}

void manage_inventory(game_t *game, sfRenderWindow *win, sfVector2i mouse_2i)
{
    sfVector2f mouse = {mouse_2i.x, mouse_2i.y};
    sfSprite *g_sword;
    sfSprite *i_sword;

    display_inventory(game, win);
    g_sword= display_items(win, game->item_pos->gold_sword,
                           game->item_rect->gold_sword);
    i_sword = display_items(win, game->item_pos->iron_sword,
                            game->item_rect->iron_sword);
    game->item_pos->gold_sword = drag_item(g_sword, game->item_pos->gold_sword,
                                           mouse);
    game->item_pos->iron_sword = drag_item(i_sword, game->item_pos->iron_sword,
                                           mouse);
}

void open_inventory(game_t *game, sfRenderWindow *win, sfSprite *sprite)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && game->inv_mode == 0)
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y))
            game->inv_mode = 1;
    if (game->inv_mode == 1)
        manage_inventory(game, win, mouse);
    if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue && game->inv_mode == 1)
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y))
            game->inv_mode = 0;
}

void main_inventory(game_t *game, sfRenderWindow *win)
{
    sfSprite *sprite = display_icon_inv(win);

    open_inventory(game, win, sprite);
}

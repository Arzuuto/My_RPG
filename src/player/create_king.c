/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** create_king
*/

#include "game.h"

void king_animation(sfIntRect *rect, int offset, int max_value, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float second = time.microseconds / 1000000.0;

    if (second > 0.1) {
        rect->left = rect->left + offset;
        if (rect->left >= max_value) {
            rect->left = 3;
        }
        sfClock_restart(clock);
    }
}

void create_king(sfRenderWindow *win, sfIntRect rect, sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {3, 3};
    sfTexture *texture = sfTexture_createFromFile("assets/king.png", NULL);

    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(win, sprite, NULL);
}

void manage_king(game_t *game, sfRenderWindow *win)
{
    sfVector2f pos = {150, 560};
    sfVector2f girl = {150, 508};
    sfVector2f pos_txt = {girl.x - 90, girl.y - 80};

    create_king(win, game->pnj->king_rect, pos);
    king_animation(&game->pnj->king_rect, 16, 48, game->pnj->king_clock);
    set_text(game->pnj->text, 21, pos_txt, "thank you so much");
}

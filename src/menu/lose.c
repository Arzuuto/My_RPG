/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** lose.c
*/

#include <stdlib.h>
#include "game.h"

lose_t *create_lose(void)
{
    lose_t *lose = malloc(sizeof(lose_t) * 1);
    char text[] = "assets/textbox.png";
    sfVector2f pos_text = (sfVector2f) {530, 400};

    lose->sp = malloc(sizeof(object_t) * 1);
    lose->txt = malloc(sizeof(text_t) * 1);
    lose->sp = create_obj(text, pos_text, (sfIntRect) {2, 7, 449, 71});
    lose->txt = create_text("assets/f.ttf");
    lose->clock = sfClock_create();
    lose->status = 0;
    set_text(lose->txt, 130, (sfVector2f) {720, 410}, "YOU  LOSE");
    sfSprite_setScale(lose->sp->sprite, (sfVector2f) {2, 3});
    return (lose);
}

game_t *display_lose(game_t *game, window_t *wind)
{
    sfTime time = sfClock_getElapsedTime(game->lose->clock);
    float seconds = time.microseconds / 1000000.0;
    sfVector2f new_pos = (sfVector2f){300, 500};

    sfRenderWindow_clear(wind->window, sfBlack);
    sfRenderWindow_drawSprite(wind->window, game->lose->sp->sprite, NULL);
    sfRenderWindow_drawText(wind->window, game->lose->txt->text, NULL);
    if (seconds >= 5 && game->lose->status == 1) {
        sfRenderWindow_setMouseCursorVisible(wind->window, sfTrue);
        sfMusic_stop(game->music);
        sfMusic_play(game->menu->music);
        sfMusic_setLoop(game->menu->music, sfTrue);
        game->menu->status = 0;
        game->lose->status = 0;
        game->player->stats->hp = game->player->stats->hp_max;
        game->player->pos = new_pos;
        game->config_map = 1;
        for (int i = 0; i < 8; i += 1)
            sfSprite_setPosition(game->player->move[i]->sprite, new_pos);
    }
    return (game);
}
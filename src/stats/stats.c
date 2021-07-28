/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** stats.c
*/

#include "game.h"

static void set_text_stats(stats_t *player, text_t **txt)
{
    set_text(txt[2], 50, (sfVector2f) {245, 250}, my_itoa(player->lvl));
    set_text(txt[3], 50, (sfVector2f) {155, 320}, my_itoa(player->xp));
    set_text(txt[4], 50, (sfVector2f) {170, 423}, my_itoa(player->hp_max));
    set_text(txt[5], 50, (sfVector2f) {170, 523}, my_itoa(player->attack));
    set_text(txt[6], 50, (sfVector2f) {170, 623}, my_itoa(player->speed));
    set_text(txt[8], 50, (sfVector2f) {245, 692}, my_itoa(player->pts));
}

static void check_level_up(stats_t *player)
{
    if (player->xp >= player->lvl) {
        player->xp -= player->lvl;
        player->lvl += 1;
        player->pts += 1;
    }
}

static void display_stats_box(stats_box_t *box, window_t *wind)
{
    for (int i = 0; i < 5; i += 1)
        sfRenderWindow_drawSprite(wind->window, box->sp[i]->sprite, NULL);
    for (int j = 0; j < 9; j += 1)
        sfRenderWindow_drawText(wind->window, box->txt[j]->text, NULL);
    for (int k = 0; k < 3; k += 1)
        sfRenderWindow_drawSprite(wind->window, box->button[k]->sprite, NULL);
}

int button_rightclick_is_clicked(object_t *sp, window_t *wind, sfColor color)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(wind->window);
    sfVector2f sprite = sfSprite_getPosition(sp->sprite);
    sfIntRect rect = sfSprite_getTextureRect(sp->sprite);
    sfVector2f scale = sfSprite_getScale(sp->sprite);

    if (mouse.x >= sprite.x && mouse.x <= sprite.x + rect.width * scale.x &&
        mouse.y >= sprite.y && mouse.y <= sprite.y + rect.height * scale.y &&
        sfMouse_isButtonPressed(sfMouseRight) == sfTrue &&
        sfRenderWindow_hasFocus(wind->window) == sfTrue) {
            sfSprite_setColor(sp->sprite, color);
            sfRenderWindow_display(wind->window);
                return (1);
    } else
        return (0);
}

void check_stats(game_t *game, stats_box_t *box, window_t *wind)
{
    check_level_up(game->player->stats);
    sfRenderWindow_drawSprite(wind->window, box->sp[0]->sprite, NULL);
    if (game->box_mode == 0)
        if (button_leftclick_is_clicked(box->sp[0], wind, sfWhite) == 1)
            game->box_mode = 1;
    if (game->box_mode == 1) {
        set_text_stats(game->player->stats, box->txt);
        add_stats_pts(game->player->stats, box->button, box->clock, wind);
        display_stats_box(game->box, wind);
    }
    if (game->box_mode == 1)
        if (button_rightclick_is_clicked(box->sp[0], wind, sfWhite) == 1)
            game->box_mode = 0;
}

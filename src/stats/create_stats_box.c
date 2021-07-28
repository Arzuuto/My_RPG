/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_stats_box.c
*/

#include <stdlib.h>
#include "stats.h"

static object_t **create_stats_box_sp(void)
{
    object_t **sp = malloc(sizeof(object_t *) * 5);
    char stats[] = "assets/stats.png";

    sp[0] = create_obj(stats, (sfVector2f)
                       {1832, 30}, (sfIntRect) {572, 3, 26, 28});
    sp[1] = create_obj(stats, (sfVector2f)
                       {0, 200}, (sfIntRect) {119, 32, 400, 580});
    sp[2] = create_obj("assets/combat.png",
                       (sfVector2f) {50, 435}, (sfIntRect) {3, 4, 13, 12});
    sp[3] = create_obj(stats, (sfVector2f)
                       {50, 535}, (sfIntRect) {37, 6, 27, 25});
    sp[4] = create_obj(stats, (sfVector2f)
                       {50, 635}, (sfIntRect) {2, 4, 27, 22});
    sfSprite_setScale(sp[0]->sprite, (sfVector2f) {2, 2});
    sfSprite_setScale(sp[2]->sprite, (sfVector2f) {4, 4});
    sfSprite_setScale(sp[3]->sprite, (sfVector2f) {2, 2});
    sfSprite_setScale(sp[4]->sprite, (sfVector2f) {2, 2});
    return (sp);
}

static object_t **create_stats_button_sp(void)
{
    object_t **sp = malloc(sizeof(object_t *) * 3);
    char opt[] = "assets/opt.png";
    sfIntRect plus = (sfIntRect) {467 , 18, 116, 115};

    sp[0] = create_obj(opt, (sfVector2f) {260, 435}, plus);
    sp[1] = create_obj(opt, (sfVector2f) {260, 535}, plus);
    sp[2] = create_obj(opt, (sfVector2f) {260, 635}, plus);
    for (int i = 0; i < 3; i += 1)
        sfSprite_setScale(sp[i]->sprite, (sfVector2f) {0.4, 0.4});
    return (sp);
}

static text_t **create_stats_box_txt(void)
{
    text_t **txt = malloc(sizeof(text_t *) * 9);

    txt[0] = create_text("assets/f.ttf");
    txt[1] = create_text("assets/f.ttf");
    txt[2] = create_text("assets/f.ttf");
    txt[3] = create_text("assets/f.ttf");
    txt[4] = create_text("assets/f.ttf");
    txt[5] = create_text("assets/f.ttf");
    txt[6] = create_text("assets/f.ttf");
    txt[7] = create_text("assets/f.ttf");
    txt[8] = create_text("assets/f.ttf");
    set_text(txt[0], 50, (sfVector2f) {65, 250}, "LEVEL");
    set_text(txt[1], 50, (sfVector2f) {65, 320}, "XP");
    set_text(txt[7], 40, (sfVector2f) {65, 700}, "POINTS");
    return (txt);
}

stats_box_t *create_stats_box(void)
{
    stats_box_t *box = malloc(sizeof(stats_box_t));

    box->sp = create_stats_box_sp();
    box->button = create_stats_button_sp();
    box->txt = create_stats_box_txt();
    box->clock = sfClock_create();
    return (box);
}

/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_pnj.c
*/

#include <stdlib.h>
#include "window.h"
#include "player.h"
#include "pnj.h"

static object_t **create_pnj_sprite(sfVector2f pos)
{
    object_t **sp = malloc(sizeof(object_t *) * 3);
    char pnj[] = "assets/girl.png";
    char text[] = "assets/textbox.png";
    sfVector2f pos_text = (sfVector2f) {pos.x - 150, pos.y - 100};

    sp[0] = create_obj(pnj, pos, (sfIntRect) {1, 8, 16, 15});
    sp[1] = create_obj(pnj, pos, (sfIntRect) {20, 8, 15, 15});
    sp[2] = create_obj(text, pos_text, (sfIntRect) {2, 7, 449, 71});

    for (int i = 0; i < 2; i += 1)
        sfSprite_setScale(sp[i]->sprite, (sfVector2f){3, 3});
    return (sp);
}

pnj_t *create_pnj(void)
{
    pnj_t *pnj = malloc(sizeof(pnj_t) * 1);
    sfVector2f pos_txt;
    char txt[] = "Hey hero please save my father the King !";

    pnj->pos = (sfVector2f) {150, 508};
    pos_txt = (sfVector2f) {pnj->pos.x - 135, pnj->pos.y - 80};
    pnj->sp = create_pnj_sprite(pnj->pos);
    pnj->clock = sfClock_create();
    pnj->king_clock = sfClock_create();
    pnj->king_rect = (sfIntRect) {3, 5, 15, 20};
    pnj->text = malloc(sizeof(text_t) * 1);
    pnj->text = create_text("assets/f.ttf");
    set_text(pnj->text, 21, pos_txt, txt);
    return (pnj);
}

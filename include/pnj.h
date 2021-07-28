/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** pnj.h
*/

#ifndef PNJ__H__
#define PNJ__H__

#include "window.h"
#include "create.h"
#include "my.h"

typedef struct pnj_s {
    object_t **sp;
    sfClock *clock;
    sfClock *king_clock;
    sfVector2f pos;
    sfIntRect king_rect;
    text_t *text;
} pnj_t;

pnj_t *create_pnj(void);
void play_pnj_animation(pnj_t *pnj, window_t *wind, sfVector2f pos);
#endif/*PLAYER__H__*/

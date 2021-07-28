/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** stats.h
*/

#ifndef STATS__H__
#define STATS__H__

#include "create.h"

typedef struct stats_box_s {
    object_t **sp;
    object_t **button;
    text_t **txt;
    sfClock *clock;
} stats_box_t;

stats_box_t *create_stats_box(void);
#endif/*STATS__H__*/

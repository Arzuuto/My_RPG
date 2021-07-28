/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** lose.h
*/

#ifndef LOSE__H__
#define LOSE__H__

#include "create.h"

typedef struct lose_s {
    object_t *sp;
    text_t *txt;
    int status;
    sfClock *clock;
} lose_t;

lose_t *create_lose(void);

#endif/*STATS__H__*/

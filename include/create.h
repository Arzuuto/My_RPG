/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef CREATE__H__
#define CREATE__H__

#include "my.h"

typedef struct object_s{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
} object_t;

typedef struct rect_s{
    sfRectangleShape *rect;
} rect_t;

typedef struct text_s{
    const sfFont *font;
    sfText *text;
} text_t;

typedef struct sound_s{
    sfSound *sound;
    sfSoundBuffer *soundbuffer;
} sound_t;

object_t *create_obj(const char *path_to_spritesheet,
                        sfVector2f pos, sfIntRect rect);
text_t *create_text(const char *path);
void set_text(text_t *text, int size, sfVector2f pos, char *str);
sound_t *create_audio(const char *path);

#endif/*CREATE__H__*/

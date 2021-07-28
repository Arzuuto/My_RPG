/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create.c
*/

#include "my.h"
#include "create.h"
#include <stdlib.h>

object_t *create_obj(const char *path_to_spritesheet,
                        sfVector2f pos, sfIntRect rect)
{
    object_t *object = malloc(sizeof(object_t));
    sfTexture *texture = sfTexture_createFromFile(path_to_spritesheet, NULL);

    object->sprite = sfSprite_create();
    object->texture = texture;
    object->pos = pos;
    object->rect = rect;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setPosition(object->sprite, object->pos);
    sfSprite_setTextureRect(object->sprite, object->rect);
    return (object);
}

text_t *create_text(const char *path)
{
    text_t *text = malloc(sizeof(text_t) * 1);

    text->font = sfFont_createFromFile(path);
    text->text = sfText_create();
    sfText_setFont(text->text, text->font);
    sfText_setColor(text->text, sfBlack);
    return (text);
}

sound_t *create_audio(const char *path)
{
    sound_t *audio = malloc(sizeof(sound_t) * 1);

    audio->sound = sfSound_create();
    audio->soundbuffer = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(audio->sound, audio->soundbuffer);
    return (audio);
}

void set_text(text_t *text, int size, sfVector2f pos, char *str)
{
    sfText_setCharacterSize(text->text, size);
    sfText_setString(text->text, str);
    sfText_setPosition(text->text, pos);
}

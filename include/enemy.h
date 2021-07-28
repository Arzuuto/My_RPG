/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** object.h
*/

#ifndef ENEMY__H__
#define ENEMY__H__

#include "window.h"
#include "create.h"
#include "my.h"
#include "pnj.h"

typedef struct enemy_sprite_s {
    sfSprite *sad_guy;
    sfSprite *orc;
    sfSprite *boss;
    sfSprite *mage;
    sfSprite *fireball;
} enemy_sprite_t;

typedef struct enemy_rect_s {
    sfIntRect sad_guy;
    sfIntRect orc;
    sfIntRect boss;
    sfIntRect mage;
    sfIntRect fireball;
} enemy_rect_t;

typedef struct enemy_pos_s {
    sfVector2f sad_guy;
    sfVector2f orc;
    sfVector2f boss;
    sfVector2f mage;
    sfVector2f fireball;
} enemy_pos_t;

typedef struct enemy_anim_s {
    sfClock *sad_guy;
    sfClock *orc;
    sfClock *boss;
    sfClock *mage;
    sfClock *fireball;
} enemy_anim_t;

typedef struct enemy_move_s {
    sfClock *sad_guy;
    sfClock *orc;
    sfClock *boss;
    sfClock *fireball;
    sfClock *mage;
} enemy_move_t;

typedef struct enemy_hp_s {
    int sad_guy;
    int orc;
    int boss;
    int mage;
} enemy_hp_t;

typedef struct enemy_s {
    enemy_sprite_t *sprite;
    enemy_rect_t *rect;
    enemy_pos_t *pos;
    enemy_anim_t *anim;
    enemy_move_t *move;
    enemy_hp_t *hp;
    sfClock *dmg;
    int status;
} enemy_t;

void create_enemy(sfRenderWindow *win, sfVector2f pos, sfTexture *texture,
           sfIntRect rect);
enemy_anim_t *init_clock_anim(enemy_anim_t *clock);
void animation(sfIntRect *rect, int offset, int max_value, sfClock *clock);
void enemy_animation(enemy_t *enemy);
enemy_rect_t *enemy_rect(enemy_rect_t *rect);
enemy_pos_t *enemy_pos(enemy_pos_t *pos);
sfVector2f pattern_sad_guy(sfVector2f pos, sfClock *clock, int speed);
sfVector2f pattern_orc(sfVector2f pos, sfClock *clock, int speed);
enemy_move_t *init_enemy_move(enemy_move_t *move);
enemy_t *setup_enemy(void);
enemy_hp_t *enemy_hp(enemy_hp_t *hp);
void walk_animation(sfIntRect *rect, int offset, int max_value, sfClock *clock);
void idle_animation(sfIntRect *rect, int offset, int max_value, sfClock *clock);
void init_hp_enemy(enemy_t *enemy);

#endif /*ENEMY__H__*/

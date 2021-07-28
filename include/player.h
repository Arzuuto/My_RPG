/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player.h
*/

#ifndef PLAYER__H__
#define PLAYER__H__

#include "window.h"
#include "create.h"
#include "my.h"
#include "enemy.h"
#include "pnj.h"

typedef enum {
    iron,
    gold
} state;

typedef struct stats_s{
    int lvl;
    int xp;
    int hp;
    int hp_max;
    int attack;
    int speed;
    int pts;
    sfClock *dmg;
    int status;
} stats_t;

typedef struct swords_s {
    object_t **iron;
    object_t **gold;
    sfClock *clock;
    int animation;
    sfClock *dmg;
    int status;
} swords_t;

typedef struct player_s {
    object_t **move;
    object_t **sp_hp;
    swords_t *wp;
    sfClock *clock;
    sfVector2f pos;
    int idle;
    stats_t *stats;
    int sword;
} player_t;

#define LEFT (1)
#define RIGHT (2)
#define STANDAR_MOVEMENT (sfKeyboard_isKeyPressed(sfKeyUp) != sfTrue && \
    sfKeyboard_isKeyPressed(sfKeyDown) != sfTrue && \
    sfKeyboard_isKeyPressed(sfKeyRight) != sfTrue && \
    sfKeyboard_isKeyPressed(sfKeyLeft) != sfTrue)
#define UP_MOVEMENT (player->idle == RIGHT) ? \
    play_animation_right(player, wind) : play_animation_left(player, wind)
#define DOWN_MOVEMENT (player->idle == RIGHT) ? \
    play_animation_right(player, wind) : play_animation_left(player, wind)
#define NO_SP_AT_RIGHT (pos_player.x - rect_player.width \
     - speed <= pos_obj.x + \
    rect_obj.width && pos_player.x + rect_player.width + speed >= pos_obj.x + \
    rect_obj.width && pos_player.y + rect_player.width >= pos_obj.y - \
    rect_obj.height && pos_player.y + rect_player.height >= pos_obj.y - \
    rect_obj.height && pos_player.y - rect_player.height <= pos_obj.y + \
    rect_obj.height)
#define NO_SP_AT_LEFT (pos_player.x + rect_player.width \
     + speed >= pos_obj.x - \
    rect_obj.width && pos_player.x + rect_player.width - speed <= pos_obj.x - \
    rect_obj.width && pos_player.y + rect_player.width >= pos_obj.y - \
    rect_obj.height && pos_player.y + rect_player.height >= pos_obj.y - \
    rect_obj.height && pos_player.y - rect_player.height <= pos_obj.y + \
    rect_obj.height)
#define NO_SP_UP (pos_player.y - rect_player.height - speed <= pos_obj.y + \
    rect_obj.height && pos_player.y + \
    rect_player.height + speed >= pos_obj.y + \
    rect_obj.height && pos_player.x - rect_player.width <= pos_obj.x + \
    rect_player.width && pos_player.x + rect_player.width >= pos_obj.x - \
    rect_obj.width)
#define NO_SP_DOWN (pos_player.y + rect_player.height + speed >= pos_obj.y - \
    rect_obj.height && pos_player.y + rect_player.height \
     - speed <= pos_obj.y - \
    rect_obj.height && pos_player.x - rect_player.width <= pos_obj.x + \
    rect_player.width && pos_player.x + rect_player.width >= pos_obj.x - \
    rect_obj.width)

void play_animation_idle(player_t *player, window_t *wind);
player_t *play_animation_left(player_t *player, window_t *wind);
player_t *play_animation_right(player_t *player, window_t *wind);
player_t *play_player_animation(player_t *player, pnj_t *pnj, window_t *wind);
player_t *create_player(void);
int check_hitbox_up(sfSprite *player, sfSprite *object, int speed);
int check_hitbox_down(sfSprite *player, sfSprite *object, int speed);
int check_hitbox_right(sfSprite *player, sfSprite *object, int speed);
int check_hitbox_left(sfSprite *player, sfSprite *object, int speed);
player_t *check_move_up(player_t *player, pnj_t *pnj, window_t *wind);
player_t *check_move_down(player_t *player, pnj_t *pnj, window_t *wind);
player_t *check_move_right(player_t *player, pnj_t *pnj, window_t *wind);
player_t *check_move_left(player_t *player, pnj_t *pnj, window_t *wind);
player_t *player_set_animation(player_t *player, float x, float y);
void display_quest(player_t *player, pnj_t *pnj, window_t *wind);
void display_stats(stats_t *player, object_t **hp, window_t *wind);
swords_t *create_sp_wp(void);
void display_attack(player_t *player, swords_t *wp, window_t *wind);
int display_attack_left_animation(swords_t *wp, object_t **sp,
                                                window_t *wind);
int display_attack_right_animation(swords_t *wp, object_t **sp,
                                                window_t *wind);
void set_attack_left(player_t *player, object_t **sp);
void set_attack_right(player_t *player, object_t **sp);
int check_hitbox_all(sfSprite *player, sfVector2f pos_obj,
                     sfIntRect rect_obj, int speed);
void add_stats_pts(stats_t *player, object_t **button,
                        sfClock *clock, window_t *wind);
void enemy_attack(player_t *player, sfVector2f pos, sfIntRect rect);
void player_attack_orc(player_t *player, enemy_t *enemy,
                       sfVector2f pos, sfIntRect rect);
void player_attack_sad(player_t *player, enemy_t *enemy,
                       sfVector2f pos, sfIntRect rect);
#endif/*PLAYER__H__*/

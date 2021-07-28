/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** game.h
*/

#ifndef GAME__H__
#define GAME__H__

#include "menu.h"
#include "player.h"
#include "map.h"
#include "pnj.h"
#include "enemy.h"
#include "cursor.h"
#include "inventory.h"
#include "tower.h"
#include "stats.h"
#include "lose.h"

typedef struct game_s {
    object_t *object;
    menu_t *menu;
    menu_t *pause;
    player_t *player;
    pnj_t *pnj;
    text_map_t *text_map;
    pos_map_t *pos_map;
    map_t *map;
    inv_t *inv;
    text_inv_t *text_inv;
    pos_inv_t *pos_inv;
    enemy_t *enemy;
    sfMusic *music;
    cursor_t *cursor;
    int fps;
    int inv_mode;
    int config_map;
    item_pos_t *item_pos;
    item_rect_t *item_rect;
    stats_box_t *box;
    tower_t *tower;
    int box_mode;
    lose_t *lose;
    sfView *view;
} game_t;

game_t *display_menu(game_t *game, window_t *wind);
game_t *play_game(game_t *game, window_t *wind);
int load_file_in_mem(char const *filepath, game_t *game);
void str_to_arr(game_t *game);
void size_rows(game_t *game);
void size_cols(game_t *game);
void display_map(sfRenderWindow *win, game_t *map, sfTexture *texture
                 ,sfVector2f pos);
void map(game_t *map);
sfVector2f set_map(game_t *game, char c, sfTexture *texture
                   ,sfRenderWindow *win);
void char_to_tiles(game_t *game, sfRenderWindow *win);
game_t *preset(game_t *game);
menu_t *animate_play_button(game_t *game, menu_t *menu, window_t *wind);
text_t **create_menu_txt_opt(menu_t *game, int fps);
menu_t *display_opt(game_t *game, menu_t *menu, window_t *wind);
void set_options(game_t *game, menu_t *menu, window_t *wind);
void set_options_sounds(game_t *game, menu_t *menu, window_t *wind);
game_t *display_pause(game_t *game, window_t *wind);
void display_inventory(game_t *game, sfRenderWindow *win);
sfVector2f set_inv(game_t *game, char c, sfTexture *texture,
                   sfRenderWindow *win);
void inv(game_t *inv);
void create_inv(sfRenderWindow *win, game_t *inv, sfTexture *texture,
                 sfVector2f pos);
void preset_inv(game_t *game);
int load_file_in_mem_inv(char const *filepath, game_t *game);
void str_to_arr_inv(game_t *game);
void size_rows_inv(game_t *game);
void size_cols_inv(game_t *game);
sfSprite *display_icon_inv(sfRenderWindow *win);
void main_inventory(game_t *game, sfRenderWindow *win);
void game_c_to_tiles(game_t *game, sfRenderWindow *win);
void find_pos_player(game_t *game);
void do_collisions(game_t *game);
game_t *game_preset(game_t *game);
game_t *display_enemy(game_t *game, sfRenderWindow *win, enemy_t *enemy);
game_t *item_preset(game_t *game);
void do_left(game_t *game);
void do_right(game_t *game);
void do_up(game_t *game);
void do_game_down(game_t *game);
void do_game_collisions(game_t *game);
sfVector2f pattern_boss(game_t *game, sfVector2f boss_pos, sfClock *clock,
                        int speed);
game_t *display_boss(game_t *game, sfRenderWindow *win, enemy_t *enemy);
void check_stats(game_t *game, stats_box_t *box, window_t *wind);
game_t *end_preset(game_t *game);
void end_c_to_tiles(game_t *game, sfRenderWindow *win);
void do_end_collisions(game_t *game);
game_t *enemy_mage(game_t *game, sfRenderWindow *win, enemy_t *enemy);
void manage_king(game_t *game, sfRenderWindow *win);
menu_t *display_opt_pause(game_t *game, menu_t *pause, menu_t *menu,
                                                    window_t *wind);
game_t *display_lose(game_t *game, window_t *wind);
game_t *init_zoom(game_t *game);
void create_zoom(game_t *game);

#endif /*GAME__H__*/

/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** play_game.c
*/

#include "window.h"
#include "menu.h"
#include "game.h"
#include "player.h"
#include "pnj.h"
#include "enemy.h"

static void begin_game(game_t *game, window_t *wind)
{
    char_to_tiles(game, wind->window);
    find_pos_player(game);
    create_zoom(game);
    sfRenderWindow_setView(wind->window, game->view);
    do_collisions(game);
    main_inventory(game, wind->window);
    game = display_enemy(game, wind->window, game->enemy);
    enemy_animation(game->enemy);
    game->player = play_player_animation(game->player, game->pnj, wind);
    play_pnj_animation(game->pnj, wind, game->pnj->pos);
    display_quest(game->player, game->pnj, wind);
    display_stats(game->player->stats, game->player->sp_hp, wind);
    display_attack(game->player, game->player->wp, wind);
    check_stats(game, game->box, wind);
    create_cursor(wind, game->cursor);
    sfRenderWindow_display(wind->window);
    game->pause->status = check_button_pause();
}

static void enter_the_game(game_t *game, window_t *wind)
{
    find_pos_player(game);
    game_c_to_tiles(game, wind->window);
    do_game_collisions(game);
    main_inventory(game, wind->window);
    game = display_boss(game, wind->window, game->enemy);
    game->player = play_player_animation(game->player, game->pnj, wind);
    display_stats(game->player->stats, game->player->sp_hp, wind);
    display_attack(game->player, game->player->wp, wind);
    check_stats(game, game->box, wind);
    create_cursor(wind, game->cursor);
    sfRenderWindow_display(wind->window);
    game->pause->status = check_button_pause();
}

static void end_game(game_t *game, window_t *wind)
{
    find_pos_player(game);
    end_c_to_tiles(game, wind->window);
    do_end_collisions(game);
    main_inventory(game, wind->window);
    play_pnj_animation(game->pnj, wind, game->pnj->pos);
    display_quest(game->player, game->pnj, wind);
    game->player = play_player_animation(game->player, game->pnj, wind);
    display_stats(game->player->stats, game->player->sp_hp, wind);
    display_attack(game->player, game->player->wp, wind);
    check_stats(game, game->box, wind);
    manage_king(game, wind->window);
    create_tower(wind, game->tower);
    create_cursor(wind, game->cursor);
    sfRenderWindow_display(wind->window);
    game->pause->status = check_button_pause();
}

static game_t *game_loop(game_t *game, window_t *wind)
{
    if (game->config_map == 1)
        begin_game(game, wind);
    if (game->config_map == 2)
        enter_the_game(game, wind);
    if (game->config_map == 3)
        end_game(game, wind);
    if (game->player->stats->hp <= 0) {
        game->menu->status = 10;
        game->lose->status = 1;
        sfClock_restart(game->lose->clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) {
        game->player->stats->attack = 1000;
        game->player->stats->speed = 20;
    }
    return (game);
}

game_t *play_game(game_t *game, window_t *wind)
{
    if (game->pause->status == 0) {
        game = game_loop(game, wind);
    } else {
        game = display_pause(game, wind);
    }
    return (game);
}

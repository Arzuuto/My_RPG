/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** manage enemy mage
*/

#include "enemy.h"
#include "game.h"

void create_fireball(sfRenderWindow *win, sfVector2f pos,
                  sfTexture *texture, sfIntRect rect)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {1, 1};

    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(win, sprite, NULL);
}

void fire_animation(sfIntRect *rect, int offset, int max_value, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float second = time.microseconds / 1000000.0;

    if (second > 0.1) {
        rect->left = rect->left + offset;
        if (rect->left >= max_value) {
            rect->left = 7;
        }
        sfClock_restart(clock);
    }
}

sfVector2f pattern_fireball(game_t *game, sfVector2f fire_pos, sfClock *clock,
                            int speed)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float second = time.microseconds / 100000.0;
    int shoot = 0;

    if (second > 0.1) {
        if (game->player->pos.x > fire_pos.x)
            shoot = 1;
        fire_pos.x -= speed;
        if (game->player->pos.y > fire_pos.y && shoot == 0)
            fire_pos.y += speed;
        if (game->player->pos.y < fire_pos.y && shoot == 0)
            fire_pos.y -= speed;
        sfClock_restart(clock);
    }
    return fire_pos;

}

game_t *shoot_fireball(game_t *game, sfRenderWindow *win, enemy_t *enemy)
{
    sfTexture *texture = sfTexture_createFromFile("assets/fireball.png", NULL);

    create_fireball(win, enemy->pos->fireball, texture, enemy->rect->fireball);
    enemy->pos->fireball = pattern_fireball(game, enemy->pos->fireball,
                                            enemy->move->fireball, 7);
    fire_animation(&enemy->rect->fireball, 40, 167, enemy->anim->fireball);
    return game;
}

game_t *enemy_mage(game_t *game, sfRenderWindow *win, enemy_t *enemy)
{
    sfTexture *texture = sfTexture_createFromFile("assets/enemy.png", NULL);
    sfTime time = sfClock_getElapsedTime(enemy->move->mage);
    float second = time.microseconds / 1000000.0;

    create_enemy(win, enemy->pos->mage, texture, enemy->rect->mage);
    idle_animation(&enemy->rect->mage, 16, 131, enemy->anim->mage);
    if (second > 0.1) {
        game = shoot_fireball(game, win, enemy);
        if (second > 15) {
            sfClock_restart(enemy->move->mage);
            enemy->pos->fireball = enemy->pos->mage;
        }
    }
    return game;
}

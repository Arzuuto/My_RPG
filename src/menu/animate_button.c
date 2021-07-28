/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** animate_button.c
*/

#include "my.h"
#include "window.h"
#include "create.h"
#include "menu.h"
#include "game.h"

int button_leftclick_is_clicked(object_t *sp, window_t *wind, sfColor color)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(wind->window);
    sfVector2f sprite = sfSprite_getPosition(sp->sprite);
    sfIntRect rect = sfSprite_getTextureRect(sp->sprite);
    sfVector2f scale = sfSprite_getScale(sp->sprite);

    if (mouse.x >= sprite.x && mouse.x <= sprite.x + rect.width * scale.x &&
        mouse.y >= sprite.y && mouse.y <= sprite.y + rect.height * scale.y &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
        sfRenderWindow_hasFocus(wind->window) == sfTrue) {
            sfSprite_setColor(sp->sprite, color);
            sfRenderWindow_display(wind->window);
                return (1);
    } else
        return (0);
}

int button_is_touched(object_t *sp, text_t *txt, window_t *wind)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(wind->window);
    sfVector2f sprite = sfSprite_getPosition(sp->sprite);
    sfIntRect rect = sfSprite_getTextureRect(sp->sprite);

    if (mouse.x >= sprite.x && mouse.x <= sprite.x + rect.width &&
        mouse.y >= sprite.y && mouse.y <= sprite.y + rect.height)
        sfText_setColor(txt->text, sfWhite);
    else
        sfText_setColor(txt->text, sfBlack);
    return 0;
}

menu_t *animate_play_button(game_t *game, menu_t *menu, window_t *wind)
{
    sfColor brown = sfColor_fromRGB(197, 154, 114);

    button_is_touched(menu->sp[1], menu->txt[0], wind);
    if (button_leftclick_is_clicked(menu->sp[1], wind, brown) == 1) {
        sfSound_play(menu->audio[0]->sound);
        sfClock_restart(menu->clock);
        sfMusic_stop(menu->music);
        sfMusic_setVolume(game->music, 20);
        sfMusic_play(game->music);
        sfMusic_setLoop(menu->music, sfFalse);
        sfMusic_setLoop(game->music, sfTrue);
        menu->status = 1;
    }
    return (menu);
}

menu_t *animate_how_button(menu_t *menu, window_t *wind)
{
    sfColor orange = sfColor_fromRGB(255, 174, 3);

    button_is_touched(menu->sp[2], menu->txt[1], wind);
    if (button_leftclick_is_clicked(menu->sp[2], wind, orange) == 1) {
        sfSound_play(menu->audio[0]->sound);
        sfClock_restart(menu->clock);
        menu->status = 3;
    }
    return (menu);
}

menu_t *animate_quit_button(menu_t *menu, window_t *wind)
{
    button_is_touched(menu->sp[3], menu->txt[2], wind);
    if (button_leftclick_is_clicked(menu->sp[3], wind, sfRed) == 1) {
        sfSound_play(menu->audio[0]->sound);
        sfClock_restart(menu->clock);
        menu->status = 5;
    }
    if (menu->status == 5 && get_seconds(menu->clock) > 0.4)
        menu->status = 6;
    return (menu);
}
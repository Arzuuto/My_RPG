/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_srpite_menu.c
*/

#include "menu.h"
#include "create.h"
#include <stdlib.h>

object_t **create_menu_how()
{
    sfColor orange = sfColor_fromRGB(255, 174, 3);
    object_t **how = malloc(sizeof(object_t *) * 4);
    char sp_how[] = "assets/opt.png";

    how[0] = create_obj("assets/menu/menu.png",
                            (sfVector2f) {275, 260},
                            (sfIntRect) {1 , 118, 443, 104});
    how[1] = create_obj(sp_how, (sfVector2f) {400, 330},
                            (sfIntRect) {151, 0, 148, 103});
    how[2] = create_obj(sp_how, (sfVector2f) {1140, 330},
                            (sfIntRect) {608 , 12, 113, 103});
    how[3] = create_obj("assets/menu/menu.png",
                            (sfVector2f) {1200, 550},
                            (sfIntRect) {1 , 0, 265, 104});
    sfSprite_setColor(how[0]->sprite, orange);
    sfSprite_setScale(how[0]->sprite, (sfVector2f) {3, 4.5});
    sfSprite_setScale(how[1]->sprite, (sfVector2f) {0.8, 0.8});
    sfSprite_setScale(how[2]->sprite, (sfVector2f) {0.8, 0.8});
    return (how);
}

static object_t **create_menu_monster_bg(object_t **sp)
{
    sp[11] = create_obj("assets/menu/sp.png", (sfVector2f) {1790, -50},
                            (sfIntRect) {41, 7, 22, 28});
    sp[12] = create_obj("assets/menu/sp.png", (sfVector2f) {1790, 200},
                            (sfIntRect) {6, 8, 22, 28});
    sp[13] = create_obj("assets/menu/sp.png", (sfVector2f) {1800, 380},
                            (sfIntRect) {112, 9, 18, 26});
    sp[14] = create_obj("assets/menu/sp.png", (sfVector2f) {1780, 550},
                            (sfIntRect) {85, 58, 16, 13});
    sp[15] = create_obj("assets/menu/sp.png", (sfVector2f) {1800, 705},
                            (sfIntRect) {88, 6, 12, 15});
    return (sp);
}

static object_t **create_menu_item_bg(object_t **sp)
{
    sp[5] = create_obj("assets/menu/sp.png", (sfVector2f) {1090, 800},
                            (sfIntRect) {69, 1, 16, 16});
    sp[6] = create_obj("assets/menu/sp.png", (sfVector2f) {910, 800},
                            (sfIntRect) {69, 1, 16, 16});
    sp[7] = create_obj("assets/menu/sp.png", (sfVector2f) {730, 800},
                            (sfIntRect) {69, 1, 16, 16});
    sp[8] = create_obj("assets/menu/sp.png", (sfVector2f) {550, 800},
                            (sfIntRect) {69, 1, 16, 16});
    sp[9] = create_obj("assets/menu/sp.png", (sfVector2f) {510, 300},
                            (sfIntRect) {87, 23, 10, 30});
    sp[10] = create_obj("assets/menu/sp.png", (sfVector2f) {1170, 300},
                            (sfIntRect) {73, 49, 10, 24});
    sp = create_menu_monster_bg(sp);
    return (sp);
}

static object_t **create_menu_heroes_bg(object_t **sp)
{
    sp[0] = create_obj("assets/menu/sp.png", (sfVector2f) {-50, 80},
                            (sfIntRect) {38, 58, 15, 19});
    sp[1] = create_obj("assets/menu/sp.png", (sfVector2f) {-50, 220},
                            (sfIntRect) {1, 56, 15, 18});
    sp[2] = create_obj("assets/menu/sp.png", (sfVector2f) {-50, 380},
                            (sfIntRect) {70, 29, 15, 18});
    sp[3] = create_obj("assets/menu/sp.png", (sfVector2f) {-50, 520},
                            (sfIntRect) {56, 58, 15, 19});
    sp[4] = create_obj("assets/menu/sp.png", (sfVector2f) {-50, 640},
                            (sfIntRect) {87, 77, 14, 21});
    return (sp);
}

object_t **create_menu_bg(void)
{
    object_t **sp = malloc(sizeof(object_t *) * 16);

    sp = create_menu_heroes_bg(sp);
    sp = create_menu_item_bg(sp);
    sp = create_menu_monster_bg(sp);
    return (sp);
}
/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main.c
*/

#include <stdlib.h>
#include "window.h"
#include "game.h"
#include "my.h"

int main(int ac, __attribute__((unused))char **av, char **env)
{
    window_t *wind;

    if (ac != 1 || env[0] == NULL)
        return (84);
    wind = malloc(sizeof(window_t) * 1);
    wind->window_x = 1920;
    wind->window_y = 1080;
    wind = init_window(wind);
    open_window(wind);
    free(wind);
    return 0;
}

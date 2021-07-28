/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** free_array
*/

#include <stdlib.h>

void **free_array(void **array)
{
    int i = 0;

    for (i = 0; array[i]; i++)
        free(array[i]);
    free(array[i]);
}
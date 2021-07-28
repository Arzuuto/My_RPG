/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

static int count_word(char *str, char *filter)
{
    char *token = NULL;
    int i = 0;

    token = strtok(str, filter);
    while (token != NULL) {
        i += 1;
        token = strtok(NULL, filter);
    }
    return (i);
}

char **str_to_tab(char *str, char *filter)
{
    char *duplicate = strdup(str);
    int size = count_word(duplicate, filter);
    char *token;
    char **tab = malloc(sizeof(char *) * (size + 1));
    int i = 0;

    token = strtok(str, filter);
    while (token != NULL) {
        tab[i] = strdup(token);
        i++;
        token = strtok(NULL, filter);
    }
    tab[i] = NULL;
    free(duplicate);
    return (tab);
}

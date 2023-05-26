/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** my_free_array
*/

#include "my.h"

void free_array(char **gree)
{
    for (int i = 0; gree[i]; i++)
        free(gree[i]);
    free(gree);
    gree = NULL;
}

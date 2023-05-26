/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** lemin_count.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my.h"
#include "my_printf.h"

#include <stdlib.h>

int count_ants(lemin_t *lemin)
{
    lemin->ants_count = my_atoi(lemin->buffer_split->words[0]);
    if (lemin->ants_count == 0
        && my_strcmp(lemin->buffer_split->words[0], "0") != 0)
        return 84;
    return 0;
}

int count_nodes(lemin_t *lemin)
{
    for (size_t i = 0;lemin->lines_split[i] != NULL;i++) {
        if (lemin->lines_split[i]->words[0][0] == '#'
            && lemin->lines_split[i]->words[0][1] != '#')
            continue;
        if (my_strcmp(lemin->lines_split[i]->words[0], "##start") == 0) {
            i++;
            lemin->id_start = lemin->lines_split[i]->words[0];
            lemin->nodes_count++;
            continue;
        }
        if (my_strcmp(lemin->lines_split[i]->words[0], "##end") == 0) {
            i++;
            lemin->id_start = lemin->lines_split[i]->words[0];
            lemin->nodes_count++;
            continue;
        }
        if (lemin->lines_split[i]->size == 3)
            lemin->nodes_count++;
    }
    return 0;
}

int count_tunnels(lemin_t *lemin)
{
    for (size_t i = 0;lemin->lines_split[i] != NULL;i++) {
        if (lemin->lines_split[i]->words[0][0] == '#'
            && lemin->lines_split[i]->words[0][1] != '#')
            continue;
        if (lemin->lines_split[i]->size == 2)
            lemin->tunnels_count++;
    }
    return 0;
}

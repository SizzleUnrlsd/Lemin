/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** ant.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my_printf.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

ant_t *init_ant(int32_t id, int32_t start_index, int32_t nodes_count)
{
    ant_t *ant = malloc(sizeof(ant_t));
    if (ant == NULL)
        return NULL;
    ant->id = id;
    ant->node_index = start_index;
    ant->last_node_index = start_index;
    ant->nodes_value = malloc(sizeof(int32_t) * nodes_count);
    if (ant->nodes_value == NULL)
        return NULL;
    for (int32_t i = 0;i < nodes_count;i++)
        ant->nodes_value[i] = 0;
    return ant;
}

void terminate_ant(ant_t *ant)
{
    free(ant);
}

int init_ants(lemin_t *lemin)
{
    lemin->ants = malloc(sizeof(ant_t *) * (lemin->ants_count + 1));
    if (lemin->ants == NULL)
        return 84;
    lemin->ants[lemin->ants_count] = NULL;
    int start_index = get_index_node_by_id(lemin, lemin->id_start);
    for (uint_fast32_t  i = 0;i < lemin->ants_count;i++) {
        lemin->ants[i] = init_ant(i + 1, start_index, lemin->nodes_count);
        if (lemin->ants[i] == NULL)
            return 84;
    }
    return 0;
}

/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** lemin.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my_printf.h"
#include "my.h"

#include <stdlib.h>
#include <stdio.h>

lemin_t *init_lemin(void)
{
    lemin_t *lemin = malloc(sizeof(lemin_t));
    if (lemin == NULL)
        return NULL;
    if (read_stdin(lemin) == 84)
        return NULL;
    if (count_lemin_objects(lemin) == 84)
        return NULL;
    if (init_nodes(lemin) == 84)
        return NULL;
    if (init_tunnels(lemin) == 84)
        return NULL;
    lemin->graph = init_graph(lemin->nodes_count);
    if (lemin->graph == NULL)
        return NULL;
    if (fill_graph(lemin) == 84)
        return NULL;
    if (init_ants(lemin) == 84)
        return NULL;
    return lemin;
}

void terminate_lemin(lemin_t *lemin)
{
    for (uint_fast32_t i = 0;lemin->nodes[i] != NULL;i++)
        terminate_node(lemin->nodes[i]);
    free(lemin->nodes);
    for (uint_fast32_t i = 0;lemin->tunnels[i] != NULL;i++)
        terminate_tunnel(lemin->tunnels[i]);
    free(lemin->tunnels);
    terminate_buffer(lemin->buffer);
    terminate_word_array(lemin->buffer_split);
    for (uint_fast32_t i = 0;lemin->lines_split[i] != NULL;i++)
        terminate_word_array(lemin->lines_split[i]);
    free(lemin->lines_split);
    terminate_graph(lemin->graph);
    free(lemin);
}

int count_lemin_objects(lemin_t *lemin)
{
    lemin->ants_count = 0;
    lemin->nodes_count = 0;
    lemin->tunnels_count = 0;
    if (count_ants(lemin) == 84)
        return 84;
    if (count_nodes(lemin) == 84)
        return 84;
    if (count_tunnels(lemin) == 84)
        return 84;
    return 0;
}

void print_ants_node(lemin_t *lemin)
{
    my_printf("\n");
    char *node_id = NULL;
    for (uint32_t i = 0;i < lemin->ants_count;i++) {
        node_id = lemin->nodes[lemin->ants[i]->node_index]->id;
        my_printf(" %d:%s ", lemin->ants[i]->id, node_id);
    }
    my_printf("\n");
}

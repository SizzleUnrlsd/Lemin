/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** fill_graph.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my_printf.h"
#include "my.h"

#include <stdlib.h>

int get_index_node_by_id(lemin_t *lemin, char *id)
{
    for (int i = 0;lemin->nodes[i] != NULL;i++)
        if (my_strcmp(lemin->nodes[i]->id, id) == 0)
            return i;
    return -1;
}

position_t get_pos_by_index(lemin_t *lemin, int index)
{
    return lemin->nodes[index]->position;
}

position_t get_pos_by_id(lemin_t *lemin, char *id)
{
    int index = get_index_node_by_id(lemin, id);
    if (index == -1)
        return (position_t){-1, -1};
    return get_pos_by_index(lemin, index);
}

int fill_start_end_graph(lemin_t *lemin)
{
    int start_index = get_index_node_by_id(lemin, lemin->id_start);
    int end_index = get_index_node_by_id(lemin, lemin->id_end);
    if (start_index == -1 || end_index == -1)
        return 84;
    for (size_t i = 0;lemin->nodes[i] != NULL;i++) {
        lemin->graph->matrix[start_index][i].type = START_NODE;
        lemin->graph->matrix[i][start_index].type = START_NODE;
    }
    for (size_t i = 0;lemin->nodes[i] != NULL;i++) {
        lemin->graph->matrix[end_index][i].type = END_NODE;
        lemin->graph->matrix[i][end_index].type = END_NODE;
    }
    return 0;
}

int fill_graph(lemin_t *lemin)
{
    if (fill_start_end_graph(lemin) == 84)
        return 84;
    for (size_t i = 0;lemin->tunnels[i] != NULL;i++) {
        int index_node1 = get_index_node_by_id(lemin, lemin->tunnels[i]->id1);
        int index_node2 = get_index_node_by_id(lemin, lemin->tunnels[i]->id2);
        if (index_node1 == -1 || index_node2 == -1)
            return 84;
        lemin->graph->matrix[index_node1][index_node2].link = LINKED;
        lemin->graph->matrix[index_node2][index_node1].link = LINKED;
    }
    position_t end_pos = get_pos_by_id(lemin, lemin->id_end);
    for (size_t i = 0;lemin->nodes[i] != NULL;i++) {
        position_t start_pos = get_pos_by_index(lemin, i);
        for (size_t j = 0;lemin->nodes[j] != NULL;j++) {
            int distance_end = calcul_distance(start_pos, end_pos);
            lemin->graph->matrix[i][j].distance_end = distance_end;
            lemin->graph->matrix[j][i].distance_end = distance_end;
        }
    }
    return 0;
}

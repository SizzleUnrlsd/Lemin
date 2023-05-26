/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** move_ant.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my_printf.h"

#include <stdlib.h>

int is_node_occuped(lemin_t *lemin, int node_index)
{
    int32_t end_index = get_index_node_by_id(lemin, lemin->id_end);
    int32_t start_index = get_index_node_by_id(lemin, lemin->id_start);
    for (uint_fast32_t i = 0; i < lemin->ants_count;i++) {
        if (lemin->ants[i]->node_index == end_index
            || lemin->ants[i]->node_index == start_index)
            continue;
        if (lemin->ants[i]->node_index == node_index)
            return 1;
    }
    return 0;
}

int calcul_best_distance_count(lemin_t *lemin, ant_t *ant)
{
    int32_t best_distance_count = 0;
    for (int i = 0;i < lemin->nodes_count;i++) {
        if (lemin->graph->matrix[ant->node_index][i].link == LINKED
            && !is_node_occuped(lemin, i)) {
            best_distance_count++;
        }
    }
    return best_distance_count;
}

distance_pair_t *create_best_distance_pair(lemin_t *lemin, ant_t *ant,
    int best_distance_count)
{
    distance_pair_t *best_distance_pair = malloc(sizeof(distance_pair_t) *
        best_distance_count);
    if (best_distance_pair == NULL)
        return NULL;
    int best_distance_pair_index = 0;
    for (int32_t i = 0;i < lemin->nodes_count;i++) {
        if (lemin->graph->matrix[ant->node_index][i].link == LINKED
            && !is_node_occuped(lemin, i)) {
            best_distance_pair[best_distance_pair_index].index = i;
            best_distance_pair[best_distance_pair_index].distance =
                lemin->graph->matrix[i][ant->node_index].distance_end;
            best_distance_pair_index++;
        }
    }
    return best_distance_pair;
}

int update_position(lemin_t *lemin, ant_t *ant,
                int best_index, bucket_str_t *sb)
{
    if (is_node_occuped(lemin, best_index))
        return 0;
    if (ant->node_index == best_index)
        return 0;
    ant->nodes_value[ant->node_index] += 1;
    char *node_id = lemin->nodes[best_index]->id;
    bucket_str_appendf(sb, "P%d-%s ", ant->id, node_id);
    ant->last_node_index = ant->node_index;
    ant->node_index = best_index;
    return 0;
}

int move_ant(lemin_t *lemin, ant_t *ant, bucket_str_t *sb)
{
    int32_t end_index = get_index_node_by_id(lemin, lemin->id_end);
    if (ant->node_index == end_index)
        return 0;
    int best_distance_count = calcul_best_distance_count(lemin, ant);
    if (best_distance_count == 0)
        return 0;
    distance_pair_t *best_distance_pair = create_best_distance_pair(lemin,
        ant, best_distance_count);
    if (best_distance_pair == NULL)
        return 84;
    sort_distance_pair_array(best_distance_pair, best_distance_count, ant);
    int best_sort_distance_index = ant->nodes_value[ant->node_index];
    if (best_sort_distance_index >= best_distance_count)
        return 84;
    int32_t best_index = best_distance_pair[best_sort_distance_index].index;
    free(best_distance_pair);
    return update_position(lemin, ant, best_index, sb);
}

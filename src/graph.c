/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** graph.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my_printf.h"

#include <stdlib.h>

graph_t *init_graph(size_t size)
{
    graph_t *graph = malloc(sizeof(graph_t));
    if (graph == NULL)
        return NULL;
    graph->size = size;
    graph->matrix = malloc(sizeof(graph_node_t *) * size);
    if (graph->matrix == NULL)
        return NULL;
    for (size_t i = 0; i < size; i++) {
        graph->matrix[i] = malloc(sizeof(graph_node_t) * size);
        if (graph->matrix[i] == NULL)
            return NULL;
        for (size_t j = 0; j < size; j++) {
            graph->matrix[i][j].link = NOT_LINKED;
            graph->matrix[i][j].type = NORMAL_NODE;
            graph->matrix[i][j].distance_end = 0;
        }
    }
    return graph;
}

void terminate_graph(graph_t *graph)
{
    for (size_t i = 0; i < graph->size; i++)
        free(graph->matrix[i]);
    free(graph->matrix);
    free(graph);
}

void print_graph(graph_t *graph)
{
    (void)graph;
}

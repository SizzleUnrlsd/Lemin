/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** node.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my_printf.h"
#include "my.h"

#include <stdlib.h>
#include <stdio.h>

node_t *init_node(word_array_t *line, unsigned char type)
{
    if (line->size != 3)
        return NULL;
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL)
        return NULL;
    node->id = line->words[0];
    node->position.x = my_atoi(line->words[1]);
    if (node->position.x == 0 && my_strcmp(line->words[1], "0") != 0)
        return NULL;
    node->position.y = my_atoi(line->words[2]);
    if (node->position.y == 0 && my_strcmp(line->words[2], "0") != 0)
        return NULL;
    node->type = type;
    return node;
}

void terminate_node(node_t *node)
{
    free(node);
}

int init_special_node(lemin_t *lemin, size_t *i, size_t *nodes_index)
{
    if (lemin->lines_split[(*i)]->words[0][0] == '#'
        && lemin->lines_split[(*i)]->words[0][1] != '#')
        return CONTINUE;
    if (my_strcmp(lemin->lines_split[(*i)]->words[0], "##start") == 0) {
        lemin->nodes[(*nodes_index)] = init_node(lemin->lines_split[++(*i)],
            START_NODE);
        if (lemin->nodes[(*nodes_index)] == NULL)
            return 84;
        lemin->id_start = lemin->nodes[(*nodes_index)++]->id;
        return CONTINUE;
    }
    if (my_strcmp(lemin->lines_split[(*i)]->words[0], "##end") == 0) {
        lemin->nodes[(*nodes_index)] = init_node(lemin->lines_split[++(*i)],
            END_NODE);
        if (lemin->nodes[(*nodes_index)] == NULL)
            return 84;
        lemin->id_end = lemin->nodes[(*nodes_index)++]->id;
        return CONTINUE;
    }
    return 0;
}

int init_nodes_loop(lemin_t *lemin, size_t *i, size_t *nodes_index)
{
    int status = init_special_node(lemin, i, nodes_index);
    if (status != 0)
        return status;
    if (lemin->lines_split[(*i)]->size == 3) {
        lemin->nodes[(*nodes_index)] = init_node(lemin->lines_split[(*i)],
            NORMAL_NODE);
        if (lemin->nodes[(*nodes_index)++] == NULL)
            return 84;
    }
    return 0;
}

int init_nodes(lemin_t *lemin)
{
    lemin->nodes = malloc(sizeof(node_t *) * (lemin->nodes_count + 1));
    if (lemin->nodes == NULL)
        return 84;
    lemin->nodes[lemin->nodes_count] = NULL;
    size_t nodes_index = 0;
    int status = 0;
    for (size_t i = 0;lemin->lines_split[i] != NULL;i++) {
        status = init_nodes_loop(lemin, &i, &nodes_index);
        if (status == 84)
            return 84;
        if (status == CONTINUE)
            continue;
    }
    return 0;
}

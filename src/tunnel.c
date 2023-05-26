/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** tunnel.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my_printf.h"
#include "my.h"

#include <stdlib.h>
#include <stdio.h>

tunnel_t *init_tunnel(word_array_t *line)
{
    tunnel_t *tunnel = malloc(sizeof(tunnel_t));
    if (tunnel == NULL)
        return NULL;
    tunnel->id1 = line->words[0];
    tunnel->id2 = line->words[1];
    return tunnel;
}

void terminate_tunnel(tunnel_t *tunnel)
{
    free(tunnel);
}

int init_tunnels_loop(lemin_t *lemin, size_t i, size_t *tunnels_index)
{
    if (lemin->lines_split[i]->words[0][0] == '#'
        && lemin->lines_split[i]->words[0][1] != '#')
            return CONTINUE;
    if (lemin->lines_split[i]->size == 2) {
        lemin->tunnels[(*tunnels_index)] = init_tunnel(lemin->lines_split[i]);
        if (lemin->tunnels[(*tunnels_index)++] == NULL)
            return 84;
    }
    return 0;
}

int init_tunnels(lemin_t *lemin)
{
    lemin->tunnels = malloc(sizeof(tunnel_t *) * (lemin->tunnels_count + 1));
    if (lemin->tunnels == NULL)
        return 84;
    size_t tunnels_index = 0;
    int status = 0;
    lemin->tunnels[lemin->tunnels_count] = NULL;
    for (size_t i = 0;lemin->lines_split[i] != NULL;i++) {
        status = init_tunnels_loop(lemin, i, &tunnels_index);
        if (status == 84)
            return 84;
        if (status == CONTINUE)
            continue;
    }
    return 0;
}

/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** move_all_ants.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my_printf.h"
#include "bucket.h"

#include <stdlib.h>

int all_ants_are_arrived(lemin_t *lemin)
{
    int32_t end_index = get_index_node_by_id(lemin, lemin->id_end);
    for (uint_fast32_t i = 0; i < lemin->ants_count;i++) {
        if (lemin->ants[i]->node_index != end_index)
            return 0;
    }
    return 1;
}

int move_ant_one_time(lemin_t *lemin, bucket_str_t *sb)
{
    for (uint_fast32_t i = 0; i < lemin->ants_count;i++) {
        if (move_ant(lemin, lemin->ants[i], sb) == 84)
            return 84;
    }
    return 0;
}

int move_all_ants(lemin_t *lemin)
{
    print_lines(lemin);
    bucket_str_t *sb = bucket_str_init();
    bucket_str_appendf(sb, "#moves\n");
    while (!all_ants_are_arrived(lemin)) {
        if (move_ant_one_time(lemin, sb) == 84)
            return 84;
        bucket_str_appendf(sb, "\n");
    }
    bucket_str_print(sb);
    return 0;
}

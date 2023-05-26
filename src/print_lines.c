/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** print_lines.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my_printf.h"
#include "bucket.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int print_lines(lemin_t *lemin)
{
    bucket_str_t *sb = bucket_str_init();

    int index = 0;
    bucket_str_appendf(sb, "#number_of_ants\n");
    bucket_str_appendf(sb, "%s\n", lemin->lines_split[index++]->str);
    bucket_str_appendf(sb, "#rooms\n");
    while (lemin->lines_split[index]->size == 3 ||
        (lemin->lines_split[index]->str[0] == '#' &&
        lemin->lines_split[index]->str[1] == '#')) {
        bucket_str_appendf(sb, "%s\n", lemin->buffer_split->words[index++]);
    }
    my_printf("#tunnels\n");
    while (lemin->lines_split[index] != NULL) {
        bucket_str_appendf(sb, "%s\n", lemin->buffer_split->words[index++]);
    }
    bucket_str_print(sb);
    return 0;
}

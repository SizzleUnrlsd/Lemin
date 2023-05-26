/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** lemin_read_input.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my_printf.h"
#include "my.h"

#include <stdlib.h>
#include <stdio.h>

int read_stdin(lemin_t *lemin)
{
    char *line = NULL;
    size_t size = 0;
    lemin->buffer = init_buffer();
    if (lemin->buffer == NULL)
        return 84;
    while (getline(&line, &size, stdin) != -1) {
        if (append_buffer(lemin->buffer, line) == 84)
            return 84;
    }
    free(line);
    if (lemin->buffer->size == 0)
        return 84;
    lemin->buffer->data = clean_buffer(lemin->buffer->data);
    if (lemin->buffer->data == NULL)
        return 84;
    if (split_buffer(lemin) == 84)
        return 84;
    return 0;
}

int split_buffer(lemin_t *lemin)
{
    lemin->buffer_split = str_to_word_array(
        get_buffer_data(lemin->buffer), "\n");
    if (lemin->buffer_split == NULL)
        return 84;
    lemin->lines_split = malloc(sizeof(word_array_t *)
        * (lemin->buffer_split->size + 1));
    if (lemin->lines_split == NULL)
        return 84;
    lemin->lines_split[lemin->buffer_split->size] = NULL;
    for (size_t i = 0;i < lemin->buffer_split->size;i++) {
        if (error_case(lemin->buffer_split->words[i]) == 84)
            return 84;
        lemin->lines_split[i] = str_to_word_array(
            lemin->buffer_split->words[i], " -");
        if (lemin->lines_split[i] == NULL)
            return 84;
    }
    return 0;
}

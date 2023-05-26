/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-minishell1-clement-antoine.xavier
** File description:
** str_to_word_array_util.c
*/

#include "my.h"
#include "my_printf.h"
#include "str_to_word_array.h"
#include <stdlib.h>

int is_separator(char c, const char *seperators)
{
    for (size_t i = 0;seperators[i] != '\0';i++) {
        if (c == seperators[i])
            return 1;
    }
    return 0;
}

void print_word_array(word_array_t *word_array)
{
    size_t i = 0;
    for (i = 0;i < word_array->size;i++) {
        my_printf(" %s ", word_array->words[i]);
    }
    my_printf("\n");
}

void terminate_word_array(word_array_t *word_array)
{
    for (size_t i = 0;i < word_array->size;i++) {
        free(word_array->words[i]);
    }
    free(word_array->words);
    free(word_array->str);
    free(word_array->separators);
    free(word_array);
}

/*
** EPITECH PROJECT, 2022
** json_parser [WSL : Fedora]
** File description:
** str_to_word_array.c
*/

#include "my.h"
#include "my_printf.h"
#include "str_to_word_array.h"
#include <stdlib.h>

size_t words_size(const char *str, const char *seperators)
{
    size_t size = 0;
    int in_words = OUT;
    for (size_t i = 0;str[i] != '\0';i++) {
        if (is_separator(str[i], seperators) == 1 && in_words == IN)
            in_words = OUT;
        if (is_separator(str[i], seperators) == 0 && in_words == OUT) {
            in_words = IN;
            size++;
        }
    }
    return size;
}

int fill_word(word_array_t *word_array, size_t i, size_t size)
{
    word_array->words[word_array->index] = malloc(
        sizeof(char) * (size + 1));
    if (word_array->words[word_array->index] == NULL)
        return 84;
    word_array->words[word_array->index][size] = '\0';
    for (size_t j = 0;j < size;j++)
        word_array->words[word_array->index][j] = word_array->str[i - size + j];
    word_array->index++;
    return 0;
}

int fill_words_loop(word_array_t *word_array, size_t i,
    size_t *size, size_t *in_words)
{
    if (is_separator(word_array->str[i],  word_array->separators) == 0
        && *in_words == OUT) {
        *in_words = IN;
        *size = 0;
    }
    if (is_separator(word_array->str[i], word_array->separators) == 1
        && *in_words == IN) {
        *in_words = OUT;
        if (fill_word(word_array, i, *size) == 84)
            return 84;
    }
    return 0;
}

int fill_words(word_array_t *word_array)
{
    size_t i = 0, size = 0, in_words = OUT;
    word_array->index = 0;
    while (word_array->str[i] != '\0') {
        if (fill_words_loop(word_array, i, &size, &in_words) == 84)
            return 84;
        size++;
        i++;
    }
    if (in_words == IN)
        if (fill_word(word_array, i, size) == 84)
            return 84;
    return 0;
}

word_array_t *str_to_word_array(const char *str, const char *seperators)
{
    word_array_t *word_array = malloc(sizeof(word_array_t));
    word_array->size = words_size(str, seperators);
    word_array->words = malloc(
        sizeof(char *) * (word_array->size + 1));
    word_array->words[word_array->size] = NULL;
    word_array->separators = my_strdup(seperators);
    word_array->str = my_strdup(str);
    if (word_array->str == NULL)
        return NULL;
    if (fill_words(word_array) == 84)
        return NULL;
    return word_array;
}

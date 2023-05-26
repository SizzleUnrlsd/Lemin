/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-minishell1-clement-antoine.xavier
** File description:
** str_to_word_array.h
*/

#ifndef _STR_TO_WORD_ARRAY_H_
    #define _STR_TO_WORD_ARRAY_H_

    #include <stdlib.h>

typedef struct word_array_s {
    char **words;
    size_t size;
    char *separators;
    char *str;
    size_t index;
} word_array_t;

    #define IN 1
    #define OUT 0

size_t words_size(const char *str, const char *seperators);
int fill_word(word_array_t *word_array, size_t i, size_t size);
int fill_words_loop(word_array_t *word_array, size_t i,
    size_t *size, size_t *in_words);
int fill_words(word_array_t *word_array);
word_array_t *str_to_word_array(const char *str, const char *seperators);
int is_separator(char c, const char *seperators);
void print_word_array(word_array_t *word_array);
void terminate_word_array(word_array_t *word_array);

#endif /* _STR_TO_WORD_ARRAY_H_ */

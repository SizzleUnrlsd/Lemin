/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

#include "my.h"

int m_strlen(char const * str);

int is_alphanumeric(char c)
{
    if (c != '\n')
        return 1;
    return 0;
}

int count_word(const char *str, int str_len)
{
    int count = 0;
    for (int i = 0;i < str_len;i++) {
        if (is_start_or_stop_word(str, i, str_len, 1) == 1) {
            count++;
        }
    }
    count++;
    return count;
}

char *copy_word(const char *str, int word_start, int word_stop)
{
    int word_len = (word_stop - word_start) + 1;
    char *word = (char *)malloc(word_len + 1);

    for (int i = 0;i < word_len;i++) {
        word[i] = str[i + word_start];
    }
    word[word_len] = '\0';
    return word;
}

char **my_str_to_word_array(const char *str)
{
    int str_len = m_strlen(str);
    int num_of_word = count_word(str, str_len);
    char **array = (char **)malloc(sizeof(char *) * (num_of_word + 1));
    int word_start = 0, word_stop = 0, word_index = 0;
    for (int i = 0;i < str_len;i++) {
        if (is_start_or_stop_word(str, i, str_len, 1) == 1) {
            word_start = i;
        }
        if (is_start_or_stop_word(str, i, str_len, 2) == 2) {
            word_stop = i;
            array[word_index] = copy_word(str, word_start, word_stop);
            word_index++;
        }
    }
    array[word_index] = NULL;
    return array;
}

size_t word_array_size(char **array)
{
    size_t size = 0;
    for (int i = 0;array[i] != NULL;i++)
        size++;
    return size;
}

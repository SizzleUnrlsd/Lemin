/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday09-clement-antoine.xavier
** File description:
** my_str_to_word_array_util.c
*/

#include "my.h"

int is_start_or_stop_word_special_case(const char *str,
    int i,
    int start_or_stop)
{
    if (i == 0) {
        if (is_alphanumeric(str[i]) == 1
                && start_or_stop == 1)
            return 1;
        if (is_alphanumeric(str[i]) == 1
                && is_alphanumeric(str[i + 1]) == 0
                && start_or_stop == 2)
            return 2;
        return 0;
    }
    if (is_alphanumeric(str[i - 1]) == 0
            && is_alphanumeric(str[i])
            && start_or_stop == 1)
        return 1;
    if (is_alphanumeric(str[i]) == 1
            && start_or_stop == 2)
        return 2;
    return 0;
}

int is_start_or_stop_word(const char *str,
    int i,
    int str_len,
    int start_or_stop)
{
    if (i == 0 || i == str_len - 1) {
        return is_start_or_stop_word_special_case(str,
            i, start_or_stop);
    }
    if (is_alphanumeric(str[i - 1]) == 0
            && is_alphanumeric(str[i]) == 1
            && start_or_stop == 1)
        return 1;
    if (is_alphanumeric(str[i]) == 1
            && is_alphanumeric(str[i + 1]) == 0
            && start_or_stop == 2)
        return 2;
    return 0;
}

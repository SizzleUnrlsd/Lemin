/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

int m_strlen(char const * str);

char *my_strcpy(char * dest, char const *src);

char *my_strdup(const char *str)
{
    int str_len = m_strlen(str);
    char *copy = (char *)malloc(str_len + 1);
    my_strcpy(copy, str);
    copy[str_len] = '\0';
    return copy;
}

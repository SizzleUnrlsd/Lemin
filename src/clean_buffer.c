/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** clean_buffer.c
*/

#include "lemin.h"
#include "my.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

void remove_comment_extend(char *str, char **new_str, bool cpy, int (*count))
{
    int i = 0;
    for (i = 0; str[i + 2]; i++) {
        if (str[i] == '#' && str[i + 1] != '#' && str[i + 2] != '#') {
            cpy = true; continue;
        }
        if (str[i] == '#' && str[i + 1] == '#'
        && str[i + 2] != '#' && cpy == false) {
            new_str[0][(*count)] = str[i];
            new_str[0][(*count) + 1] = str[i + 1];
            (*count) = (*count) + 2;
            i++;continue;
        }
        if (str[i] == '\n') {
            cpy = false;
        }
        if (cpy == false) {
            new_str[0][(*count)] = str[i];
            (*count)++;continue;
        }
    }
}

char *clean_buffer(char *str)
{
    bool cpy = false;
    int count = 0;
    char *new_str = malloc(sizeof(char) * (m_strlen(str) + 1));
    if (new_str == NULL)
        return NULL;
    remove_comment_extend(str, &new_str, cpy, &count);
    new_str[count++] = str[m_strlen(str) - 2];
    new_str[count] = '\0';
    return new_str;
}

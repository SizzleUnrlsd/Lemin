/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** print_array
*/
#include "my.h"

int len_array(char **array)
{
    int i = 0;
    if (array == NULL)
        return 0;
    for (; array[i]; i++);
    return i;
}

void print_array(char **array, char c)
{
    int size = len_array(array);
    for (int i = 0; i != size; i++) {
        m_putstr(array[i]);
        if (c != 0)
            m_putchar(c);
    }
    return;
}

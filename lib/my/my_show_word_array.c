/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** my_show_word_array
*/

#include "my.h"

int my_show_word_array(char **tab)
{
    int i = 0;
    while (tab[i] != 0) {
        m_putstr(tab[i]);
        m_putchar('\n');
        i++;
    }

    return 0;
}

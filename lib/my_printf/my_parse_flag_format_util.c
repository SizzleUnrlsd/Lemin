/*
** EPITECH PROJECT, 2022
** B-CPE-101-RUN-1-1-myprintf-kovalen-dimitri.ramaretty
** File description:
** my_parse_flag_format_util.c
*/

#include "my_printf.h"

int is_numeric(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int print_width_space(int space)
{
    for (int i = 0;i < space;i++)
        my_putchar(' ');
    return space - 1;
}

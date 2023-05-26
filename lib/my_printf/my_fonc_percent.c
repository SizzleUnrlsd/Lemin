/*
** EPITECH PROJECT, 2022
** B-CPE-101-RUN-1-1-myprintf-kovalen-dimitri.ramaretty
** File description:
** my_fonc_%.c
*/

#include "my_printf.h"

int my_fonc_percent(va_list *param_list, format_flag_t *format_flag)
{
    (void)*param_list;
    (void)*format_flag;
    return my_putchar('%');
}

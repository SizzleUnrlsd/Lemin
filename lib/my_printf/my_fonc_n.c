/*
** EPITECH PROJECT, 2022
** B-CPE-101-RUN-1-1-myprintf-kovalen-dimitri.ramaretty
** File description:
** my_fonc_n.c
*/

#include "my_printf.h"
#include <stdarg.h>

int my_fonc_n(va_list *param_list, format_flag_t *format_flag)
{
    int *n = va_arg(*param_list, int*);
    *n = format_flag->len_last;
    return 0;
}

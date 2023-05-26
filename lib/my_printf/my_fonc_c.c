/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_fonc_c
*/

#include "my_printf.h"
#include <stdarg.h>

int my_fonc_c(va_list *param_list, format_flag_t *format_flag)
{
    int count_char = 0;
    char c = (char)va_arg(*param_list, int);
    count_char += print_width_space(format_flag->width);
    count_char += my_putchar(c);
    return count_char;
}

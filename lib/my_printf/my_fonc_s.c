/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_fonc_s
*/

#include "my_printf.h"
#include <stdarg.h>

int my_fonc_s(va_list *param_list, format_flag_t *format_flag)
{
    int count_char = 0;
    char *str = va_arg(*param_list, char *);
    count_char += print_width_space(format_flag->width);
    count_char += my_putstr(str);
    return count_char;
}

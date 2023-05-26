/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_fonc_bin
*/

#include <stdarg.h>
#include "my_printf.h"

int my_fonc_bin(va_list *param_list, format_flag_t *format_flag)
{
    int count_char = 0;
    int num = va_arg(*param_list, long long);
    count_char += print_width_space(format_flag->width);
    count_char += my_put_nbr_base(num, "01", format_flag->length_modifier);
    return count_char;
}

/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** mini_printf
*/

#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>

const printf_format_t my_printf_format_tab[NUM_OF_FORMAT] = {
    {'d', &my_fonc_i},
    {'i', &my_fonc_i},
    {'s', &my_fonc_s},
    {'c', &my_fonc_c},
    {'x', &my_fonc_hexamini},
    {'X', &my_fonc_hexa},
    {'o', &my_fonc_octal},
    {'b', &my_fonc_bin},
    {'u', &my_fonc_u},
    {'f', &my_fonc_f},
    {'S', &my_fonc_s_max},
    {'p', &my_fonc_p},
    {'n', &my_fonc_n},
    {'%', &my_fonc_percent}
};

int in_lenght_modifier(char c)
{
    const char *my_lenght_modif = "hlL";
    for (int i = 0; i < 3; i++) {
        if (c == my_lenght_modif[i])
            return 1;
    }
    return 0;
}

int is_charact(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

int find_end_format(const char *format, int start)
{
    int i = start;
    while (1) {
        if (in_format(format[i], my_printf_format_tab) == 1)
            return i ;
        if (is_charact(format[i]) &&
            (in_format(format[i], my_printf_format_tab) == 0
            || in_lenght_modifier(format[i]) == 0))
            return -i;
        i++;
    }
    return 1;
}

int print_params(const char *format, int i, va_list *param_list,
    int last_count)
{
    int count_char = 1;
    format_flag_t format_flag = {last_count, "", 0, 0, 0};
    int conversion_index = find_end_format(format, i);
    if (conversion_index < 0) {
        conversion_index *= -1;
        my_putchar('%');
        my_putchar(format[conversion_index]);
        return 2;
    }
    parse_flag_format(format, i, &format_flag, my_printf_format_tab);
    for (int j = 0;j < NUM_OF_FORMAT;j++)
        if (my_printf_format_tab[j].format == format[conversion_index]) {
            count_char += my_printf_format_tab[j].print_format(param_list,
                &format_flag);
        }
    return count_char;
}

int my_printf(const char *format, ...)
{
    va_list param_list;
    va_start(param_list, format);
    int i = 0, count = 0, last_count = 1;
    while (format[i] != '\0') {
        if (format[i] == '%') {
            last_count += print_params(format, i + 1, &param_list, last_count);
            count += last_count;
            i = find_end_format(format, i) + 1;
            i = (i < 0) ? -i : i;
            i++;
        } else {
            count += my_putchar(format[i]);
            i++;
        }
    }
    va_end(param_list);
    return count + 1;
}

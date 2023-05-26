/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_parse_flag_format
*/

#include "my_printf.h"
#include <stdlib.h>
#include <stdio.h>

const printf_length_modifier_t my_length_modifier[NUM_LENGTH_MODIFIER] = {
    {'h', 0xffff},
    {'l', 0xffffffffffffffff},
    {'z', 0xffffffff}
};

int in_format(char c,
    const printf_format_t my_printf_format_tab[NUM_OF_FORMAT])
{
    for (int i = 0;i < NUM_OF_FORMAT;i++)
        if (c == my_printf_format_tab[i].format)
            return 1;
    return 0;
}

int get_precision(const char *format, int start, int end)
{
    int precision_start = -1;
    for (int i = start;i < end + 1;i++)
        if (format[i] == '.') {
            precision_start = i;
            break;
        }
    if (precision_start == -1)
        return 6;
    char *precision_str = malloc(end - precision_start);
    int i;
    for (i = precision_start;is_numeric(format[i]) == 1;i++)
        precision_str[i - precision_start] = format[i];
    precision_str[i - precision_start] = '\0';
    int precision = my_getnbr(precision_str);
    free(precision_str);
    return precision;
}

unsigned long long get_length_modifier(const char *format, int start, int end)
{
    int format_length = end - start;
    if (format_length < 1)
        return 0xffffffff;
    if (format_length > 2 && format[end - 1] == 'h' &&
        format[end - 2] == 'h')
        return 0xff;
    for (int i = 0;i < NUM_LENGTH_MODIFIER;i++)
        if (format[end] == my_length_modifier[i].length_modifier)
            return my_length_modifier[i].max_size;
    return 0xffffffff;
}

int parse_flag_format(const char *format, int start, format_flag_t *format_flag,
    const printf_format_t my_printf_format_tab[NUM_OF_FORMAT])
{
    int end;
    for (end = start;in_format(format[end + 1],
        my_printf_format_tab) != 1;end++);
    format_flag->width = 0;
    format_flag->precision = get_precision(format, start, end);
    format_flag->length_modifier = get_length_modifier(format, start, end);
    return end;
}

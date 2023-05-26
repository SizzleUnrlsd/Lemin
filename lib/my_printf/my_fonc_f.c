/*
** EPITECH PROJECT, 2022
** B-CPE-101-RUN-1-1-myprintf-kovalen-dimitri.ramaretty
** File description:
** my_fonc_float
*/

#include <stdarg.h>
#include "my_printf.h"

int get_zero(double my_nb)
{
    int zero = 0;
    int my_count_char = 0;
    while (my_nb < 1) {
        zero++;
        my_nb *= 10;
    }
    zero--;
    for (int i = 0;i < zero;i++)
        my_count_char += my_putchar('0');
    return zero;
}

int my_fonc_f(va_list *my_float, format_flag_t *format_flag)
{
    int my_count_char = 0;
    float my_nb = (float)va_arg(*my_float, double);
    if (my_nb < 0) {
        my_count_char += my_putchar('-');
        my_nb = -my_nb;
    }
    long long entier = (long long)my_nb;
    my_nb -= entier;
    my_count_char += my_put_nbr(entier, format_flag->length_modifier);
    my_count_char += my_putchar('.');
    int zero = get_zero(my_nb);
    my_count_char += zero;
    format_flag->precision -= zero;
    my_nb *= my_compute_power_rec(10, format_flag->precision);
    long long decimal = (long long)my_nb;
    my_count_char += my_put_nbr(decimal, format_flag->length_modifier);
    return my_count_char;
}

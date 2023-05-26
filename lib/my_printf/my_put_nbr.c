/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "my_printf.h"

int my_put_nbr(long long nb, unsigned long long length_modifier)
{
    long long max = 1;
    int count = 0;

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    nb &= length_modifier;
    while (nb / max >= 10) {
        max *= 10;
    }
    while (max != 0) {
        count += my_putchar((nb / max + 48));
        nb %= max;
        max /= 10;
    }
    return count;
}

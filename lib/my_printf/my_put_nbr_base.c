/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_put_nbr_base
*/

#include "my_printf.h"
#include <stdlib.h>

int my_strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int put_negative_nbr(long long n, char *base, unsigned long long max)
{
    int count = 0, base_len = my_strlen(base), index = 0;
    long long temp;
    long long m = (max + n) + 1;
    temp = m;
    while (m > 0) {
        index = m % base_len;
        m = (int)(m / base_len);
        count++;
    }
    m = temp;
    char *str = malloc(count);
    for (int i = count - 1;i > -1;i--) {
        index = m % base_len;
        m = (int)(m / base_len);
        str[i] = base[index];
    }
    my_putstr(str);
    free(str);
    return count;
}

int count_num(long long n, int base_len)
{
    int count = 0;
    while (n > 0) {
        n = (int)(n / base_len);
        count++;
    }
    return count;
}

int my_put_nbr_base(long long n, char *base, unsigned long long max)
{
    int count = 0, base_len = my_strlen(base), index = 0;
    n &= max;
    long long temp = n;
    if (n == 0)
        return my_putchar('0');
    if (n < 0)
        return put_negative_nbr(n, base, max);
    count = count_num(n, base_len);
    n = temp;
    char *str = malloc(count + 1);
    str[count] = '\0';
    for (int i = count - 1;i > -1;i--) {
        index = n % base_len;
        n = (int)(n / base_len);
        str[i] = base[index];
    }
    my_putstr(str);
    free(str);
    return count;
}

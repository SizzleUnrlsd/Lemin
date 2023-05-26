/*
** EPITECH PROJECT, 2022
** B-CPE-101-RUN-1-1-myprintf-kovalen-dimitri.ramaretty
** File description:
** my_fonc_s
*/

#include <stdarg.h>
#include "my_printf.h"
#include <stdio.h>

int my_fonc_s_max(va_list *param_list, format_flag_t *format_flag)
{
    char *str = va_arg(*param_list, char*);
    int count = 0;

    for (int cpt = 0; str[cpt] != '\0'; cpt++) {
        if (str[cpt] >= 32 && str[cpt] <= 126) {
            count += my_putchar(str[cpt]);
        } else {
            count += my_putstr("\\0");
            count += my_put_nbr_base((long long)str[cpt], "01234567",
                format_flag->length_modifier);
        }
    }
    return count;
}

/*
** EPITECH PROJECT, 2022
** B-CPE-101-RUN-1-1-myprintf-kovalen-dimitri.ramaretty
** File description:
** my_fonc_p
*/

#include <stdarg.h>
#include "my_printf.h"
#include <stdlib.h>

int my_fonc_p(va_list *param_list, format_flag_t *format_flag)
{
    int count_char = 0;
    unsigned long long num = (unsigned long long)va_arg(*param_list, void*);
    count_char += my_putstr("0x");
    count_char += print_width_space(format_flag->width);
    int index = 0, base_len = 16;
    char base[16] = "0123456789abcdef";
    int count = count_num(num, base_len);
    char *str = malloc(count + 1);
    str[count] = '\0';
    for (int i = count - 1;i > -1;i--) {
        index = num % base_len;
        num = (unsigned long long)(num / base_len);
        str[i] = base[index];
    }
    my_putstr(str);
    free(str);
    return count_char;
}

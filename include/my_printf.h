/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday08-clement-antoine.xavier
** File description:
** my.h
*/

#ifndef _MY_PRINTF_H_
    #define _MY_PRINTF_H_

    #include <stdarg.h>

int my_put_nbr(long long nb, unsigned long long length_modifier);
int my_putchar(char c);
int my_putstr(char const *str);
int my_printf(const char *format, ...);

typedef struct {
    char *flag;
    unsigned long long length_modifier;
    int len_last;
    int width;
    int precision;
    char padded[4];
} format_flag_t;

typedef struct {
    unsigned long long max_size;
    char length_modifier;
    char padded[7];
} printf_length_modifier_t;

typedef struct {
    int(*print_format)(va_list *param_list, format_flag_t *format_flag);
    char format;
    char padded[7];
} printf_format_t;

    #define NUM_OF_FORMAT 14
    #define NUM_LENGTH_MODIFIER 3

int my_fonc_i(va_list *param_list, format_flag_t *format_flag);
int my_fonc_s(va_list *param_list, format_flag_t *format_flag);
int my_fonc_c(va_list *param_list, format_flag_t *format_flag);
int my_put_nbr_base(long long n, char *base, unsigned long long max);
int my_fonc_hexamini(va_list *param_list, format_flag_t *format_flag);
int my_fonc_hexa(va_list *param_list, format_flag_t *format_flag);
int my_fonc_octal(va_list *param_list, format_flag_t *format_flag);
int my_fonc_bin(va_list *param_list, format_flag_t *format_flag);
int my_fonc_u(va_list *param_list, format_flag_t *format_flag);
void check_is_neg(const char * str, int i, int * is_neg);
void check_stop_while(const char *str, int i, int *stop_while);
void is_number(const char *str, int i, long * number, int *stop_while);
long long my_getnbr(const char * str);
int my_strlen(char *str);
int in_format(char c,
    const printf_format_t my_printf_format_tab[NUM_OF_FORMAT]);
int parse_flag_format(const char *format, int start, format_flag_t *format_flag,
    const printf_format_t my_printf_format_tab[NUM_OF_FORMAT]);
int is_numeric(char c);
int print_width_space(int space);
void redirect_all_std(void);
int my_compute_power_rec(int nb, int p);
int my_fonc_f(va_list *my_float, format_flag_t *format_flag);
int my_fonc_s_max(va_list *param_list, format_flag_t *format_flag);
int my_fonc_p(va_list *param_list, format_flag_t *format_flag);
int my_fonc_n(va_list *param_list, format_flag_t *format_flag);
int my_fonc_percent(va_list *param_list, format_flag_t *format_flag);
int count_num(long long n, int base_len);

#endif

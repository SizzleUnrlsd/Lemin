/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday08-clement-antoine.xavier
** File description:
** my.h
*/

#ifndef _MY_H_
    #define _MY_H_

    #include <stdlib.h>

char *concat_params(int argc, char **argv);
int error_case(char *str);

int my_compute_power_rec(int nb, int power);
int power_rec_func(int nb, int p, int result);

int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);

int m_getnbr(char const *str);
void check_is_neg(const char * str, int i, int * is_neg);
void check_stop_while(const char *str, int i, int *stop_while);
void is_number(const char *str, int i, long * number, int *stop_while);

int my_is_prime(int nb);

int my_isneg(int nb);

int m_put_nbr(int nb);

void m_putchar(char c);

int m_putstr(char const *str);

char *my_revstr(char *str);

int my_show_word_array(char **tab);

void my_sort_int_array(int *tab, int size);
void check_number(int * array, int j);
void gen_j(int * array, int size);

int my_str_isalpha(char const *str);
int check_char(char c);

int my_str_isnum(char const *str);
int check_digit(char c);

int my_str_islower(char const *str);
int check_lower(char c);

int my_str_isprintable(char const *str);
int check_print(char c);

int my_str_isupper(char const *str);
int check_upper(char c);

char **my_str_to_word_array(const char *str);
int is_alphanumeric(char c);
int count_word(const char *str, int str_len);
int is_start_or_stop_word(const char *str,
    int i, int str_len, int start_or_stop);
int is_start_or_stop_word_special_case(const char *str,
    int i, int start_or_stop);
char *copy_word(const char *str, int word_start, int word_stop);
size_t word_array_size(char **array);

char *my_strcapitalize(char *str);
void change_capchar(char * str, int i);

char *my_strcat(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);
int strcmp_compare(char c1, char c2);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(const char *str);

int m_strlen(char const *str);

char *my_strlowcase(char *str);
void change_lowchar(char * str, int i);

char *my_strncat(char *dest, char const *src, int nb);

int my_strncmp(char const *s1, char const *s2, int n);
int strncmp_compare(char c1, char c2);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strstr(char *str, char const *to_find);
int strstr_compare(char *str, char const *to_find, int to_find_size, int start);
int check_start(char *str, char const *to_find, int to_find_size, int i);

char *my_strupcase(char *str);
void change_upchar(char *str, int i);

void my_swap(int *a, int *b);

void free_array(char **gree);
char **my_str_to_word_array_separator(char *str, char *token);
void **append_array(void *str, void **array, int size);
void print_array(char **array, char c);
int len_array(char **array);
int my_memset_zero(void *buffer, char c, size_t size);

#endif

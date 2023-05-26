/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-rush2-clement-antoine.xavier
** File description:
** rush.h
*/

#ifndef _RUSH_H_
    #define _RUSH_H_

int is_alpha(char c);

int strlen_alpha(char *str);

void print_float(float b);

int count_char(char *str, char to_find);

void print_char(char to_find, int to_find_count, int str_len_alpha);

int handling_error(int argc, char **argv);

#endif

/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** errors_case
*/

#include "lemin.h"
#include "stdio.h"
#include <strings.h>
#include "my.h"

int check_in_str(char *str)
{
    if (my_str_isalpha(str) != 0)
        return 1;
    return 0;
}

int check_args(char *array)
{
    if (check_in_str(array) == 1)
        return 84;
    return 0;
}

int error_case(char *str)
{
    if (check_args(str) == 84)
        return 84;
    return 0;
}

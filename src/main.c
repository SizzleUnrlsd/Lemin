/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** main.c
*/

#include "lemin.h"
#include "str_to_word_array.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    lemin_t *lemin = init_lemin();
    if (lemin == NULL)
        return 84;
    if (move_all_ants(lemin) == 84)
        return 84;
    terminate_lemin(lemin);
    return 0;
}

/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** sort_int_array.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my_printf.h"

#include <stdlib.h>

void swap_distance_pair(distance_pair_t *a, distance_pair_t *b, ant_t *ant)
{
    if (a->distance < b->distance)
        return;
    if (ant->nodes_value[a->index] < ant->nodes_value[b->index])
        return;
    distance_pair_t tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort_distance_pair_array(distance_pair_t *array, int size, ant_t *ant)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            swap_distance_pair(&array[j], &array[j + 1], ant);
        }
    }
}

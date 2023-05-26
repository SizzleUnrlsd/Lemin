/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** my_realloc.c
*/

#include <stdio.h>
#include <stdlib.h>

char *my_realloc_str(char *ptr, size_t size)
{
    char *new_ptr = malloc(size + 1);
    if (new_ptr == NULL)
        return NULL;
    new_ptr[size] = '\0';
    for (size_t i = 0;i < size;i++)
        new_ptr[i] = '\0';
    for (size_t i = 0;i < size && ptr[i] != '\0';i++)
        new_ptr[i] = ptr[i];
    free(ptr);
    return new_ptr;
}

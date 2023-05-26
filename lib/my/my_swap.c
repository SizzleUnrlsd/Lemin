/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday04-clement-antoine.xavier
** File description:
** my_swap.c
*/

void my_swap(int * a, int * b)
{
    int c = *b;
    *b = *a;
    *a = c;
}

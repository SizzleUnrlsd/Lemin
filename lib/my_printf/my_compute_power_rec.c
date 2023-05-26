/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday05-kovalen-dimitri.ramaretty
** File description:
** my_compute_power_rec
*/

#include <unistd.h>

int cond_rec(int nb, int p, int my_result)
{
    if (p == 0)
        return my_result;
    my_result = my_result * nb;
    p--;
    return cond_rec(nb, p, my_result);
}

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p > 12)
        return 0;
    return cond_rec(nb, p, 1);
}

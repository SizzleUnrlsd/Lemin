/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday05-clement-antoine.xavier
** File description:
** my_compute_power_rec.c
*/

int power_rec_func(int nb, int p, int result)
{
    if (p == 0)
        return result;
    result *= nb;
    p--;
    return power_rec_func(nb, p, result);
}

int my_compute_power_rec(int nb , int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    long result = power_rec_func(nb, p, 1);
    if (result > __INT_MAX__)
        return 0;

    return (long)result;
}

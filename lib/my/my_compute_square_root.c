/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday05-clement-antoine.xavier
** File description:
** my_compute_square_root.c
*/

int my_compute_square_root(int nb)
{
    int result = 0;
    for (int i = 0;i < __INT_MAX__;i++) {
        if ((i ^ 2) == nb)
            return i;
    }
    return result;
}

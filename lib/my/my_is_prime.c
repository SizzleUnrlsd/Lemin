/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday05-clement-antoine.xavier
** File description:
** my_is_prime.c
*/

int my_is_prime(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    if (nb == 2) {
        return 1;
    }
    for (int i = 2;i < nb;i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}

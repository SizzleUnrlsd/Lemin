/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** my_find_prime_sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb <= 2) {
        return 2;
    }
    int to_test = nb;
    while (1) {
        if (my_is_prime(to_test) == 1) {
            return to_test;
        } else {
            to_test++;
        }
    }
}

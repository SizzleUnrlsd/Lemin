/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my_put_nbr
*/

void m_putchar(char c);

int m_put_nbr(int nb)
{
    long int max = 1;

    if (nb < 0) {
        nb *= -1;
        m_putchar('-');
    }
    while (nb / max >= 10) {
        max *= 10;
    }
    while (max != 0) {
        m_putchar((nb / max + 48));
        nb %= max;
        max /= 10;
    }
    return 0;
}

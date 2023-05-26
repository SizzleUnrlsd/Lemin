/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday04-clement-antoine.xavier
** File description:
** my_putstr.c
*/

int my_putchar(char c);

int my_putstr(char const * str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}

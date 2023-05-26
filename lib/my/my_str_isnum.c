/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday06-clement-antoine.xavier
** File description:
** my_str_isnum.c
*/

int check_digit(char c)
{
    if ((c >= '0' && c <= '9'))
        return 1;
    return 0;
}

int my_str_isnum(char const *str)
{
    int str_size = 0;
    while (str[str_size] != '\0') {
        str_size++;
    }
    for (int i = 0;i < str_size;i++) {
        if (check_digit(str[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

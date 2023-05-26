/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday06-clement-antoine.xavier
** File description:
** my_str_isupper.c
*/

int check_upper(char c)
{
    if ((c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int my_str_isupper(char const *str)
{
    int str_size = 0;
    while (str[str_size] != '\0') {
        str_size++;
    }
    for (int i = 0;i < str_size;i++) {
        if (check_upper(str[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

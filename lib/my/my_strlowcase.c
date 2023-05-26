/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday06-clement-antoine.xavier
** File description:
** my_strlowcase.c
*/

void change_lowchar(char * str, int i)
{
    if (str[i] >= 'A' && str[i] <= 'Z') {
        str[i] += 32;
    }
}

char *my_strlowcase(char *str)
{
    int str_size = 0;
    while (str[str_size] != '\0')
        str_size++;
    for (int i = 0;i < str_size;i++) {
        change_lowchar(str, i);
    }
    return str;
}

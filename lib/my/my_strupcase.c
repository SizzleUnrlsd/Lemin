/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday06-clement-antoine.xavier
** File description:
** my_strupcase.c
*/

void change_upchar(char * str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z') {
        str[i] -= 32;
    }
}

char *my_strupcase(char *str)
{
    int str_size = 0;
    while (str[str_size] != '\0')
        str_size++;
    for (int i = 0;i < str_size;i++) {
        change_upchar(str, i);
    }
    return str;
}

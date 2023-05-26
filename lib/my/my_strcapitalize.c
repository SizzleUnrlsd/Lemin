/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday06-clement-antoine.xavier
** File description:
** my_strcapitalize.c
*/

char *my_strlowcase(char *str);

void change_capchar(char * str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z'
        && ((str[i - 1] == ' ' || str[i - 1] == '-')
        || str[i - 1] == '+')) {
        str[i] -= 32;
    }
}

char *my_strcapitalize(char *str)
{
    my_strlowcase(str);
    int str_size = 0;
    while (str[str_size] != '\0')
        str_size++;
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    for (int i = 1;i < str_size;i++)
        change_capchar(str, i);
    return str;
}

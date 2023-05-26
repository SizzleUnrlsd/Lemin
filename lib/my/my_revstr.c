/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    int size = 0;
    int j;
    char temp;
    while (str[size] != '\0') {
        size++;
    }
    j = size - 1;
    for (int i = 0;i < size / 2;i++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    return str;
}

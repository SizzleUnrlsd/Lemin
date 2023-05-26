/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** my_strstr
*/

int strstr_compare(char *str, char const *to_find, int to_find_size, int start)
{
    for (int i = 0;i < to_find_size;i++) {
        if (str[start + i] != to_find[i]) {
            return 0;
        }
    }
    return 1;
}

int check_start(char *str, char const *to_find, int to_find_size, int i)
{
    if (str[i] == to_find[0]) {
        return strstr_compare(str, to_find, to_find_size, i);
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int to_find_size = 0;

    while (to_find[to_find_size] != '\0') {
        to_find_size++;
    }
    if (to_find_size == 0)
        return str;
    for (int i = 0;str[i] != '\0';i++) {
        if (check_start(str, to_find, to_find_size, i) == 1) {
            return (char *)str;
        }
    }
    return "";
}

/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** my_strcmp
*/

int strcmp_compare(char c1, char c2)
{
    if (c1 > c2) {
        return 1;
    } else {
        return -1;
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int size1 = 0;
    int size2 = 0;
    while (s1[size1] != '\0')
        size1++;
    while (s2[size2] != '\0')
        size2++;
    if (size1 > size2)
        return 1;
    if (size2 > size1)
        return -1;
    for (int i = 0;i < size1;i++) {
        if (s1[i] != s2[i]) {
            return strcmp_compare(s1[i], s2[i]);
        }
    }
    return 0;
}

/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** my_strncmp
*/

int strncmp_compare(char c1, char c2)
{
    if (c1 > c2) {
        return 1;
    } else {
        return -1;
    }
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0;i < n;i++) {
        if (s1[i] != s2[i]) {
            return strncmp_compare(s1[i], s2[i]);
        }
    }
    return 0;
}

/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** my_strncat
*/

int m_strlen(char const * str);

char *my_strncat(char *dest, char const *src, int n)
{
    int dest_len = m_strlen(dest);
    int i;
    for (i = 0; i < n && src[i] != '\0';i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}

/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday07-clement-antoine.xavier
** File description:
** my_strcat.c
*/

int m_strlen(char const * str);

char *my_strcat(char *dest, char const *src)
{
    int dest_len = m_strlen(dest);
    int src_len = m_strlen(src);

    for (int i = 0;i < src_len;i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + src_len] = '\0';
    return dest;
}

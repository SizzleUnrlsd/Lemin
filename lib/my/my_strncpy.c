/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char * dest, char const *src, int n)
{
    int src_size = 0;
    int i = 0;
    while (src[src_size] != '\0')
        src_size++;

    if (n > src_size) {
        while (i < src_size) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    } else {
        while (i < n) {
            dest[i] = src[i];
            i++;
        }
    }
    return dest;
}

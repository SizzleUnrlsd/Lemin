/*
** EPITECH PROJECT, 2022
** concat_params
** File description:
** concat_params
*/

#include <stdlib.h>

int m_strlen(char const * str);

char *my_strcat(char *dest, char const *src);

char *concat_params(int argc, char **argv)
{
    char *str;
    int str_len;
    int j;
    for (int i = 0;i < argc;i++) {
        str_len += m_strlen(argv[i]);
    }
    str_len += (argc - 1);
    str = (char *)malloc(str_len);
    for (j = 0;j < argc - 1;j++) {
        my_strcat(str, argv[j]);
        my_strcat(str, "\n");
    }
    my_strcat(str, argv[j]);
    return str;
}

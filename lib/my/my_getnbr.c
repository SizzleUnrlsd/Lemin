/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** my_getnbr
*/

void check_is_neg(const char * str, int i, int * is_neg)
{
    if (str[i] == '-') {
        *is_neg = *is_neg * (-1);
    }
}

void check_stop_while(const char *str, int i, int *stop_while)
{
    if ((str[i + 1] < '0') || (str[i + 1] > '9')) {
        *stop_while = 1;
    }
}

void is_number(const char *str, int i, long * number, int *stop_while)
{
    if (str[i] >= '0' && str[i] <= '9') {
        *number = (*number * 10) + (str[i] - 48);
        check_stop_while(str, i, stop_while);
    }
}

int my_getnbr(const char * str)
{
    int i = 0;
    int stop_while = 0;
    long number = 0;
    int is_neg = 1;
    int have_number = 0;
    while (str[i] != '\0') {
        (str[i] >= '0' && str[i] <= '9' ? have_number = 1 : 0);
        i++;
    }
    if (have_number == 0)
        return 0;
    i = 0;
    while (str[i] != '\0' && stop_while == 0) {
        check_is_neg(str, i, &is_neg);
        is_number(str, i, &number, &stop_while);
        i = i + 1;
    }
    if (number < -2147483648 || number > 2147483647)
        return 0;
    return (long)(number *= is_neg);
}

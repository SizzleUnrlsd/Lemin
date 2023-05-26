/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday04-clement-antoine.xavier
** File description:
** my_sort_int_array.c
*/

void check_number(int * array, int j)
{
    int temp;
    if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
    }
}

void gen_j(int * array, int size)
{
    for (int j = 0;j < (size - 1);j++) {
        check_number(array, j);
    }
}

void my_sort_int_array(int * array , int size)
{
    for (int i = 0;i < size;i++) {
        gen_j(array, size);
    }
}

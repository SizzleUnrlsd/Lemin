/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** buffer.c
*/

#include "lemin.h"
#include "str_to_word_array.h"
#include "my.h"

#include <stdlib.h>


buffer_t *init_buffer(void)
{
    buffer_t *buffer = malloc(sizeof(buffer_t));
    if (buffer == NULL)
        return NULL;
    buffer->size = 0;
    buffer->capacity = BLOCK_SIZE;
    buffer->data = malloc(sizeof(char) * BLOCK_SIZE + 1);
    if (buffer->data == NULL)
        return NULL;
    for (size_t i = 0;i < BLOCK_SIZE + 1;i++)
        buffer->data[i] = '\0';
    return buffer;
}

void terminate_buffer(buffer_t *buffer)
{
    free(buffer->data);
    free(buffer);
}

int append_buffer(buffer_t *buffer, char *str)
{
    size_t str_size = m_strlen(str);
    while (buffer->size + str_size >= buffer->capacity) {
        buffer->capacity += BLOCK_SIZE;
    }
    buffer->data = my_realloc_str(buffer->data, (buffer->capacity + 1));
    if (buffer->data == NULL)
        return 84;
    for (size_t i = 0;i < str_size;i++)
        buffer->data[buffer->size + i] = str[i];
    buffer->size += str_size;
    return 0;
}

int append_char_buffer(buffer_t *buffer, char c)
{
    while (buffer->size + 1 >= buffer->capacity) {
        buffer->capacity += BLOCK_SIZE;
    }
    buffer->data = my_realloc_str(buffer->data, (buffer->capacity + 1));
    if (buffer->data == NULL)
        return 84;
    buffer->data[buffer->size] = c;
    buffer->size += 1;
    return 0;
}

char *get_buffer_data(buffer_t *buffer)
{
    return buffer->data;
}

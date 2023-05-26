/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** bucket
*/
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "bucket.h"

bucket_str_t *bucket_str_init(void)
{
    bucket_str_t *sb = malloc(sizeof(bucket_str_t));
    sb->buffer = (char *)malloc(sizeof(char) * BUCKET_SIZE);
    if (sb->buffer == NULL || sb == NULL) {
        return NULL;
    }
    sb->used = 0;
    sb->size = BUCKET_SIZE;
    return sb;
}

void bucket_str_append(bucket_str_t *sb, char *str)
{
    size_t len = my_strlen(str);

    if (sb->used + len >= sb->size) {
        sb->size *= 2;
        sb->buffer = (char *)re_alloc(sb->buffer, sb->size);
        if (sb->buffer == NULL) {
            return;
        }
    }

    my_memcpy(sb->buffer + sb->used, str, len);
    sb->used += len;
    sb->buffer[sb->used] = '\0';
}

void bucket_str_append_int(bucket_str_t *sb, int value)
{
    char int_buffer[32];
    int32_t pos = 0;
    if (value < 0) {
        bucket_str_append(sb, "-");
        value = -value;
    }

    do {
        int_buffer[pos++] = '0' + (value % 10);
        value /= 10;
    } while (value > 0);

    for (int32_t i = pos - 1; i >= 0; i--) {
        char str[2] = {int_buffer[i], '\0'};
        bucket_str_append(sb, str);
    }
}

void bucket_str_append_formatted(bucket_str_t *sb, char *format, va_list args)
{
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 's': {
                    char *str = va_arg(args, char *);
                    bucket_str_append(sb, str); break;
                }
                case 'd': {
                    int value = va_arg(args, int);
                    bucket_str_append_int(sb, value); break;
                }
                default: break;
            }
        } else {
            char str[2] = {*format, '\0'};
            bucket_str_append(sb, str);
        }
        format++;
    }
}

char *bucket_format(bucket_str_t *sb)
{
    char *str = sb->buffer;
    uint32_t count = 0;
    uint32_t len_str = my_strlen(str);
    char *new_str = malloc(sizeof(char) * len_str);
    if (new_str == NULL)
        return NULL;

    for (uint_fast32_t i = 0; i != len_str; i++) {
        if (str[i] == ' ' && str[i + 1] == '\n') {
            new_str[count] = '\n';
            continue;
        }
        new_str[count] = str[i];
        count++;
    }
    new_str[count] = '\0';
    return new_str;
}

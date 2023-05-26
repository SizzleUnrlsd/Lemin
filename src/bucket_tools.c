/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** destroy_bucket
*/
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "bucket.h"

void bucket_str_appendf(bucket_str_t *sb, char *format, ...)
{
    va_list args;
    va_start(args, format);
    bucket_str_append_formatted(sb, format, args);
    va_end(args);
}

void bucket_str_print(bucket_str_t *sb)
{
    char *new_bucket = bucket_format(sb);
    int len_new_bucket = my_strlen(new_bucket);
    write(1, new_bucket, len_new_bucket);
}

void bucket_str_destroy(bucket_str_t *sb)
{
    free(sb->buffer);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** bucket
*/

#ifndef BUCKET_H_
    #define BUCKET_H_
    #include <string.h>
    #include <stdarg.h>
    #include <stdint.h>

    #define BUCKET_SIZE 1024

    typedef struct bucket_str_s {
        char *buffer;
        size_t used;
        size_t size;
    } bucket_str_t;

    bucket_str_t *bucket_str_init(void);
    char *bucket_format(bucket_str_t *sb);
    void* re_alloc(void* ptr, size_t size);
    void bucket_str_print(bucket_str_t *sb);
    void bucket_str_destroy(bucket_str_t *sb);
    void bucket_str_append(bucket_str_t *sb, char *str);
    void *my_memcpy(void *dest, const void *src, size_t n);
    void bucket_str_append_int(bucket_str_t *sb, int value);
    void bucket_str_appendf(bucket_str_t *sb, char *format, ...);
    void bucket_str_append_formatted(bucket_str_t *sb,
    char *format, va_list args);

#endif /* !BUCKET_H_ */

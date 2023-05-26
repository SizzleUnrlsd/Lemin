/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** lemin.h
*/

#ifndef _LEMIN_H_
    #define _LEMIN_H_

    #include <stdint.h>
    #include "str_to_word_array.h"
    #include "my_macro_abs.h"
    #include "../include/bucket.h"

    #define NOT_LINKED 0
    #define LINKED 1

    #define NORMAL_NODE 0
    #define START_NODE 1
    #define END_NODE 2

    #define CONTINUE 21

    #define BLOCK_SIZE 8


typedef struct distance_pair_s {
    int32_t index;
    int32_t distance;
} distance_pair_t;

char *my_realloc_str(char *ptr, size_t size);

typedef struct buffer_s {
    char *data;
    size_t size;
    size_t capacity;
} buffer_t;

buffer_t *init_buffer(void);
void terminate_buffer(buffer_t *buffer);
int append_buffer(buffer_t *buffer, char *str);
int append_char_buffer(buffer_t *buffer, char c);
char *get_buffer_data(buffer_t *buffer);

typedef struct position_s {
    int32_t x;
    int32_t y;
} position_t;

typedef struct node_s {
    char *id;
    position_t position;
    unsigned char type;
    char padded[7];
} node_t;

node_t *init_node(word_array_t *line, unsigned char type);
void terminate_node(node_t *node);

typedef struct tunnel_s {
    char *id1;
    char *id2;
} tunnel_t;

tunnel_t *init_tunnel(word_array_t *line);
void terminate_tunnel(tunnel_t *tunnel);

typedef struct ant_s {
    int32_t *nodes_value;
    int32_t id;
    int32_t node_index;
    int32_t last_node_index;
    char padded[4];
} ant_t;

ant_t *init_ant(int id, int start_index, int nodes_count);
void terminate_ant(ant_t *ant);

typedef struct graph_node_s {
    long distance_end;
    unsigned char link;
    unsigned char type;
    char padded[6];
} graph_node_t;

typedef struct graph_s {
    size_t size;
    graph_node_t **matrix;
} graph_t;

typedef struct node_index_s {
    int32_t index;
    int32_t distance;
} node_index_t;

graph_t *init_graph(size_t size);
void terminate_graph(graph_t *graph);
void print_graph(graph_t *graph);

typedef struct lemin_s {
    buffer_t *buffer;
    word_array_t *buffer_split;
    word_array_t **lines_split;
    node_t **nodes;
    tunnel_t **tunnels;
    ant_t **ants;
    graph_t *graph;
    char *id_start;
    char *id_end;
    uint_fast32_t ants_count;
    int32_t nodes_count;
    int32_t tunnels_count;
    char padded[16];
} lemin_t;

lemin_t *init_lemin(void);
void terminate_lemin(lemin_t *lemin);
int read_stdin(lemin_t *lemin);
int split_buffer(lemin_t *lemin);
int count_lemin_objects(lemin_t *lemin);

int count_ants(lemin_t *lemin);
int count_nodes(lemin_t *lemin);
int count_tunnels(lemin_t *lemin);

int init_nodes(lemin_t *lemin);
int init_tunnels(lemin_t *lemin);
int init_ants(lemin_t *lemin);
int fill_graph(lemin_t *lemin);

int get_index_node_by_id(lemin_t *lemin, char *id);
position_t get_pos_by_index(lemin_t *lemin, int index);

int my_atoi(char *str);
int calcul_distance(position_t pos1, position_t pos2);

int move_ant(lemin_t *lemin, ant_t *ant, bucket_str_t *sb);
int move_all_ants(lemin_t *lemin);
void print_ants_node(lemin_t *lemin);
int all_ants_are_arrived(lemin_t *lemin);

void sort_distance_pair_array(distance_pair_t *array, int size, ant_t *ant);
int print_lines(lemin_t *lemin);
char *clean_buffer(char *str);

void* re_alloc(void* ptr, size_t size);

#endif // _LEMIN_H_

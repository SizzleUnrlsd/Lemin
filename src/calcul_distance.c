/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** calcul_distance.c
*/

#include "lemin.h"

int calcul_distance(position_t pos1, position_t pos2)
{
    int x = pos1.x - pos2.x;
    int y = pos1.y - pos2.y;
    int distance = x + y;
    if (distance < 0)
        distance = distance * -1;
    return distance;
}

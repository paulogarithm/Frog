/*
** EPITECH PROJECT, 2023
** frog_code
** File description:
** addin
*/

#include <stdlib.h>

#include "../include/frog.h"

number_t **addin_number(number_t **list, number_t *button)
{
    number_t **new_list;
    int size = 0;
    int n = 0;

    while (list[size] != NULL)
        ++size;
    new_list = malloc(sizeof(number_t) * (size + 2));
    while (list[n] != NULL) {
        new_list[n] = list[n];
        n += 1;
    }
    new_list[n] = button;
    new_list[n + 1] = NULL;
    return new_list;
}

string_t **addin_string(string_t **list, string_t *button)
{
    string_t **new_list;
    int size = 0;
    int n = 0;

    while (list[size] != NULL)
        ++size;
    new_list = malloc(sizeof(string_t) * (size + 2));
    while (list[n] != NULL) {
        new_list[n] = list[n];
        n += 1;
    }
    new_list[n] = button;
    new_list[n + 1] = NULL;
    return new_list;
}

boolean_t **addin_boolean(boolean_t **list, boolean_t *button)
{
    boolean_t **new_list;
    int size = 0;
    int n = 0;

    while (list[size] != NULL)
        ++size;
    new_list = malloc(sizeof(boolean_t) * (size + 2));
    while (list[n] != NULL) {
        new_list[n] = list[n];
        n += 1;
    }
    new_list[n] = button;
    new_list[n + 1] = NULL;
    return new_list;
}

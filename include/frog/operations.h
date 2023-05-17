/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** operations
*/

#ifndef OPERATIONS_H_
    #define OPERATIONS_H_

    #include <stdbool.h>
    #include <stddef.h>
    #include "frog/frog.h"

void operation_plus(frog_t *g, char ***array, size_t n);
void operation_minus(frog_t *g, char ***array, size_t n);

char *remove_string(const char *str1, const char *str2);
bool my_atob(const char *str);
char *my_btoa(const bool b);

#endif /* !OPERATIONS_H_ */

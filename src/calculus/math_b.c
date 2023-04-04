/*
** EPITECH PROJECT, 2023
** line_calculus
** File description:
** math_a
*/

#include <stdlib.h>

#include "polib.h"
#include "frog.h"

double get_numbervalue(char *str, frog_t *frog);

static char *process_calculus_b(char **array, int n, frog_t *frog)
{
    double a = get_numbervalue(array[n - 1], frog);
    double b = get_numbervalue(array[n + 1], frog);

    switch (array[n][0]) {
        case '+':
        return my_double_str(a + b);
        case '-':
        return my_double_str(a - b);

        default:
        break;
    }
    return NULL;
}

char **cmon_do_math_b(char **array, frog_t *frog)
{
    for (int n = 0; array[n] != NULL; n ++) {
        if (n % 2 == 0)
            continue;
        char *process = process_calculus_b(array, n, frog);
        if (!process) {
            n += 1;
            continue;
        }
        free(array[n - 1]);
        array[n - 1] = process;
        crush_array(&array, n);
        crush_array(&array, n);
        n = n - 1;
    }
    return array;
}

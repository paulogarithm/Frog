/*
** EPITECH PROJECT, 2023
** line_calculus
** File description:
** math_a
*/

#include <stdlib.h>

#include "polib.h"
#include "frog.h"

int get_numbervalue(char *str, frog_t *frog);

static char *process_calculus_a(char **array, int n, frog_t *frog)
{
    if (array[n + 1] == NULL)
        return NULL;
    int a = get_numbervalue(array[n - 1], frog);
    int b = get_numbervalue(array[n + 1], frog);

    switch (array[n][0]) {
        case '*':
        return my_nb_str(a * b);
        case '/':
        return my_nb_str((int) a / b);
        case '%':
        return my_nb_str(a % b);
        default:
        break;
    }
    return NULL;
}

char **cmon_do_math_a(char **array, frog_t *frog)
{
    for (int n = 0; array[n] != NULL; n ++) {
        if (n % 2 == 0)
            continue;
        char *process = process_calculus_a(array, n, frog);
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

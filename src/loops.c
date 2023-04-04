/*
** EPITECH PROJECT, 2023
** Frog
** File description:
** loops
*/

#include <stdlib.h>

#include "polib.h"
#include "frog.h"

int find_first_end(char **array, int begin);
char *calculus(char *line_const, frog_t *frog);
void read_it(frog_t *frog, int beg);

void native_while(frog_t *frog, char **array_template, int *n)
{
    char **array = my_newarray(array_template);
    char *cal = NULL;
    char *join;

    crush_array(&array, my_arraylen(array) - 1);
    crush_array(&array, 0);
    join = my_strjoin(array, " ");
    while (1) {
        if (cal != NULL)
            free(cal);
        cal = calculus(join, frog);
        if (my_compstr(cal, "true") || my_str_double(cal))
            read_it(frog, *n + 1);
        else
            break;
    }
    *n = find_first_end(frog->array, *n);
    free_ception(array);
    free(cal);
    free(join);
}

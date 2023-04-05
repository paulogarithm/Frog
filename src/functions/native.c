/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** native
*/

#include <stdlib.h>

#include "polib.h"
#include "frog.h"

void native_print(frog_t *frog, char **array);
void native_maths(frog_t *frog, char *function, char **array);

int native_function(frog_t *frog, char *name, char **args)
{
    char **array = my_strsplit(name, ".");
    int ret = 0;

    if (my_compstr(array[0], "print")) {
        native_print(frog, args);
        ret = 1;
    } else if (my_compstr(array[0], "math")) {
        native_maths(frog, array[1], args);
        ret = 1;
    }
    free_ception(array);
    return ret;
}

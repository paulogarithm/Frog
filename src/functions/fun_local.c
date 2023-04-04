/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** fun_local
*/

#include <unistd.h>

#include "frog.h"
#include "polib.h"

void read_it(frog_t *frog, int beg);
int find_function(char **array, char *name);

void local_function(frog_t *frog, char *name)
{
    int n = 0;

    if (name == NULL)
        return;
    n = find_function(frog->array, name);
    if (n < 0)
        return;
    frog->current_function = name;
    read_it(frog, n);
}

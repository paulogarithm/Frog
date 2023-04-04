/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** native
*/

#include "polib.h"
#include "frog.h"

void native_print(frog_t *frog, char **array);

int native_function(frog_t *frog, char *name, char **args)
{
    if (my_compstr(name, "print")) {
        native_print(frog, args);
        return 1;
    }
    return 0;
}

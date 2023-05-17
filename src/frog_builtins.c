/*
** Paul Parisot PROJECT, 2023
** sh_final
** File description:
** frog_builtins
*/

#include <stdbool.h>
#include <iso646.h>
#include "my/string.h"
#include "my/stdio.h"

#include "frog/functions.h"

bool frog_builtins_exec(frog_t *frog, char **keyval)
{
    (void)frog;
    (void)keyval;
    return true;
}

static char *realval(frog_t *frog, char *str)
{
    return frog_arithmetics(frog, str);
}

bool frog_builtins_print(frog_t *frog, char **keyval)
{
    char **to_print = my_strsplit(keyval[1], ",");
    char *val = NULL;

    if (to_print == NULL)
        return false;
    for (size_t n = 0; to_print[n] != NULL; ++n) {
        val = realval(frog, to_print[n]);
        my_printf("%s", ((n > 0) ? ", " : ""));
        my_printf("%s", ((val != NULL) ? val : "nil"));
    }
    my_printf("\n");
    return true;
}

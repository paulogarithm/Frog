/*
** Paul Parisot PROJECT, 2023
** sh_final
** File description:
** frog
*/

#include <stdbool.h>
#include <iso646.h>
#include <malloc.h>

#include "my/string.h"
#include "my/array.h"

#include "frog/functions.h"

static frog_t *frog_setup(char **words)
{
    frog_t *frog = malloc(sizeof(frog_t));

    if (frog == NULL)
        return NULL;
    frog->variables = malloc(sizeof(var_t *));
    frog->variables[0] = NULL;
    frog->words = words;
    return frog;
}

bool frog(char *line)
{
    char **word_array = NULL;
    frog_t *frog = NULL;

    if (line == NULL)
        return false;
    word_array = my_array_str(line);
    if (word_array == NULL)
        return false;
    frog = frog_setup(word_array);
    if (frog == NULL)
        return false;
    return frog_process(frog);
}

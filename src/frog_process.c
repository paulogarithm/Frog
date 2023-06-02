/*
** Paul Parisot PROJECT, 2023
** sh_final
** File description:
** process_frog
*/

#include <iso646.h>
#include <stdbool.h>
#include <malloc.h>
#include "my/string.h"
#include "my/stdio.h"
#include "my/array.h"

#include "frog/functions.h"

static const tabfrog_actions_t TAB_GROF[] = {
    {"exp", frog_create_var},
    {"foreach", frog_foreach_loop},
    {NULL, NULL}
};

static void variable_show(frog_t *frog)
{
    for (size_t n = 0; frog->variables[n] != NULL; ++n) {
        var_t *var = frog->variables[n];
        my_printf("[%d] %s = %s\n", var->type, var->name, var->value);
    }
}

bool frog_process(frog_t *frog)
{
    char *word = NULL;
    bool ret = true;
    size_t len = my_arraylen((const char **)frog->words);
    short pos = 0;

    for (size_t n = 0; n < len and ret; ++n) {
        word = frog->words[n];
        pos = frog_tabpos_actions(word, TAB_GROF);
        if (frog_isfunction(frog, &n))
            continue;
        if (pos < 0)
            return false;
        ret = ((not ret) ? ret : TAB_GROF[pos].function(frog, &n));
    }
    (void)variable_show;
    return ret;
}

bool frog_simulate(frog_t *frog, char *str)
{
    char **old_words = my_newarray((const char **)frog->words);
    char **new_words = my_array_str(str);

    if (new_words == NULL)
        return false;
    free(frog->words);
    frog->words = new_words;
    if (not frog_process(frog))
        return false;
    free(frog->words);
    frog->words = old_words;
    return true;
}

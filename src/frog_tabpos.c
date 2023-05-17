/*
** Paul Parisot PROJECT, 2023
** sh_final
** File description:
** frog_tabpos
*/

#include <stddef.h>
#include "my/string.h"

#include "frog/frog.h"

short frog_tabpos_actions(const char *str, const tabfrog_actions_t *TAB_GROF)
{
    for (unsigned short n = 0; TAB_GROF[n].flag != NULL; ++n)
        if (my_strcmp(TAB_GROF[n].flag, str))
            return n;
    return -1;
}

short frog_tabpos_builtins(const char *str, const tabfrog_builtins_t *TAB_GROF)
{
    for (unsigned short n = 0; TAB_GROF[n].flag != NULL; ++n)
        if (my_strcmp(TAB_GROF[n].flag, str))
            return n;
    return -1;
}

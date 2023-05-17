/*
** Paul Parisot PROJECT, 2023
** Frog
** File description:
** keyvalue
*/

#include <malloc.h>
#include <stdbool.h>
#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"

char **keyvalue_parser(char *str)
{
    char **split = my_strsplit(str, "=");
    char *tmp = NULL;

    if (split == NULL || my_arraylen((const char **)split) != 2)
        return NULL;
    tmp = my_strnorm(split[0]);
    free(split[0]);
    split[0] = my_newstr(tmp);
    free(tmp);
    tmp = my_strnorm(split[1]);
    free(split[1]);
    split[1] = my_newstr(tmp);
    free(tmp);
    return split;
}

bool my_startswith(const char *str, const char *start)
{
    const size_t startlen = my_strlen(start);

    if (startlen > my_strlen(str))
        return false;
    for (size_t n = 0; n < startlen; n ++)
        if (str[n] != start[n])
            return false;
    return true;
}

char *my_newscanf(const char *show)
{
    long unsigned int size = 0;
    char *command = NULL;
    char last = '\0';
    int count = 0;
    char *ret = NULL;

    my_printf(show);
    if (getline(&command, &size, stdin) < 0)
        return NULL;
    count = my_strlen(command) - 1;
    last = command[count];
    ret = ((last == '\n') ? my_strcut(command, 0, count) : my_newstr(command));
    free(command);
    return ret;
}

/*
** Paul Parisot PROJECT, 2023
** Frog
** File description:
** main
*/

#include <iso646.h>
#include <stdio.h>
#include <malloc.h>
#include "my/stdio.h"

#include "frog/functions.h"

static int is_file(char const *av[])
{
    char *parsing = my_parsing(av[1]);
    int ret = 0;

    if (parsing == NULL)
        return 84;
    ret = (frog(parsing) ? 0 : 84);
    free(parsing);
    return ret;
}

int main(int ac, char const *av[])
{
    char *str = NULL;
    unsigned short res = 0;

    if (ac == 2)
        return is_file(av);
    if (ac > 2)
        return 84;
    while (true) {
        str = my_newscanf("> ");
        if (str == NULL)
            break;
        res = (frog(str) ? 0 : 84);
        free(str);
    }
    return res;
}

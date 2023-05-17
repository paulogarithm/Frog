/*
** Paul Parisot PROJECT, 2023
** rpg-bg
** File description:
** string
*/

#include <stdarg.h>
#include <stdlib.h>


void my_arraysuperpop(char ***array, const int pos, const int num);

void remove_extension(char **file)
{
    char **array = my_strsplit(*file, "./");
    char *ret = NULL;

    if (array == NULL || my_arraylen(array) < 2)
        return;
    ret = my_newstr(array[my_arraylen(array) - 2]);
    my_arrayfree(array);
    if (ret == NULL)
        return;
    free(*file);
    *file = ret;
}

char **keyvalue_parser(char *str)
{
    char **split = my_strsplit(str, "=");
    char *tmp = NULL;

    if (split == NULL || my_arraylen(split) != 2)
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

char *get_lastword(char *str, char *sep)
{
    char **array = my_strsplit(str, sep);
    char *ret = NULL;

    if (array == NULL || array[0] == NULL) {
        my_arrayfree(array);
        return str;
    }
    my_arraysuperpop(&array, 0, my_arraylen(array) - 1);
    ret = array[0];
    free(array);
    return ret;
}

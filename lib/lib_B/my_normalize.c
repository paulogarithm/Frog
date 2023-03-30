/*
** EPITECH PROJECT, 2023
** parcing_map_csfml
** File description:
** my_normalize
*/

#include <unistd.h>

char **my_str_array(char *str);
char *my_strjoin(char **array, char *join);
void free_ception(char **array);

char *my_normalize(char *str)
{
    char **array = my_str_array(str);
    char *new;

    if (array == NULL)
        return str;
    new = my_strjoin(array, " ");
    if (new == NULL) {
        free_ception(array);
        return str;
    }

    free_ception(array);
    return new;
}

/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_str_float
*/

#include <stdlib.h>

char *my_newstr(char *str);
char *my_nb_str(int n);
void my_addstr(char **str, char *add);

char *my_double_str(double num)
{
    char *str = my_newstr("");
    int pos = num >= 0;
    int a = (int) num;
    int b = (int) ((num - a) * 10000);
    char *a_str = my_nb_str(a);
    char *b_str = my_nb_str(b);

    my_addstr(&str, pos ? "" : "-");
    my_addstr(&str, a_str);
    my_addstr(&str, ".");
    my_addstr(&str, b_str);
    free(a_str);
    free(b_str);
    return str;
}

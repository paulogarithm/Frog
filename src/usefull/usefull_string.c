/*
** Paul PARISOT, 2023
** Frog
** File description:
** usefull_string
*/

char *my_cutstr(char *str, int a, int b);
int my_countstr(char *str);
int my_compstr(char *a, char *b);

char *unstringify(char *str)
{
    int len_str = my_countstr(str);

    if (str[0] != '"' || str[len_str - 1] != '"')
        return str;
    str = my_cutstr(str, 1, len_str - 1);
    return str;
}

int finish_with(char *str, char *end)
{
    int c_str = my_countstr(str);
    int c_end = my_countstr(end);

    if (c_str < c_end)
        return 0;
    if (my_compstr(my_cutstr(str, c_str - c_end, c_str), end))
        return 1;
    return 0;
}

int beggins_with(char *str, char *beg)
{
    int len_str = my_countstr(str);
    int len_beg = my_countstr(beg);
    char *cut = my_cutstr(str, 0, len_beg);

    if (len_str < len_beg)
        return 0;
    if (my_compstr(cut, beg))
        return 1;
    return 0;
}

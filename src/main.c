/*
** Paul PARISOT, 2022
** my_lib
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>

#include "../include/color.h"

char **my_array_parcing(char *file_path);
char *my_parcing(char *path);

int my_compstr(char *a, char *b);
int my_countstr(char *str);
char *my_cutstr(char *str, int a, int b);

char *get_type(char *val);
void read_file(char **parcing);

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

int display_help(void)
{
    char *parcing = my_parcing("assets/frog.txt");

    printf("%s%s%s\n",
    COL[Green], parcing != NULL ? parcing : "", COL[Reset]);
    printf("[%s%sFrog%s 1.0] Copyright (C) 2023 by paulogarithm.\n\n",
    COL[Green], COL[Bold], COL[Reset]);
    printf("Using gcc (GCC) 12.2.1 20221121 (Red Hat 12.2.1-4), on linux.\n");
    printf("This program comes with ABSOLUTELY NO WARRANTY. For details,\n");
    printf("check the website https://www.gnu.org/licenses.\n");
    printf("FrogCode is an open-source programming language, developped\n");
    printf("in C, inspired by Lua.\n\n");
    printf("Usage\n");
    printf("\tfrog [option] files...\n\n");

    return 0;
}

int main(int ac, char **av)
{
    char **parcing;

    if (ac == 2 && my_compstr(av[1], "-h"))
        return display_help();
    if (ac != 2)
        return 69 + 0 * printf("Frog::%s[E]%s missing input files.\n",
        COL[Red], COL[Reset]);

    parcing = my_array_parcing(av[1]);
    if (parcing == NULL)
        return 69 + 0 * printf("Frog::%s[E]%s error while reading file.\n",
        COL[Red], COL[Reset]);

    read_file(parcing);
    return 0;
}

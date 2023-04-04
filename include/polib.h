/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** polib v 1.3
*/

#ifndef POLIB_H_
    #define POLIB_H_

    #undef NULL
    #define NULL ((void *)0)

// LIB A

/* Compare two strings, return 1 if success, else 0. */
int my_compstr(char *a, char *b);
int my_strlen(char *str);
int my_findchar(char *str, char c);
int my_findstr(char *str, char *find);
int my_isalphanum(char *str);
int my_isnum(char *str);
int my_abs(int a);
int my_pow(int a, unsigned int b);
int my_nblen(int nb);
int my_putchar(char c);
int my_putstr(char *str);
int my_str_nb(char *str);
int my_isdouble(char *str);
int my_countchar(char *str, char c);
void my_replacechar(char *str, char obj, char rep);
void my_revstr(char *str);
void my_strcpy(char *dest, char *src);
void my_strup(char *str);
void my_strlow(char *str);
void my_cleanchar(char *str, char c);
double my_str_double(char *str);
void *my_puterr(char *str);

//-- LIB B --//

/* Gives the len of an [array] of [string]. */
int my_arraylen(char **array);

/* Concaten 2 strings, adds 'add' at the end of [&dest]. */
void my_addstr(char **dest, char *add);
/* Adds the character 'add' at the end of [&str]. */
void my_addchar(char **str, char add);
/* Free the [array] of [string] with everything in it. */
void free_ception(char **array);
/* Shows the [array] of [string]. */
void my_putarray(char **array);
/* Adds a [string] in an [&array]. */
void addin_array(char ***array, char *str);
/* Removes the 'index' of the [&array] and moves everything to the right. */
void crush_array(char ***array, int index);

/* Cuts the 'string' from 'beg' to 'end' and returns the [result]. */
char *my_cutstr(char *str, int beg, int end);
/* Convert the 'number' into a [string]. */
char *my_nb_str(int nb);
/* Create a new [string] from the 'text'. */
char *my_newstr(char *text);
/* Joins an [array] of [strings] to create a [string]. */
char *my_strjoin(char **array, char *join);
/* Return a [string] with nice little formatting */
char *my_disparray(char **array);
/* Float to number */
char *my_double_str(double d);
/* Normalize a string */
char *my_normalize(char *str);

/* Converts a string to an [array] at each characters from 'correct'. */
char **my_strsplit(char *str, char *correct);
/* Converts a string to an [array] of [words]. */
char **my_str_array(char *str);
/* Duplicate the [array] to make a [new] one. */
char **my_newarray(char **array);

// LIB C
char *my_parsing(char *path);
char **my_array_parsing(char *path);
int my_printf(const char *str, ...);

#endif /* !POLIB_H_ */

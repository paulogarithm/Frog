/*
** Paul PARISOT, 2023
** frog_code
** File description:
** frog
*/

#ifndef FROG_H_
#define FROG_H_

typedef struct
{
    char *name;
    char *type;

    int number;
    char *string;
    int boolean;
} variable_t;

typedef struct
{
    variable_t **variables;
} frog_t;

#endif /* !FROG_H_ */

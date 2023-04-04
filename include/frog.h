/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** frog
*/

#ifndef FROG_H_
    #define FROG_H_

enum type {
    null = 0,
    number,
    boolean,
    string,
};

typedef struct {
    int type;
    char *name;

    double number;
    int boolean;
    char *string;

} variable_t;


typedef struct {
    variable_t **varibales;
    char *null_ptr;
    char **array;
} frog_t;

#endif /* !FROG_H_ */

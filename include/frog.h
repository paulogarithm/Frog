/*
** EPITECH PROJECT, 2023
** frog_code
** File description:
** frog
*/

#ifndef FROG_H_
    #define FROG_H_

typedef struct {
    char *name;
    float number_f;
    int number_n;
} number_t;

typedef struct {
    char *name;
    char *string;
} string_t;

typedef struct {
    char *name;
    int boolean;
} boolean_t;

typedef struct {
    number_t **numbers;
    string_t **strings;
    boolean_t **booleans;
} frog_t;

#endif /* !FROG_H_ */

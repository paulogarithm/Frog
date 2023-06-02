/*
** Paul Parisot PROJECT, 2023
** sh_final
** File description:
** frog
*/

#ifndef GROF_H_
    #define GROF_H_

    #include <stddef.h>
    #include <stdbool.h>

enum mode_e {
    G_NIL = 0,
    G_NUMBER,
    G_BOOLEAN,
    G_STRING,
    G_TABLE,
};

typedef struct s_var {
    char *name;
    unsigned short type;
    char *value;
} var_t;

typedef struct s_frog {
    var_t **variables;
    char **words;
} frog_t;

typedef struct s_tabfrog_actions {
    char *flag;
    bool (*function)(frog_t *, unsigned long *);
} tabfrog_actions_t;

typedef struct s_tabfrog_builtins {
    char *flag;
    bool (*function)(frog_t *, char **);
} tabfrog_builtins_t;

typedef struct s_tabfrog_operations {
    char *operation;
    void (*function)(frog_t *, char ***, size_t);
} tabfrog_operations_t;

#endif /* !GROF_H_ */

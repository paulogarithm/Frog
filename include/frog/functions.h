/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** fun_frog
*/

#ifndef FUN_GROF_H_
    #define FUN_GROF_H_

    #include "./frog.h"

unsigned short frog_get_type(frog_t *frog, const char *str);
bool frog_process(frog_t *frog);
char *frog_arithmetics(frog_t *frog, char *str);
bool frog_isfunction(frog_t *frog, size_t *n);

bool frog_create_var(frog_t *frog, unsigned long *n);
bool frog_for_loop(frog_t *frog, size_t *n);

short frog_tabpos_actions
(const char *str, const tabfrog_actions_t *TAB_GROF);
short frog_tabpos_builtins
(const char *str, const tabfrog_builtins_t *TAB_GROF);

bool frog_replacevar(frog_t *frog, char ***array);
char *frog_get_varvalue(frog_t *frog, const char *varname);

bool frog_builtins_print(frog_t *frog, char **keyval);
bool frog_builtins_exec(frog_t *frog, char **keyval);

bool frog_append_var(frog_t *frog, var_t *var);
bool frog_autovar(frog_t *frog, char *keyval_str);

bool frog_simulate(frog_t *frog, char *str);
bool frog(char *line);

char **keyvalue_parser(char *str);
bool my_startswith(const char *str, const char *start);
char *my_newscanf(const char *toshow);

#endif /* !FUN_GROF_H_ */

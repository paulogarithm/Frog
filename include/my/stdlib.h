/*
** Paul Parisot PROJECT, 2023
** lib2
** File description:
** my_stdlib
*/

#ifndef MY_STDLIB_H_
    #define MY_STDLIB_H_

    #include "common.h"

typedef struct s_meta meta_t;

struct s_meta {
    bool freed;
    unsigned long size;
    struct s_meta *next;
    char ptr[1];
};

char *my_ftoa(const double num);
char *my_itoa(const int num);
int my_atoi(const char *str);
long int my_atol(const char *str);
long long int my_atoll(const char *str);
double my_atof(const char *str);
char *my_ctoa(const char c);
bool my_isalphanum(const char *str);
bool my_isnum(const char *str);
bool my_isdouble(const char *str);
int my_abs(const int n);
int my_pow(const int a, const unsigned int b);
int my_min(const int a, const int b);
int my_max(const int a, const int b);

#endif /* !MY_STDLIB_H_ */

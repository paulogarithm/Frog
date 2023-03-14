/*
** EPITECH PROJECT, 2023
** frog_code
** File description:
** color
*/

#ifndef COLOR_H_
    #define COLOR_H_

enum color_enum {
    Reset = 0,
    Bold,
    Underline,

    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
};

static const char *COL[] = {
    "\033[m",
    "\033[1m",
    "\033[4m",

    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",
};

#endif /* !COLOR_H_ */

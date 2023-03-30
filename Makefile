##
## EPITECH PROJECT, 2022
## radar
## File description:
## Makefile
##

CAL 	= src/calculus/
FUN 	= src/functions/

## ---------- ##

BIN		= frog

INC		=

SRC		= src/main.c\
		src/gets.c\
		src/free.c\
		src/variables.c\
		src/condition.c\
		\
		$(CAL)calculus.c\
		$(CAL)math_a.c\
		$(CAL)math_b.c\
		$(CAL)math_c.c\
		\
		$(FUN)functions.c\
		$(FUN)native.c\
		$(FUN)fun_local.c\
		$(FUN)fun_print.c\

## ---------- ##

CC	  = gcc
RM	  = rm -rf

LIBA 	= lib/lib_A/
LIBB 	= lib/lib_B/
LIBC 	= lib/lib_C/

LIB 	= $(LIBA)my_strlen.c\
		$(LIBA)my_compstr.c\
		$(LIBA)my_findchars.c\
		$(LIBA)my_isit.c\
		$(LIBA)my_math.c\
		$(LIBA)my_nblen.c\
		$(LIBA)my_putchars.c\
		$(LIBA)my_replacechar.c\
		$(LIBA)my_revstr.c\
		$(LIBA)my_str_nb.c\
		$(LIBA)my_strcpy.c\
		$(LIBA)my_strlowup.c\
		$(LIBA)my_countchar.c\
		$(LIBA)my_cleanchar.c\
		\
		$(LIBB)my_addchars.c\
		$(LIBB)my_array.c\
		$(LIBB)my_newstr.c\
		$(LIBB)my_cutstr.c\
		$(LIBB)my_nb_str.c\
		$(LIBB)my_ignorequote.c\
		$(LIBB)my_strsplit.c\
		$(LIBB)my_newarray.c\
		$(LIBB)my_visualarray.c\
		$(LIBB)my_normalize.c\
		\
		$(LIBC)my_printf.c\
		$(LIBC)my_parsing.c\

SRCOBJ  = $(SRC:.c=.o)
LIBOBJ  = $(LIB:.c=.o)

LIBNAME = lib$(BIN).a

CFLAGS  = -Wall -Wextra -g3 -I./include


## ---------- ##

all: build

build: $(LIBOBJ) $(SRCOBJ)
	ar rc $(LIBNAME) $(LIBOBJ) $(SRCOBJ)
	$(CC) -L. -l$(BIN) $(INC) -o $(BIN)

clean:
	$(RM) $(SRCOBJ)
	$(RM) $(LIBOBJ)
	$(RM) $(LIBNAME)
	$(RM) vgcore.*
	$(RM) *.c~

fclean: clean
	$(RM) $(BIN)

re: fclean build

pol: re
	make clean

.PHONY:
	clean fclean re build all pol

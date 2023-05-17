##
## Paul Parisot PROJECT, 2023
## lib2
## File description:
## Makefile
##

#-#-#-#-#-#-#-#-#-#-#-#-#-#-#

BIN 		= frog

SRCFILES 	= src/main.c\
			src/usefull/keyvalue.c\
			src/frog_arithmetics.c\
			src/frog_builtins.c\
			src/frog_for_loop.c\
			src/frog_function.c\
			src/frog_operations_usefull.c\
			src/frog_operations.c\
			src/frog_process.c\
			src/frog_tabpos.c\
			src/frog_type.c\
			src/frog_variable_creation.c\
			src/frog_variable.c\
			src/frog.c\

#-#-#-#-#-#-#-#-#-#-#-#-#-#-#

CC			?= gcc
RM			= rm -f

SRCOBJ      = $(SRCFILES:.c=.o)
CFLAGS		= -Wall -Wextra
CPPFLAGS	= -iquote ./include

LIBDIR		= ./lib
LDFLAGS		= -L./$(LIBDIR)
LDLIBS		= -lmy

#-#-#-#-#-#-#-#-#-#-#-#-#-#-#

all: 		$(BIN)

$(BIN): 	$(SRCOBJ)
			@if [ -n "$(filter -g3,$(CFLAGS))" ]; then \
				make -C $(LIBDIR) debug; \
			else \
				make -C $(LIBDIR); \
			fi
			$(CC) $(SRCOBJ) $(LDFLAGS) $(LDLIBS) -o $(BIN)

clean:
			make -C $(LIBDIR) clean
			$(RM) $(SRCOBJ)

fclean:		clean
			make -C $(LIBDIR) fclean
			$(RM) $(BIN)

re:			fclean all

redebug:	fclean debug

debug:		CFLAGS += -g3
debug:		$(BIN)

pol:		redebug
			@make clean
			make -C $(LIBDIR) fclean

.PHONY:		all fclean clean re redebug debug pol

#-#-#-#-#-#-#-#-#-#-#-#-#-#-#

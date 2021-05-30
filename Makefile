##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##


CFLAGS		=	-I include -L lib/my -lmy -Wall -Wextra

CTEST = --coverage -lcriterion

SRC =	sources/main.c	\
		sources/game_loop.c	\
		sources/move.c	\
		sources/walls.c	\
		sources/move_player.c	\
		sources/error_handling.c	\
		sources/help.c	\
		sources/verify_terminal_size.c	\

OBJ	=	$(SRC:.c=.o)

SRC_RUN_TEST =  tests/tests.c

NAME =	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(OBJ) -I include -L lib/my -lmy -lncurses -g3 \

cleantest:
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests

clean:
	rm -f $(OBJ)

fclean: clean cleantest
	rm -f $(NAME)

unit_tests:
	gcc -o unit_tests $(SRC) $(SRC_RUN_TEST) $(CTEST) -I./include -L ./lib/my -lmy

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
	gcovr -r .
	gcovr -r . --branches

re: fclean all

.PHONY: all clean fclean re
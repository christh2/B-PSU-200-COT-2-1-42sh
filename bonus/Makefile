##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## make
##

SRC 	=	$(wildcard src/*.c)

NAME 	=	42sh

all: $(NAME)

$(NAME):	$(SRC)
	gcc $(SRC) -o $(NAME) -lcsfml-window -lcsfml-system -lcsfml-graphics

clean:
	rm -f *#
	rm -f *~

fclean: clean
	rm -f $(NAME)

re:	fclean all

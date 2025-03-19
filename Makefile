##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## 101pong
##

TESTOR	=	tests/test_my_strlen.c

TEST	=	src/my_strlen.c

SRC 	=	$(wildcard src/*.c)

NAME 	=	42sh

all: $(NAME)

$(NAME):	$(SRC)
	gcc $(SRC) -o $(NAME) -g3

clean:
	rm -f *#
	rm -f *~

fclean: clean
	rm -f $(NAME)

re:	fclean all

test_clean:	clean
	rm *.gcda
	rm *.gcno
	rm -f uni_tests

re_test:	test_clean all

tests_run:
	gcc -o uni_tests $(TEST) -I ./include/ $(TESTOR) --coverage -lcriterion
	./uni_tests

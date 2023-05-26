##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC=gcc

CCFLAGS=-W -Wall -Wextra -Werror -g3

LDFLAGS=-I./include/

SRC=./*.c

LIB=libmy_printf.a

all: clean $(LIB) header

$(LIB):
	$(CC) $(CCFLAGS) -c $(SRC) $(LDFLAGS)
	ar rc $(LIB) *.o
	cp $(LIB) ../

header:
	mkdir -p ../include
	cp -r include/*.h ../include

clean:
	rm -f ./*.o
	rm -f *.gc*
	rm -f ./include/*.gc*

fclean: clean
	rm -rf ../$(LIB)
	rm -rf ./$(LIB)

re: fclean all

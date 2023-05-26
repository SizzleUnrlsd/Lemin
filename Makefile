##
## EPITECH PROJECT, 2022
## B-CPE-200-RUN-2-1-dante-clement-antoine.xavier
## File description:
## Makefile
##


CC=gcc

CCFLAGS=-W -Wall -Wextra -Werror -g3 -Wpadded -Os -mstackrealign -falign-loops

LDFLAGS=-I./include/ -L./lib/ -lmy -lmy_printf -lm

SRC=./src/*.c

OBJ=./obj/*.o

BIN=lem_in

all:
	mkdir -p ./obj
	make -C ./lib/ all
	$(CC) $(CCFLAGS) -c $(SRC) $(LDFLAGS)
	mv *.o ./obj/
	$(CC) $(CCFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)

clean:
	make -C ./lib/ fclean
	rm -rf $(OBJ)
	rm -f *.gc*
	rm -f ./include/*.gc*

fclean: clean
	make -C ./lib fclean
	rm -rf $(BIN)
	rm -rf $(TEST_BIN)

re: fclean all

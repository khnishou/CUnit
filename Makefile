CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = CUnit.c mem.c toolbox.c var.c
OBJ = $(SRC:.c=.o)

EXEC = CUnit

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c CUnit.h
	$(CC) $(CFLAGS) -c $< -o $@

fclean:
	rm -f $(OBJ) $(EXEC)

re: clean all

.PHONY: all clean rebuild

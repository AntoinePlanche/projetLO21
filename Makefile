CC=gcc
CFLAGS=-W -Wall -Wextra -Wno-unused-parameter
LDFLAGS= -lm
EXEC=projet-LO21
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

projet-LO21: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)

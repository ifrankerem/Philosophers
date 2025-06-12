NAME = philo

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

HEADER = philo.h

SRC = main.c \
      actions.c \
      better_usleep.c \
      clean.c \
      dinner.c \
      error.c \
      init.c \
      log.c \
      monitor.c \
      parsing.c \
      utils.c

OBJ = main.o \
      actions.o \
      better_usleep.o \
      clean.o \
      dinner.o \
      error.o \
      init.o \
      log.o \
      monitor.o \
      parsing.o \
      utils.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
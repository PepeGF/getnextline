SRCS = get_next_line.c get_next_line_utils.c

$(NAME) =

CC = gcc

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=$(BUFFER_SIZE)

BUFFER_SIZE = 32

all:

clean:

fclean:

re:

.PHONY: all clean fclean re

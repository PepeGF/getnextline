#!/bin/bash
read -p "Introduce BUFFER_SIZE: " buff
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$buff wololo.c get_next_line_utils.c get_next_line.h && ./a.out | cat -e

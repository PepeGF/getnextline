#!/bin/bash
read -p "Introduce BUFFER_SIZE: " buff
read -p "Introduce LINEAS: (0 es todas) " line
gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=$buff -D LINEAS=$line get_next_line.c get_next_line_utils.c get_next_line.h && time ./a.out | cat -e

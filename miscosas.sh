#!/bin/bash
read -p "Introduce BUFFER_SIZE: " buff
read -p "introduce LINEAS: " line
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$buff -D LINEAS=$line nuevaspruebas.c get_next_line_utils.c get_next_line.h && ./a.out | cat -e
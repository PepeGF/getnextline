#!/bin/bash
gcc -g -O0 -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c get_next_line.h && gdb -q ./a.out -tui

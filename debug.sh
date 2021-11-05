#!/bin/bash
gcc -g -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c get_next_line.h && gdb ./a.out

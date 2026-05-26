# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gemini-cli <gemini@tester.unit.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:27:13 by jtoty             #+#    #+#              #
#    Updated: 2026/05/20 12:00:00 by gemini-cli       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

###################################################
#                 Part1 functions                 #
###################################################

Part1_func=('ft_isalpha.c' 'ft_isdigit.c' 'ft_isalnum.c' 'ft_isascii.c' 'ft_isprint.c' \
'ft_strlen.c' 'ft_memset.c' 'ft_bzero.c' 'ft_memcpy.c' 'ft_memmove.c' \
'ft_strlcpy.c' 'ft_strlcat.c' 'ft_toupper.c' 'ft_tolower.c' 'ft_strchr.c' \
'ft_strrchr.c' 'ft_strncmp.c' 'ft_memchr.c' 'ft_memcmp.c' 'ft_strnstr.c' \
'ft_atoi.c' 'ft_calloc.c' 'ft_strdup.c')

# Authorized bits: 1=malloc, 2=free, 4=write
Part1_func_authorized=('0' '0' '0' '0' '0' \
'0' '0' '0' '0' '0' \
'0' '0' '0' '0' '0' \
'0' '0' '0' '0' '0' \
'0' '1' '1')

Part1_func_activation=('0' '0' '0' '0' '0' \
'0' '0' '0' '0' '0' \
'0' '0' '0' '0' '0' \
'0' '0' '0' '0' '0' \
'0' '0' '0')

###################################################
#                 Part2 functions                 #
###################################################

Part2_func=('ft_substr.c' 'ft_strjoin.c' 'ft_strtrim.c' 'ft_split.c' 'ft_itoa.c' \
'ft_strmapi.c' 'ft_striteri.c' 'ft_putchar_fd.c' 'ft_putstr_fd.c' 'ft_putendl_fd.c' \
'ft_putnbr_fd.c')

# Authorized bits: 1=malloc, 2=free, 4=write
Part2_func_authorized=('1' '1' '1' '3' '1' \
'1' '0' '4' '4' '4' '4')

Part2_func_activation=('0' '0' '0' '0' '0' \
'0' '0' '0' '0' '0' '0')

###################################################
#                 Part3 functions                 #
###################################################

Part3_func=('ft_lstnew.c' 'ft_lstadd_front.c' 'ft_lstsize.c' 'ft_lstlast.c' \
'ft_lstadd_back.c' 'ft_lstdelone.c' 'ft_lstclear.c' 'ft_lstiter.c' \
'ft_lstmap.c')

# Authorized bits: 1=malloc, 2=free, 4=write
Part3_func_authorized=('1' '0' '0' '0' \
'0' '2' '2' '0' '3')

Part3_func_activation=('0' '0' '0' '0' \
'0' '0' '0' '0' '0')

###################################################
#                 Other variables                 #
###################################################

tab_all_part=('Part1_func' 'Part2_func' 'Part3_func')

num_sys_func=('1' '2' '4')
system_func=('void' 'malloc' 'free' 'printf' 'write')

# COORDENADAS RECALCULADAS PARA TABELA LARGA (WIDE)
NORME_COL=23
CHEAT_COL=34
COMPIL_COL=50
LEAKS_COL=60
TEST_COL=71
RESULT_COL=133
TITLE_LENGTH=142
CHAR_LENGTH="-"
CHAR_WIDTH="|"

DIRECTORY=0
OPT_NO_LIBRARY=0
OPT_FULL_MAKEFILE=0
OPT_NO_SEARCH=0
OPT_NO_COLOR=0
OPT_NO_FORBIDDEN=0
OPT_NO_NORMINETTE=0
OPT_NO_UPDATE=0
OPT_FAST=0
OPT_NO_PART1=0
OPT_NO_PART2=0
OPT_NO_PART3=0
ACTIVATE_PART1=0
ACTIVATE_PART2=0
ACTIVATE_PART3=0
CHECK_IN_PART1=1
CHECK_IN_PART2=1
CHECK_IN_PART3=1
CUSTOM_DIRECTORY=1

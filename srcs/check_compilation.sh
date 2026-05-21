# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_compilation.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gemini-cli <gemini@tester.unit.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:26:19 by jtoty             #+#    #+#              #
#    Updated: 2026/05/20 12:00:00 by gemini-cli       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

compilation()
{
	if [ -e "${PATH_TEST}"/user_exe ]
	then
		rm -f "${PATH_TEST}"/user_exe
	fi
	
	# Full link logic: function_file.c + test_main.c + libft.a
	# This ensures all dependencies are satisfied.
	
	local func_src="${PATH_LIBFT}/${SRC_DIR}/$1"
	local test_main="${PATH_TEST}/tests/$(echo ${part}tions)/$(echo $1 | cut -d . -f 1 | sed 's/_bonus//g')/main.c"
	local lib_a="${PATH_LIBFT}/libft.a"
	
	printf "$> clang -Wextra -Wall -Werror -g3 $1 main.c libft.a -o user_exe\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
	
	clang -Wextra -Wall -Werror -g3 "$func_src" "$test_main" "$lib_a" \
		  -I "${PATH_LIBFT}"/${HEADER_DIR}/ \
		  -I "${PATH_TEST}" \
		  -I . \
		  2>>"${PATH_DEEPTHOUGHT}"/deepthought -o user_exe
}

check_compilation()
{
	printf "\033[${COMPIL_COL}G"
	if [ -e "${PATH_TEST}"/user_exe ]
	then
		printf "  ${COLOR_OK}✅ OK ${DEFAULT}"
		return 1
	else
		printf "  ${COLOR_FAIL}❌ ERR${DEFAULT}"
		return 0
	fi
}

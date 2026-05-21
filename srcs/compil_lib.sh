# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compil_lib.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gemini-cli <gemini@tester.unit.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:26:36 by jtoty             #+#    #+#              #
#    Updated: 2026/05/20 12:00:00 by gemini-cli       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

func_compil_lib()
{
	printf "\n${COLOR_PART}─── Checking & Compiling libft.a ───${DEFAULT}\n"
	
	if [ -e "${PATH_LIBFT}"/libft.a ]; then
		rm -f "${PATH_LIBFT}"/libft.a
	fi

	if [ "${MAKEFILE_VAR}" == "missing_makefile" ]; then
		printf "${COLOR_FAIL}❌ Missing Makefile, cannot compile library.${DEFAULT}\n"
		printf "\nMissing Makefile, can't compil library.\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
		return
	fi

	printf "${BOLD}┌───────────────────┬────────────┐${DEFAULT}\n"
	
	# Full testing mode (requested for 2026 PDF compliance)
	local rules=("all" "clean" "fclean" "re" "bonus")
	
	for rule in "${rules[@]}"
	do
		printf "${BOLD}│ make %-12s │${DEFAULT}" "$rule"
		
		# Check if rule exists in Makefile text first
		local pattern=$(echo "$rule" | sed 's/\$/\\\$/g')
		if grep -E "^${pattern}[[:space:]]*:" "${PATH_LIBFT}"/${MAKEFILE_VAR} > /dev/null 2>&1
		then
			printf "\n$> make $rule\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
			make --no-print-directory -C "${PATH_LIBFT}" "$rule" >> "${PATH_DEEPTHOUGHT}"/deepthought 2>&1
			if [ $? -eq 0 ]; then
				printf " ${COLOR_OK}✅ OK${DEFAULT}       │\n"
			else
				printf " ${COLOR_FAIL}❌ ERR${DEFAULT}      │\n"
			fi
		else
			printf " ${COLOR_WARNING}⚠️  MISSING${DEFAULT}  │\n"
		fi
	done

	printf "${BOLD}├───────────────────┼────────────┤${DEFAULT}\n"
	printf "${BOLD}│ Result: libft.a   │${DEFAULT}"
	
	# Final compilation for tests (ensure all and bonus are built)
	make --no-print-directory -C "${PATH_LIBFT}" all bonus >> "${PATH_DEEPTHOUGHT}"/deepthought 2>&1
	
	if [ -e "${PATH_LIBFT}"/libft.a ]; then
		printf " ${COLOR_OK}✅ FOUND${DEFAULT}    │\n"
	else
		printf " ${COLOR_FAIL}❌ MISSING${DEFAULT}  │\n"
	fi
	printf "${BOLD}└───────────────────┴────────────┘${DEFAULT}\n"
}

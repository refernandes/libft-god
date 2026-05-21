# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_function.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gemini-cli <gemini@tester.unit.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:27:09 by jtoty             #+#    #+#              #
#    Updated: 2026/05/20 12:00:00 by gemini-cli       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

draw_static_progress()
{
	local current=$1
	local total=$2
	local width=40
	local percent=$((current * 100 / total))
	local filled=$((current * width / total))
	local empty=$((width - filled))
	printf "\n${COLOR_INFO}Progress: ["
	for ((j=0; j<filled; j++)); do printf "█"; done
	for ((j=0; j<empty; j++)); do printf "░"; done
	printf "] %d%%${DEFAULT}\033[1A\r" $percent
}

check_turned_in_file()
{
	local file_to_check=$1
	local clean_name=$(echo $file_to_check | sed 's/_bonus//g')
	
	text="= $file_to_check "
	printf "\n${text}" >> "${PATH_DEEPTHOUGHT}"/deepthought
	printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> "${PATH_DEEPTHOUGHT}"/deepthought
	printf "\n" >> "${PATH_DEEPTHOUGHT}"/deepthought

	if [ -e "${PATH_LIBFT}"/${SRC_DIR}/${file_to_check} ] || [ -e "${PATH_LIBFT}"/${SRC_DIR}/${clean_name} ]
	then
		return 1
	else
		printf "\033[${NORME_COL}G${COLOR_FAIL}   NTI  ${DEFAULT}"
		printf "\033[${CHEAT_COL}G${COLOR_FAIL}      NTI      ${DEFAULT}"
		printf "\033[${COMPIL_COL}G${COLOR_FAIL}  NTI   ${DEFAULT}"
		printf "\033[${LEAKS_COL}G${COLOR_FAIL}  NTI   ${DEFAULT}"
		printf "\033[${TEST_COL}G${COLOR_FAIL}      NTI      ${DEFAULT}"
		printf "\033[${RESULT_COL}G${COLOR_FAIL}  NTI   ${DEFAULT}│\n"
		printf "Nothing turned in\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
		return 0
	fi
}

test_function()
{
	local part_name=$(echo ${part} | cut -d _ -f 1)
	printf "\n${COLOR_PART}─── Testing ${part_name} functions ───${DEFAULT}\n"
	
	# Modern Table Header - Adjusted for Ultra-Wide columns
	printf "${BOLD}┌───────────────────┬─────────┬───────────────┬────────┬────────┬──────────────────────────────────────────────────────────────┬────────┐${DEFAULT}\n"
	printf "${BOLD}│ FUNCTION          │ NORME   │ FORBIDDEN     │ COMPIL │ LEAKS  │ TESTS                                                        │ RESULT │${DEFAULT}\n"
	printf "${BOLD}├───────────────────┼─────────┼───────────────┼────────┼────────┼──────────────────────────────────────────────────────────────┼────────┤${DEFAULT}\n"

	local i=0
	local success=0
	local total_tested=0
	local tab_part=$(echo ${part}[*])
	local func_list=(${!tab_part})

	for function in "${func_list[@]}"
	do
		if [ $(( ${part}_activation[$i] )) -eq 1 ]
		then
			let "total_tested += 1"
			func_name=$(echo "$function" | cut -d . -f 1 | sed 's/_bonus//g')
			
			printf "│ ${COLOR_FUNC}%-17s${DEFAULT} │" "${func_name}"
			
			check_turned_in_file $function
			if [ $? -eq 1 ]
			then
				result=1
				
				# Norme
				if [ ${OPT_NO_NORMINETTE} -eq 0 ]
				then
					check_norme $function
					[ $? -eq 0 ] && result=0
				else
					printf "\033[${NORME_COL}G  ${DEFAULT}SKIP "
				fi
				
				# Compilation
				local target_file=$function
				[ ! -e "${PATH_LIBFT}"/${SRC_DIR}/$function ] && target_file=$(echo ${function} | sed 's/_bonus//g')
				
				compilation $target_file
				check_compilation
				if [ $? -eq 1 ]
				then
					# Forbidden functions
					if [ ${OPT_NO_FORBIDDEN} -eq 0 ]
					then
						check_cheating $target_file $(( ${part}_authorized[$i] ))
						[ $? -eq 1 ] && result=0
					else
						printf "\033[${CHEAT_COL}G    ${DEFAULT}  SKIP     "
					fi
					
					# Tests and Leaks
					diff_test $target_file
					[ $? -eq 0 ] && result=0
				else
					printf "\033[${CHEAT_COL}G${COLOR_FAIL}    FAIL       ${DEFAULT}"
					printf "\033[${COMPIL_COL}G${COLOR_FAIL} FAIL ${DEFAULT}"
					printf "\033[${LEAKS_COL}G${COLOR_FAIL} FAIL ${DEFAULT}"
					printf "\033[${TEST_COL}G${COLOR_FAIL}     FAIL      ${DEFAULT}"
					result=0
				fi
				
				# Final Result - Aligned to the new RESULT_COL
				printf "\033[${RESULT_COL}G"
				if [ $result -eq 0 ]
				then
					printf "${COLOR_FAIL}  KO  ${DEFAULT}│\n"
				else
					printf "${COLOR_OK}  OK  ${DEFAULT}│\n"
					let "success += 1"
				fi
			fi
			
			let "GLOBAL_CURRENT += 1"
			[ -e "${PATH_TEST}"/user_exe ] && rm -f "${PATH_TEST}"/user_exe
		fi
		let "i += 1"
	done
	
	# Table Footer
	printf "${BOLD}└───────────────────┴─────────┴───────────────┴────────┴────────┴──────────────────────────────────────────────────────────────┴────────┘${DEFAULT}\n"
	
	# Part Summary
	local color_summary="${COLOR_OK}"
	[ $success -lt $total_tested ] && color_summary="${COLOR_FAIL}"
	printf "${BOLD}${part_name} Summary: ${color_summary}${success}/${total_tested}${DEFAULT} functions passed.\n"
	
	draw_static_progress $GLOBAL_CURRENT $GLOBAL_TOTAL
	printf "\n"
}

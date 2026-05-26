# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    diff_test.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gemini-cli <gemini@tester.unit.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:26:48 by jtoty             #+#    #+#              #
#    Updated: 2026/05/20 12:00:00 by gemini-cli       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

diff_test()
{
	# First, run the tests and print progress icons at TEST_COL
	printf "\033[${TEST_COL}G"

	local test_dir="${PATH_TEST}/tests/$(echo ${part}tions)/$(echo $1 | cut -d . -f 1 | sed 's/_bonus//g')"
	if [ ! -d "$test_dir" ]; then
		printf "  ${COLOR_FAIL}❌ NO TESTS${DEFAULT}"
		return 0
	fi

	cd "$test_dir"
	local kmax=$(ls -1 test*.output 2>/dev/null | wc -l)
	cd "${PATH_TEST}"

	local retvalue=1
	local leak_found=0
	local k=1

	while [ $k -le $kmax ]
	do
		# Format test number as 01, 02...
		local text=$(printf "%02d" $k)

		printf "\n= Test $k " >> "${PATH_DEEPTHOUGHT}"/deepthought
		printf "%.s=" $(seq 1 60) >> "${PATH_DEEPTHOUGHT}"/deepthought
		printf "\n$> ./user_exe $k\n" >> "${PATH_DEEPTHOUGHT}"/deepthought

		local valgrind_log="/tmp/leaks_libft_${k}_$$.log"
		local leaks_cmd=""
		local valgrind_cmd=""
		local output_file="$test_dir/user_output_test$text"
		local expected_file="$test_dir/test$text.output"

		if [ ${OPT_FAST} -eq 0 ]; then
			# --- ORIGINAL MODE: Leak check PER TEST ---
			if [ "$(uname)" == "Darwin" ]; then
				leaks_cmd="leaks -quiet -atExit --"
			elif command -v valgrind &> /dev/null; then
				valgrind_cmd="valgrind --leak-check=full --error-exitcode=42 --log-file=$valgrind_log -q"
			fi

			if [ $(( $k%2 )) -eq 1 ] && [[ "$1" =~ ^ft_put.*_fd\.c$ ]]; then
				if [ "$(uname)" == "Darwin" ]; then
					"${PATH_TEST}"/user_exe $k > /dev/null 2> "$output_file"
					${leaks_cmd} "${PATH_TEST}"/user_exe $k > "$valgrind_log" 2>&1
				else
					${valgrind_cmd} "${PATH_TEST}"/user_exe $k > /dev/null 2> "$output_file"
				fi
			else
				if [ "$(uname)" == "Darwin" ]; then
					"${PATH_TEST}"/user_exe $k > "$output_file" 2>/dev/null
					${leaks_cmd} "${PATH_TEST}"/user_exe $k > "$valgrind_log" 2>&1
				else
					${valgrind_cmd} "${PATH_TEST}"/user_exe $k > "$output_file" 2>/dev/null
				fi
			fi
			
			local sig=$?
			if [ "$(uname)" == "Darwin" ]; then
				if grep -qE "[1-9][0-9]* leaks?" "$valgrind_log" 2>/dev/null; then sig=42; fi
			fi

			if [ $sig -eq 42 ]; then
				leak_found=1
				printf "Memory leak detected in Test $k\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
				[ -f "$valgrind_log" ] && cat "$valgrind_log" >> "${PATH_DEEPTHOUGHT}"/deepthought
				if [ "$(uname)" != "Darwin" ]; then
					if [ $(( $k%2 )) -eq 1 ] && [[ "$1" =~ ^ft_put.*_fd\.c$ ]]; then
						"${PATH_TEST}"/user_exe $k > /dev/null 2> "$output_file"
					else
						"${PATH_TEST}"/user_exe $k > "$output_file" 2>/dev/null
					fi
				fi
			fi
		else
			# --- FAST MODE: No leak check inside loop ---
			if [ $(( $k%2 )) -eq 1 ] && [[ "$1" =~ ^ft_put.*_fd\.c$ ]]; then
				"${PATH_TEST}"/user_exe $k > /dev/null 2> "$output_file"
			else
				"${PATH_TEST}"/user_exe $k > "$output_file" 2>/dev/null
			fi
			local sig=$?
		fi

		# Check Signals and Diff
		if [ $sig -eq 134 ]; then
			printf "${COLOR_FAIL}A${DEFAULT}"; retvalue=0; printf "Killed by Abort\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
		elif [ $sig -eq 138 ]; then
			printf "${COLOR_FAIL}B${DEFAULT}"; retvalue=0; printf "Killed by Bus Error\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
		elif [ $sig -eq 139 ]; then
			printf "${COLOR_FAIL}S${DEFAULT}"; retvalue=0; printf "Killed by Segfault\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
		elif [ $sig -eq 142 ]; then
			printf "${COLOR_FAIL}T${DEFAULT}"; retvalue=0; printf "Killed by Timeout\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
		else
			printf "$> diff -U 3 user_output test.output\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
			if [ ! -f "$output_file" ] || ! diff -U 3 "$output_file" "$expected_file" >> "${PATH_DEEPTHOUGHT}"/deepthought 2>&1; then
				printf "Diff KO ❌\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
				printf "${COLOR_FAIL}❌${DEFAULT}"
				retvalue=0
			else
				printf "Diff OK ✅\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
				printf "${COLOR_OK}✅${DEFAULT}"
			fi
		fi
		[ -f "$valgrind_log" ] && rm -f "$valgrind_log"
		let "k += 1"
	done

	# --- FAST MODE: Optimized Leak Check (Runs ONCE per function) ---
	if [ ${OPT_FAST} -eq 1 ]; then
		local valgrind_log="/tmp/leaks_libft_all_$$.log"
		local leak_status=0
		
		if [ "$(uname)" == "Darwin" ]; then
			leaks -quiet -atExit -- /bin/bash -c "for i in \$(seq 1 $kmax); do \"${PATH_TEST}/user_exe\" \$i >/dev/null 2>&1; done" > "$valgrind_log" 2>&1
			if grep -qE "[1-9][0-9]* leaks?" "$valgrind_log" 2>/dev/null; then leak_status=42; fi
		elif command -v valgrind &> /dev/null; then
			valgrind --leak-check=full --error-exitcode=42 --log-file="$valgrind_log" -q /bin/bash -c "for i in \$(seq 1 $kmax); do \"${PATH_TEST}/user_exe\" \$i >/dev/null 2>&1; done"
			leak_status=$?
		fi

		if [ $leak_status -eq 42 ]; then
			leak_found=1
			printf "\n= Memory Leak Detection (Fast Mode) " >> "${PATH_DEEPTHOUGHT}"/deepthought
			printf "%.s=" $(seq 1 44) >> "${PATH_DEEPTHOUGHT}"/deepthought
			printf "\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
			cat "$valgrind_log" >> "${PATH_DEEPTHOUGHT}"/deepthought
		fi
		[ -f "$valgrind_log" ] && rm -f "$valgrind_log"
	fi

	# After all icons, print LEAKS status column
	printf "\033[${LEAKS_COL}G"
	if [ $leak_found -eq 1 ]; then
		printf "${COLOR_FAIL}KO${DEFAULT}"
	elif [ "$(uname)" == "Darwin" ]; then
		printf "${COLOR_OK}0 LEAKS${DEFAULT}"
	elif command -v valgrind &> /dev/null; then
		printf "${COLOR_OK}OK${DEFAULT}"
	else
		printf "${COLOR_WARNING}N/A${DEFAULT}"
	fi
	return $retvalue
}

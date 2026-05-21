#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

void	ft_print_result(int n)
{
	if (n > 0)
		write(1, "1", 1);
	else if (n < 0)
		write(1, "-1", 2);
	else
		write(1, "0", 1);
}

int		main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_print_result(ft_memcmp("salut", "salut", 5));
	else if (arg == 2)
		ft_print_result(ft_memcmp("t\200", "t\0", 2));
	else if (arg == 3)
		ft_print_result(ft_memcmp("testss", "test", 5));
	else if (arg == 4)
		ft_print_result(ft_memcmp("test", "tEst", 4));
	else if (arg == 5)
		ft_print_result(ft_memcmp("", "test", 4));
	else if (arg == 6)
		ft_print_result(ft_memcmp("test", "", 4));
	else if (arg == 7)
		ft_print_result(ft_memcmp("abcdefghij", "abcdefgxyz", 7));
	else if (arg == 8)
		ft_print_result(ft_memcmp("abcdefgh", "abcdwxyz", 6));
	else if (arg == 9)
		ft_print_result(ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
	else if (arg == 10)
        ft_print_result(ft_memcmp("abc\0def", "abc\0xyz", 4));
    else if (arg == 11)
        ft_print_result(ft_memcmp("abc\0def", "abc\0xyz", 7));
    else if (arg == 12)
        ft_print_result(ft_memcmp("abc", "abd", 2));
    else if (arg == 13)
        ft_print_result(ft_memcmp("abc", "abd", 3));
    else if (arg == 14)
        ft_print_result(ft_memcmp("\200", "\201", 1));
    else if (arg == 15)
        ft_print_result(ft_memcmp("\201", "\200", 1));
    else if (arg == 16)
        ft_print_result(ft_memcmp("\377", "\0", 1));
    else if (arg == 17)
        ft_print_result(ft_memcmp("\0\1", "\0\2", 2));
    else if (arg == 18)
        ft_print_result(ft_memcmp("\0\2", "\0\1", 2));
    else if (arg == 19)
        ft_print_result(ft_memcmp("abcdx", "abcdy", 4));
    else if (arg == 20)
        ft_print_result(ft_memcmp("abcdx", "abcdy", 5));
    return (0);
}

#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

int	main(int argc, const char *argv[])
{
	int	arg;

	alarm(5);
	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		ft_putstr_fd("lorem ipsum dolor sit amet", 2);
	else if (arg == 2)
		ft_putstr_fd("  lorem\nipsum\rdolor\tsit amet  ", 1);
	else if (arg == 3)
		ft_putstr_fd("", 2);
	else if (arg == 4)
		ft_putstr_fd("lorem ipsum do\0lor sit amet", 1);
	else if (arg == 6)
		ft_putstr_fd("\n", 1);
	else if (arg == 8)
		ft_putstr_fd("abc", -1);
	else if (arg == 9)
		ft_putstr_fd("abc", 42);
	else if (arg == 10)
		ft_putstr_fd("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 1);
	return (0);
}

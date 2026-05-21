#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	void	*mem;
	int		arg;

	alarm(5);
	if (!(mem = malloc(sizeof(*mem) * 15)) || argc == 1)
		return (0);
	memset(mem, 'j', 15);
	if ((arg = atoi(argv[1])) == 1)
	{
		if (mem != ft_memset(mem, 'c', 5))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 2)
	{
		if (mem != ft_memset(mem, 'c', 14))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 3)
	{
		if (mem != ft_memset(mem, '\n', 6))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 4)
	{
		if (mem != ft_memset(mem, '\0', 1))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 5)
	{
		if (mem != ft_memset(mem, 'c', 15))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 6)
	{
		if (mem != ft_memset(mem, '\0', 6))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 7)
	{
		if (mem != ft_memset(mem, '\t', 5))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 8)
	{
		if (mem != ft_memset(mem, ' ', 10))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 9)
	{
		if (mem != ft_memset(mem, 1, 7))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 10)
	{
		if (mem != ft_memset(mem, 127, 4))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 11)
	{
		if (mem != ft_memset(mem, 255, 8))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 12)
	{
		if (mem != ft_memset(mem, -1, 5))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 13)
	{
		if (mem != ft_memset(mem, 'A', 1))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 14)
	{
		if (mem != ft_memset(mem, 'Z', 8))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 15)
	{
		if (mem != ft_memset(mem, 'X', 8))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 16)
	{
		if (mem != ft_memset(mem, 'c', 0))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	return (0);
}

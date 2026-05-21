#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	void	*mem;

	alarm(5);
	if (argc == 1 || !(mem = malloc(sizeof(*mem) * 5)))
		return (0);
	if (atoi(argv[1]) == 1)
	{
		memset(mem, 'e', 5);
		ft_bzero(mem, 5);
		write(1, mem, 5);
	}
	else if (atoi(argv[1]) == 2)
	{
		memset(mem, 'e', 5);
		ft_bzero(mem, 0);
		write(1, mem, 5);
	}
	else if (atoi(argv[1]) == 3)
{
    memset(mem, 'e', 5);
    ft_bzero(mem, 1);
    write(1, mem, 5);
}
else if (atoi(argv[1]) == 4)
{
    memset(mem, 'e', 5);
    ft_bzero(mem, 2);
    write(1, mem, 5);
}
else if (atoi(argv[1]) == 5)
{
    memset(mem, 'e', 5);
    ft_bzero(mem, 3);
    write(1, mem, 5);
}
else if (atoi(argv[1]) == 6)
{
    memset(mem, 'e', 5);
    ft_bzero(mem, 4);
    write(1, mem, 5);
}
else if (atoi(argv[1]) == 7)
{
    memset(mem, 'e', 5);
    ft_bzero(mem, 5);
    write(1, mem, 5);
}
else if (atoi(argv[1]) == 8)
{
    memset(mem, 'e', 5);
    ft_bzero(mem, 0);
    write(1, mem, 5);
}
	return (0);
}

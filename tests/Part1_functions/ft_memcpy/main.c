#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	void	*mem;
	int		arg;

	alarm(5);
	if (!(mem = malloc(sizeof(*mem) * 30)) || argc == 1)
		return (0);
	memset(mem, 'j', 30);
	if ((arg = atoi(argv[1])) == 1)
	{
		if (mem != ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14))
			write(1, "dest's adress was not returned\n", 31);
		write(1, mem, 30);
	}
	else if (arg == 2)
	{
		if (mem != ft_memcpy(mem, "zyxwvutst", 0))
			write(1, "dest's adress was not returned\n", 31);
		write(1, mem, 30);
	}
	else if (arg == 3)
	{
		if (mem != ft_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11))
			write(1, "dest's adress was not returned\n", 31);
		write(1, mem, 30);
	}
	else if (arg == 4)
{
    if (mem != ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 1))
        write(1, "dest's adress was not returned\n", 31);
    write(1, mem, 30);
}
else if (arg == 5)
{
    if (mem != ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 5))
        write(1, "dest's adress was not returned\n", 31);
    write(1, mem, 30);
}
else if (arg == 6)
{
    if (mem != ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 26))
        write(1, "dest's adress was not returned\n", 31);
    write(1, mem, 30);
}
else if (arg == 7)
{
    if (mem != ft_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11))
        write(1, "dest's adress was not returned\n", 31);
    write(1, mem, 30);
}
else if (arg == 8)
{
    if (mem != ft_memcpy(mem, "", 0))
        write(1, "dest's adress was not returned\n", 31);
    write(1, mem, 30);
}
else if (arg == 9)
{
    if (mem != ft_memcpy(mem, "abcdefghijklmnop", 16))
        write(1, "dest's adress was not returned\n", 31);
    write(1, mem, 30);
}
else if (arg == 10)
{
    if (mem != ft_memcpy(mem, "1234567890", 10))
        write(1, "dest's adress was not returned\n", 31);
    write(1, mem, 30);
}
else if (arg == 11)
{
    if (mem != ft_memcpy(mem, "A", 1))
        write(1, "dest's adress was not returned\n", 31);
    write(1, mem, 30);
}
else if (arg == 12)
{
    if (mem != ft_memcpy(mem, "\n\t\r\v\f", 5))
        write(1, "dest's adress was not returned\n", 31);
    write(1, mem, 30);
}
	return (0);
}

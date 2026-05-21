
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	char	*dest;
	int		arg;

	alarm(5);
	if (!(dest = (char *)malloc(sizeof(*dest) * 15)) || argc == 1)
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	if ((arg = atoi(argv[1])) == 1)
	{
		dest[8] = 'a';
		if (dest != ft_strncat(dest, "lorem", 2))
			write(1,"dest's adress was not returned\n", 31);
		write(1, dest, 15);
	}
	else if (arg == 2)
	{
		dest[11] = 'a';
		if (dest != ft_strncat(dest, "lorem", 9))
			write(1,"dest's adress was not returned\n", 31);
		write(1, dest, 15);
	}
	else if (arg == 3)
	{
		if (dest != ft_strncat(dest, "", 3))
			write(1,"dest's adress was not returned\n", 31);
		write(1, dest, 15);
	}
	else if (arg == 4)
	{
		if (dest != ft_strncat(dest, "lorem ipsum", 0))
			write(1,"dest's adress was not returned\n", 31);
		write(1, dest, 15);
	}
	else if (arg == 5)
	{
		dest[0] = '\0';
		dest[10] = 'a';
		if (dest != ft_strncat(dest, "lorem ipsum", 10))
			write(1,"dest's adress was not returned\n", 31);
		write(1, dest, 15);
	}
	    else if (arg == 6)
    {
        if (dest != ft_strncat(dest, "lorem", 1))
            write(1,"dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 7)
    {
        dest[7] = 'a';
        if (dest != ft_strncat(dest, "lo", 2))
            write(1,"dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 8)
    {
        dest[7] = 'a';
        if (dest != ft_strncat(dest, "lo", 5))
            write(1,"dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 9)
    {
        dest[0] = '\0';
        if (dest != ft_strncat(dest, "", 5))
            write(1,"dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 10)
    {
        dest[0] = '\0';
        if (dest != ft_strncat(dest, "abc", 1))
            write(1,"dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 11)
    {
        dest[0] = '\0';
        if (dest != ft_strncat(dest, "abc", 3))
            write(1,"dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 12)
    {
        memset(dest, 'x', 15);
        dest[3] = '\0';
        if (dest != ft_strncat(dest, "yz", 2))
            write(1,"dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 13)
    {
        strcpy(dest, "abc");
        if (dest != ft_strncat(dest, "def", 2))
            write(1,"dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 14)
    {
        strcpy(dest, "abc");
        if (dest != ft_strncat(dest, "def", 3))
            write(1,"dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
	return (0);
}

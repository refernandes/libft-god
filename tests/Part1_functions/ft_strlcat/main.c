#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"
#include <string.h>

void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

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
		dest[11] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 2)
	{
		ft_print_result(ft_strlcat(dest, "", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 3)
	{
		dest[0] = '\0';
		dest[11] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 4)
	{
		dest[14] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 5)
	{
		dest[10] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 6)
	{
		dest[10] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 1));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 7)
	{
		memset(dest, 'r', 15);
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 8)
	{
		dest[10] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 6));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 9)
	{
		memset(dest, 'r', 14);
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	    else if (arg == 10)
    {
        strcpy(dest, "abc");
        ft_print_result(ft_strlcat(dest, "de", 6));
        write(1, "\n", 1);
        write(1, dest, 15);
    }
    else if (arg == 11)
    {
        strcpy(dest, "abc");
        ft_print_result(ft_strlcat(dest, "de", 5));
        write(1, "\n", 1);
        write(1, dest, 15);
    }
    else if (arg == 12)
    {
        strcpy(dest, "abcdef");
        ft_print_result(ft_strlcat(dest, "X", 4));
        write(1, "\n", 1);
        write(1, dest, 15);
    }
    else if (arg == 13)
    {
        dest[0] = '\0';
        ft_print_result(ft_strlcat(dest, "abc", 1));
        write(1, "\n", 1);
        write(1, dest, 15);
    }
    else if (arg == 14)
    {
        strcpy(dest, "abc");
        ft_print_result(ft_strlcat(dest, "", 4));
        write(1, "\n", 1);
        write(1, dest, 15);
    }
    else if (arg == 15)
    {
        strcpy(dest, "abc");
        ft_print_result(ft_strlcat(dest, "defgh", 4));
        write(1, "\n", 1);
        write(1, dest, 15);
    }
    else if (arg == 16)
    {
        strcpy(dest, "abcd");
        ft_print_result(ft_strlcat(dest, "Z", 5));
        write(1, "\n", 1);
        write(1, dest, 15);
    }
    else if (arg == 17)
    {
        strcpy(dest, "abcd");
        ft_print_result(ft_strlcat(dest, "Z", 4));
        write(1, "\n", 1);
        write(1, dest, 15);
    }
    else if (arg == 18)
    {
        memset(dest, 'x', 15);
        dest[3] = '\0';
        ft_print_result(ft_strlcat(dest, "yz", 15));
        write(1, "\n", 1);
        write(1, dest, 15);
    }
    else if (arg == 19)
    {
        memset(dest, 'a', 15);
        dest[14] = '\0';
        ft_print_result(ft_strlcat(dest, "b", 15));
        write(1, "\n", 1);
        write(1, dest, 15);
    }
    else if (arg == 20)
    {
        dest[0] = '\0';
        ft_print_result(ft_strlcat(dest, "", 15));
        write(1, "\n", 1);
        write(1, dest, 15);
    }
	return (0);
}

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

void	ft_print_result(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void	iter(unsigned int i, char *c)
{
	static int	index_array[26] = {0};

	if (i > 25 || index_array[i] == 1)
		write(1, "wrong index\n", 12);
	else
		index_array[i] = 1;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

int	main(int argc, const char *argv[])
{
	char	*str;

	alarm(5);
	str = (char *)malloc(sizeof(*str) * 32);
	if (argc == 1 || !str)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		strcpy(str, "LoReM iPsUm");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	else if (atoi(argv[1]) == 2)
	{
		strcpy(str, "");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	else if (atoi(argv[1]) == 3)
	{
		strcpy(str, "a");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	else if (atoi(argv[1]) == 4)
	{
		strcpy(str, "A");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	else if (atoi(argv[1]) == 5)
	{
		strcpy(str, "1234!?$");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	else if (atoi(argv[1]) == 6)
	{
		strcpy(str, "abc");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	else if (atoi(argv[1]) == 7)
	{
		strcpy(str, "ABC");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	else if (atoi(argv[1]) == 8)
	{
		strcpy(str, "   ");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	else if (atoi(argv[1]) == 9)
	{
		strcpy(str, "aBcDeFgHiJ");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	else if (atoi(argv[1]) == 10)
	{
		strcpy(str, "0123456789");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	else if (atoi(argv[1]) == 11)
	{
		strcpy(str, "abcdefghijklmnopqrstuvwxyz");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	else if (atoi(argv[1]) == 12)
	{
		strcpy(str, "ABCDEFGHIJ");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	free(str);
	return (0);
}
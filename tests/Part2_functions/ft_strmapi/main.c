 /*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:34:20 by jtoty             #+#    #+#             */
/*   Updated: 2026/05/19 21:07:42  

 /*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:34:20 by jtoty             #+#    #+#             */
/*   Updated: 2026/05/19 21:07:00  

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

char	mapi(unsigned int i, char c)
{
	static int	index_array[27] = {0};

	if (i > 26 || index_array[i] == 1)
		write(1, "wrong index\n", 12);
	else
		index_array[i] = 1;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	main(int argc, const char *argv[])
{
	char	*str;
	char	*strmapi;
	int		arg;

	alarm(5);
	str = (char *)malloc(sizeof(*str) * 32);
	if (argc == 1 || !str)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
	{
		strcpy(str, "LoReM iPsUm");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[11] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	else if (arg == 2)
	{
		strcpy(str, "");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[0] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	else if (arg == 3)
	{
		strcpy(str, "a");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[1] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	else if (arg == 4)
	{
		strcpy(str, "Z");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[1] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	else if (arg == 5)
	{
		strcpy(str, "1234!?$");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[7] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	else if (arg == 6)
	{
		strcpy(str, "Ab1");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[3] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	else if (arg == 7)
	{
		strcpy(str, "abcdefghijklmnopqrstuvwxyz");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[26] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	else if (arg == 8)
	{
		strcpy(str, "ABCDEFGHIJ");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[10] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	else if (arg == 9)
	{
		strcpy(str, "   ");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[3] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	else if (arg == 10)
	{
		strcpy(str, "aBcDeFgHiJ");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[10] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	else if (arg == 11)
	{
		strcpy(str, "0123456789");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[10] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	else if (arg == 12)
	{
		strcpy(str, "a");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi[0] != 'A' || strmapi[1] != '\0')
			ft_print_result("\nWrong result for single char");
	}
	else if (arg == 13)
	{
		strcpy(str, "A");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi[0] != 'a' || strmapi[1] != '\0')
			ft_print_result("\nWrong result for single char upper");
	}
	else if (arg == 14)
	{
		strcpy(str, "---");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strcmp(strmapi, "---") != 0)
			ft_print_result("\nSpecial chars should not change");
	}
	else if (arg == 15)
	{
		strcpy(str, "Hello World!");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[12] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	return (0);
}